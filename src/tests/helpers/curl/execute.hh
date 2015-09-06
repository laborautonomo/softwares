<?hh

function executeCurlRequest(string $host, string $httpMethod, string $uri, array $data = null) {

    include_once('src/shared/logics/curl/execute.hh');

    $params = Map<string, string> {
        'host' => $host,
        'port' => 80,
        'uri' => $uri,
        'http_method' => $httpMethod
    };

    if (!empty($data)) {
        $params['data'] = $data;
    }

    return execute($params);

}
