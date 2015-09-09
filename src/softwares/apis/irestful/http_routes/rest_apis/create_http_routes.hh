<?hh
function createHttpRoutes(Map<string, string> $params = null, Map<string, \Closure> $subLogics = null, Map<string, string> $subAPIs = null) {

    if (!isset($subLogics['insert_element'])) {
        throw new \Exception('The insert_element subLogic is mandatory in order to create a new HTTP Route.');
    }

    if (!isset($params['possible_params'])) {
        throw new \Exception('The possible_params param is mandatory in order to create a new HTTP Route.');
    }

    if (!isset($params['data']['method'])) {
        throw new \Exception('The data->method param is mandatory in order to create a new HTTP Route.');
    }

    if (!isset($params['data']['pattern_prefix'])) {
        throw new \Exception('The data->pattern_prefix param is mandatory in order to create a new HTTP Route.');
    }

    if (!isset($params['data']['pattern_suffix'])) {
        throw new \Exception('The data->pattern_suffix param is mandatory in order to create a new HTTP Route.');
    }

    //make the method lower case, then compare it:
    $params['data']['method'] = strtolower($params['data']['method']);
    if (!in_array($params['data']['method'], $params['possible_params'])) {
        throw new \Exception('The given HTTP method is invalid.  It must be one of these: '.implode(',', $params['possible_params']));
    }

    if (strlen($params['data']['pattern_prefix']) != 1) {
        throw new \Exception('The pattern prefix must be 1 character long.');
    }

    if (strlen($params['data']['pattern_suffix']) != 1) {
        throw new \Exception('The pattern suffix must be 1 character long.');
    }

    //we inset the params:
    $subLogics['insert_element']($params);
};
