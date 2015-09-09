<?hh

function createParams(Map<string, string> $params = null, Map<string, \Closure> $subLogics = null, Map<string, string> $subAPIs = null) {
    
    $areParamsValid = function() use($params) {

        //input validator
        if (isset($params['data']['variable_name']) && isset($params['data']['variable_delimiter']) && isset($params['data']['validator'])) {
            return true;
        }

        //variable
        if (isset($params['data']['variable_name']) && isset($params['data']['variable_delimiter'])) {
            return true;
        }

        //rendered value
        if (isset($params['data']['value']) && isset($params['data']['rendered_parser'])) {
            return true;
        }

        //value
        if (isset($params['data']['value'])) {
            return true;
        }

        return false;
    };

    if (!isset($subLogics['insert_element'])) {
        throw new \Exception('The insert_element subLogic is mandatory in order to insert params.', 500);
    }

    if (!$areParamsValid()) {
        throw new \Exception('The given params combination are invalid.', 500);
    }

    //we inset the params:
    $subLogics['insert_element']($params);
};
