<?hh

function retrieveElementByUuid(Map<string, string> $params = null, Map<string, \Closure> $subLogics = null) {

    if (!isset($subLogics['retrieve_element_by_uuid'])) {
        throw new \Exception('The retrieve_element_by_uuid subLogic is mandatory in order to retrieve an element by uuid.');
    }

    return $subLogics['retrieve_element_by_uuid']($params);
}
