<?hh
function saveNewSoftware($configUrl) {

    $data = array('config_url' => $configUrl);

    $host = 'http://softwares.irestful.com';
    $uri = '/';

    $output = executeCurlRequest($host, 'post', $uri, $data);

    if ($output['http_code'] != 200) {
        throw new \Exception('There was a problem while saving a software in the datastore.  Output: '.print_r($output, true));
    }

}
