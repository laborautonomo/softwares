<?hh

function validator(Map<string, string> $params = null, Map<string, \Closure> $subLogics = null) {

    if (!isset($subLogics['curl_execute'])) {
        throw new \Exception('The curl_execute subLogic is mandatory in order to execute the validator.', 500);
    }

    if (!isset($params['validators'])) {
        throw new \Exception('The validators param is mandatory in order to execute the validator.', 500);
    }

    if (!isset($params['cache_path'])) {
        throw new \Exception('The cache_path param is mandatory in order to execute the validator.', 500);
    }

    $renderedParsers = Map<string, mixed> {};
    $queries = Map<string, Map<string, mixed>> {};
    foreach($params['validators'] as $keyname => $oneValidator) {

        if (!isset($oneValidator['validator']['language']['host'])) {
            throw new \Exception('The validators[i]->validator->language->host param is mandatory in order to execute the validator.', 500);
        }

        if (!isset($oneValidator['validator']['language']['port'])) {
            throw new \Exception('The validators[i]->validator->language->port param is mandatory in order to execute the validator.', 500);
        }

        if (!isset($oneValidator['validator']['function']['name'])) {
            throw new \Exception('The validators[i]->validator->function->name param is mandatory in order to execute the validator.', 500);
        }

        if (!isset($oneValidator['validator']['function']['url'])) {
            throw new \Exception('The validators[i]->validator->function->url param is mandatory in order to execute the validator.', 500);
        }

        if (isset($oneValidator['validator']['rendered_parser']['url']) && isset($oneValidator['validator']['rendered_parser']['name'])) {
            $renderedParsers[$keyname] = Map<string, string> {
                'url' => $oneValidator['validator']['rendered_parser']['url'],
                'name' => $oneValidator['validator']['rendered_parser']['name'],
                'validator_url' => $oneValidator['validator']['function']['url']
            };
        }

        if (!isset($oneValidator['value'])) {
            throw new \Exception('The validators[i]->value param is mandatory in order to execute the validator.', 500);
        }

        $code = @file_get_contents($oneValidator['validator']['function']['url']);
        $queries[$keyname] = Map<string, mixed> {
            'port' => (integer) $oneValidator['validator']['language']['port'],
            'http_method' => 'post',
            'host' => $oneValidator['validator']['language']['host'],
            'data' => Map<string, string> {
                'type' => 'input_validator',
                'name' => $oneValidator['validator']['function']['name'],
                'code' => $code,
                'input' => $oneValidator['value']
            }
        };

    }

    $curlParams = Map<string, mixed> {
        'queries' => $queries
    };

    $output = $subLogics['curl_execute']($curlParams);
    if (empty($renderedParsers)) {
        return $output;
    }

    foreach($renderedParsers as $keyname => $oneRenderedParser) {

        $code = @file_get_contents($oneRenderedParser['url']);
        $fileName = md5($code).'.hh';
        $filePath = $params['cache_path'].$fileName;

        file_put_contents($filePath, $code);
        include_once($filePath);
        unlink($filePath);

        if ($output[$keyname]['http_code'] != 200) {
            throw new \Exception('The field ('.$keyname.') was supposed to be parsed using the rendered_parser (url: '.$oneRenderedParser['url'].').  However, its validator (url: '.$oneRenderedParser['validator_url'].') returned an http_code of: '.$output[$keyname]['http_code']);
        }

        $output[$keyname]['content'] = $oneRenderedParser['name']($output[$keyname]['content']);
    }

    return $output;

};
