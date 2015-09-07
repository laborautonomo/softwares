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

function preCrud(string $newSoftwareNameInDatastore, string $newSoftwareConfigUrl, array $containerData) {

    //save both our application config files:
    saveNewSoftware($newSoftwareConfigUrl);

    //create the software container:
    insertContainerInDatastore($newSoftwareNameInDatastore, $containerData);

}

function crud(\PHPUnit_Framework_TestCase $phpunit, string $baseRoute, string $newSoftwareConfigUrl, array $firstData, $secondData) {

    $newSoftwareJson = file_get_contents($newSoftwareConfigUrl);
    $newSoftwareData = json_decode($newSoftwareJson, true);
    $subDomain = $newSoftwareData['name'];

    $retrieve_Success = function(string $uuid) use($baseRoute, $subDomain) {
        $uri = $baseRoute.$uuid;
        $output = crudExecute($subDomain, 'get', $uri);

        $retrievedData = json_decode($output['content'], true);
        if ($output['http_code'] != 200) {
            throw new \Exception('There was a problem while retrieving an element in the datastore.  Route: '.$uri.', Http Method: get --> Output: '.print_r($output, true));
        }

        return $retrievedData;
    };



    //interact:
    crudInsert($subDomain, $baseRoute, $firstData);
    $retrievedFirstData = $retrieve_Success($firstData['uuid'], $firstData);
    $phpunit->assertEquals($firstData, $retrievedFirstData);

    crudDelete($subDomain, $baseRoute, $firstData['uuid']);

}
