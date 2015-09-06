<?hh
include_once('src/tests/helpers/curl/execute.hh');

function insertSoftwareInDatastore(string $name) {

    $host = 'http://apis-datastore.softwares.irestful.com';
    $data = array('software_name' => $name);
    $output = executeCurlRequest($host, 'post', '/', $data);

    if ($output['http_code'] != 200) {
        throw new \Exception('There was a problem while inserting a new software ('.$name.') in the datastore.  Output: '.print_r($output, true));
    }
};

function insertContainerInDatastore(string $software, array $containerData) {

    $host = 'http://apis-datastore.softwares.irestful.com';
    $uri = '/'.$software;

    $output = executeCurlRequest($host, 'post', $uri, $containerData);

    if ($output['http_code'] != 200) {
        throw new \Exception('There was a problem while inserting a new container ('.$containerData['name'].'), in the software ('.$software.') in the datastore.  Output: '.print_r($output, true));
    }
};

function deleteSoftwareFromDatastore(string $name) {

    $host = 'http://apis-datastore.softwares.irestful.com';
    $uri = '/'.$name;
    $output = executeCurlRequest($host, 'delete', $uri);

    if ($output['http_code'] != 200) {
        throw new \Exception('There was a problem while deleting a software ('.$name.') from the datastore.  Output: '.print_r($output, true));
    }
};

function deleteContainerFromDatastore(string $software, string $container) {

    $host = 'http://apis-datastore.softwares.irestful.com';
    $uri = '/'.$software.'/'.$container;
    $output = executeCurlRequest($host, 'delete', $uri);

    if ($output['http_code'] != 200) {
        throw new \Exception('There was a problem while deleting a container ('.$container.'), from the software ('.$software.') from the datastore.  Output: '.print_r($output, true));
    }

}
