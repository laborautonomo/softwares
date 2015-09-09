<?hh
include_once('src/tests/helpers/curl/execute.hh');
include_once('src/tests/helpers/software.hh');
include_once('src/tests/helpers/datastore.hh');

function crudExecute(string $subDomain, string $httpMethod, string $uri, array $data = null) {
    return executeCurlRequest('http://'.$subDomain.'.softwares.irestful.com', $httpMethod, $uri, $data);
}

function getSubdomainNameFromSoftwareConfigUrl(string $softwareConfigUrl) {
    $softwareJson = file_get_contents($softwareConfigUrl);
    $softwareData = json_decode($softwareJson, true);
    return $softwareData['name'];
}

function crudInsert(string $subDomain, string $uri, array $data) {
    $output = crudExecute($subDomain, 'post', $uri, $data);
    if ($output['http_code'] != 200) {
        throw new \Exception('There was a problem while inserting an element in the datastore.  Route: '.$uri.', Http Method: post, Input: '.print_r($data, true).' -->  Output: '.print_r($output, true));
    }
}

function crudDelete($subDomain, $baseRoute, string $uuid) {
    $uri = $baseRoute.$uuid;
    $output = crudExecute($subDomain, 'delete', $uri);

    if ($output['http_code'] != 200) {
        throw new \Exception('There was a problem while deleting an element from the datastore.  Route: '.$uri.', Http Method: delete --> Output: '.print_r($output, true));
    }
}

function interact(\PHPUnit_Framework_TestCase $phpunit, string $baseRoute, string $subDomain, array $data, array $removeKeysInDataBeforeComparing = null) {

    $retrieve_Success = function(string $uuid) use($baseRoute, $subDomain) {
        $uri = $baseRoute.$uuid;
        $output = crudExecute($subDomain, 'get', $uri);

        $retrievedData = json_decode($output['content'], true);
        if ($output['http_code'] != 200) {
            throw new \Exception('There was a problem while retrieving an element in the datastore.  Route: '.$uri.', Http Method: get --> Output: '.print_r($output, true));
        }

        return $retrievedData;
    };

    crudInsert($subDomain, $baseRoute, $data['first']);
    $retrievedFirstData = $retrieve_Success($data['first']['uuid'], $data['first']);

    if (!empty($removeKeysInDataBeforeComparing)) {
        foreach($removeKeysInDataBeforeComparing as $oneKeyToRemove) {
            unset($data['first'][$oneKeyToRemove]);
        }
    }

    $phpunit->assertEquals($data['first'], $retrievedFirstData);
    crudDelete($subDomain, $baseRoute, $data['first']['uuid']);

}

function crud(\PHPUnit_Framework_TestCase $phpunit, string $baseRoute, array $dependencies, string $softwareNameInDatastore, string $softwareConfigUrl, array $containerData, array $data, array $preAdditionalData = null, array $postAdditionalContainerData = null, array $removeKeysInDataBeforeComparing = null) {

    //create the dependency softwares:
    $subDomains = array();
    $configUrls = array_keys($dependencies);
    foreach($configUrls as $oneConfigUrl) {
        $subDomains[$oneConfigUrl] = getSubdomainNameFromSoftwareConfigUrl($oneConfigUrl);
        saveNewSoftware($oneConfigUrl);
    }

    //discover the software subdomain:
    $softwareJson = file_get_contents($softwareConfigUrl);
    $softwareData = json_decode($softwareJson, true);

    //create the software, in our datastore:
    insertSoftwareInDatastore($softwareNameInDatastore);

    //insert our dependencies container (in datastore) & data:
    foreach($dependencies as $oneConfigUrl => $oneDependencyData) {

        if (empty($oneDependencyData)) {
            continue;
        }

        insertContainerInDatastore($softwareNameInDatastore, $oneDependencyData['container_data']);
        crudInsert($subDomains[$oneConfigUrl], $oneDependencyData['base_route'], $oneDependencyData['data']);
    }

    //save both our application config files:
    saveNewSoftware($softwareConfigUrl);

    //create the software container:
    insertContainerInDatastore($softwareNameInDatastore, $containerData);

    //if we have pre container data, insert it:
    if (!empty($postAdditionalContainerData)) {
        foreach($postAdditionalContainerData as $oneContainerData) {
            insertContainerInDatastore($softwareNameInDatastore, $oneContainerData);
        }
    }

    //if we have pre data, insert it:
    if (!empty($preAdditionalData)) {
        foreach($preAdditionalData as $oneData) {
            crudInsert($softwareData['name'], $baseRoute, $oneData);
        }
    }

    //interact with functions:
    interact($phpunit, $baseRoute, $softwareData['name'], $data, $removeKeysInDataBeforeComparing);

    //if we have pre data, delete it:
    if (!empty($preAdditionalData)) {
        foreach($preAdditionalData as $oneData) {
            crudDelete($softwareData['name'], $baseRoute, $oneData['uuid']);
        }
    }

    //if we have pre container data, delete it:
    if (!empty($postAdditionalContainerData)) {
        foreach($postAdditionalContainerData as $oneContainerData) {
            deleteContainerFromDatastore($softwareNameInDatastore, $oneContainerData['name']);
        }
    }

    //delete container:
    deleteContainerFromDatastore($softwareNameInDatastore, $containerData['name']);

    //delete dependencies container:
    $reversedDependencies = array_reverse($dependencies);
    foreach($reversedDependencies as $oneConfigUrl => $oneDependencyData) {

        if (empty($oneDependencyData)) {
            continue;
        }

        crudDelete($subDomains[$oneConfigUrl], $oneDependencyData['base_route'], $oneDependencyData['data']['uuid']);
        deleteContainerFromDatastore($softwareNameInDatastore, $oneDependencyData['container_data']['name']);
    }

    //delete the software from datastore:
    deleteSoftwareFromDatastore($softwareNameInDatastore);
}
