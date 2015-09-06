<?hh
include_once('src/tests/helpers/curl/execute.hh');
include_once('src/tests/helpers/software.hh');
include_once('src/tests/helpers/datastore.hh');

function crud(\PHPUnit_Framework_TestCase $phpunit, string $baseRoute, string $newSoftwareNameInDatastore, string $newSoftwareConfigUrl, string $datastoreConfigUrl, array $containerData, array $firstData, $secondData) {

    $newSoftwareJson = file_get_contents($newSoftwareConfigUrl);
    $newSoftwareData = json_decode($newSoftwareJson, true);
    $subDomain = $newSoftwareData['name'];

    $execute = function(string $httpMethod, string $uri, array $data = null) use($subDomain) {
        return executeCurlRequest('http://'.$subDomain.'.softwares.irestful.com', $httpMethod, $uri, $data);
    };

    $insert_Success = function(array $data) use($baseRoute, $execute) {
        $output = $execute('post', $baseRoute, $data);

        if ($output['http_code'] != 200) {
            throw new \Exception('There was a problem while inserting an element in the datastore.  Route: '.$baseRoute.', Http Method: post, Input: '.print_r($data, true).' -->  Output: '.print_r($output, true));
        }
    };

    $retrieve_Success = function(string $uuid) use($baseRoute, $execute) {
        $uri = $baseRoute.$uuid;
        $output = $execute('get', $uri);
        $retrievedData = json_decode($output['content'], true);

        if ($output['http_code'] != 200) {
            throw new \Exception('There was a problem while retrieving an element in the datastore.  Route: '.$uri.', Http Method: get --> Output: '.print_r($output, true));
        }

        return $retrievedData;
    };

    $delete_Success = function(string $uuid) use($baseRoute, $execute) {
        $uri = $baseRoute.$uuid;
        $output = $execute('delete', $uri);

        if ($output['http_code'] != 200) {
            throw new \Exception('There was a problem while deleting an element from the datastore.  Route: '.$uri.', Http Method: delete --> Output: '.print_r($output, true));
        }
    };

    //save both our application config files:
    saveNewSoftware($datastoreConfigUrl);
    saveNewSoftware($newSoftwareConfigUrl);

    //create the software and container:
    insertSoftwareInDatastore($newSoftwareNameInDatastore);
    insertContainerInDatastore($newSoftwareNameInDatastore, $containerData);

    //interact:
    $insert_Success($firstData);
    $retrievedFirstData = $retrieve_Success($firstData['uuid'], $firstData);
    $phpunit->assertEquals($firstData, $retrievedFirstData);

    $delete_Success($firstData['uuid']);

    deleteContainerFromDatastore($newSoftwareNameInDatastore, $containerData['name']);
    deleteSoftwareFromDatastore($newSoftwareNameInDatastore);

}
