<?hh
function createRoutes(Map<string, string> $params = null, Map<string, \Closure> $subLogics = null, Map<string, string> $subAPIs = null) {

    if (!isset($subLogics['insert_element'])) {
        throw new \Exception('The insert_element subLogic is mandatory in order to create a new HTTP Route.');
    }

    $amount = ((isset($params['data']['cli_route']) && !empty($params['data']['cli_route'])) ? 1 : 0) + ((isset($params['data']['http_route']) && !empty($params['data']['http_route'])) ? 1 : 0);
    if ($amount != 1) {
        $word = ($amount > 1) ? 'Both' : 'None';
        throw new \Exception('There must be either a cli or an http route.  '.$word.' given.');
    }

    //we inset the params:
    $subLogics['insert_element']($params);
};
