<?hh
function createCliRoutes(Map<string, string> $params = null, Map<string, \Closure> $subLogics = null, Map<string, string> $subAPIs = null) {

    if (!isset($subLogics['insert_element'])) {
        throw new \Exception('The insert_element subLogic is mandatory in order to create a new CLI Route.');
    }

    $optionalParams = array();
    if (isset($params['data']['optional_params'])) {
        $optionalParams = explode(',', $params['data']['optional_params']);
    }

    $mandatoryParams = array();
    if (isset($params['data']['mandatory_params'])) {
        $mandatoryParams = explode(',', $params['data']['mandatory_params']);
    }

    foreach($mandatoryParams as $oneParam) {
        if (in_array($oneParam, $optionalParams)) {
            throw new \Exception('The param ('.$oneParam.') is in both optional and mandatory parameters.  Each parameter can only be assigned to one or the other');
        }
    }

    //we inset the params:
    $subLogics['insert_element']($params);
};
