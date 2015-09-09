<?hh

function insertElement(Map<string, string> $params = null, Map<string, \Closure> $subLogics = null) {

    if (!isset($subLogics['insert_element'])) {
        throw new \Exception('The insert_element subLogic is mandatory in order to insert an element.');
    }

    return $subLogics['insert_element']($params);
}
