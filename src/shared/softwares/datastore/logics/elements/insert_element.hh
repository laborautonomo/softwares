<?hh

function insertElement(Map<string, string> $params = null, Map<string, \Closure> $subLogics = null) {

    if (!isset($params['host'])) {
        throw new \Exception('The host param is mandatory in order to retrieve a container.');
    }

    if (!isset($params['port'])) {
        throw new \Exception('The port param is mandatory in order to retrieve a container.');
    }

    if (!isset($params['software_name'])) {
        throw new \Exception('The software_name param is mandatory in order to retrieve a container.');
    }

    if (!isset($params['container_name'])) {
        throw new \Exception('The container_name param is mandatory in order to retrieve a container.');
    }

    if (!isset($params['data'])) {
        throw new \Exception('The data param is mandatory in order to retrieve a container.');
    }

    if (!isset($subLogics['execute'])) {
        throw new \Exception('The execute subLogic is mandatory in order to retrieve a container.');
    }

    $params['uri'] = '/'.$params['software_name'].'/'.$params['container_name'];
    $params['http_method'] = 'post';
    unset($params['software_name']);
    unset($params['container_name']);

    $output = $subLogics['execute']($params);

    if ($output['http_code'] != 200) {
        throw new \Exception($output['content'], $output['http_code']);
    }
}
