<?hh

function insertMiddleElements(Map<string, string> $params = null, Map<string, \Closure> $subLogics = null) {

    if (!isset($params['foreign_keys'])) {
        throw new \Exception('The foreign_keys param is mandatory in order to insert middle elements.', 500);
    }

    if (!isset($params['data'])) {
        throw new \Exception('The data param is mandatory in order to insert middle elements.', 500);
    }

    if (!isset($subLogics['insert_element'])) {
        throw new \Exception('The insert_element subLogic is mandatory in order to insert middle elements.', 500);
    }

    if (!isset($subLogics['generate_uuid'])) {
        throw new \Exception('The generate_uuid subLogic is mandatory in order to insert middle elements.', 500);
    }

    //if we have middle elements, build up the params:
    $middleElementParams = Vector<Map<string, mixed>> {};
    if (isset($params['foreign_keys'])) {
        foreach($params['foreign_keys'] as $fieldName => $oneForeignKey) {

            if (!isset($oneForeignKey['parent_field'])) {
                throw new \Exception('The parent_field is mandatory inside the foreign_key elements.  It is missin inside the '.$fieldName.' foreign key.', 500);
            }

            if (!isset($oneForeignKey['middle_container'])) {
                throw new \Exception('The middle_container is mandatory inside the foreign_key elements.  It is missin inside the '.$fieldName.' foreign key.', 500);
            }

            $parentField = $oneForeignKey['parent_field'];
            if (!isset($params['data'][$parentField])) {
                throw new \Exception('The parent_field ('.$parentField.') is not a valid key inside the data.', 500);
            }

            if (!isset($params['data'][$fieldName])) {
                continue;
            }

            foreach($params['data'][$fieldName] as $oneChildElement) {
                $middleElementParams[] = Map<string, mixed> {
                    'software_name' => $params['software_name'],
                    'container_name' => $oneForeignKey['middle_container'],
                    'data' => Map<string, string> {
                        'uuid' => $subLogics['generate_uuid'](),
                        'parent' => $params['data'][$parentField],
                        'child' => $oneChildElement,
                        'created_on' => time()
                    }
                };
            }

            unset($params['data'][$fieldName]);
        }

        unset($params['foreign_keys']);
    }

    //first insert the parent:
    $subLogics['insert_element']($params);

    //insert the middle elements, if any:
    if (!empty($middleElementParams)) {
        foreach($middleElementParams as $oneMiddleParam) {
            $subLogics['insert_element']($oneMiddleParam);
        }
    }
}
