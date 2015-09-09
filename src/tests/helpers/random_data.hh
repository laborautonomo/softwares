<?hh
include_once('src/shared/logics/uuid.hh');

function getRouteData($index, array $cliRoute = null, array $httpRoute = null) {

    if ($index % 2) {

        $data = array(
            'uuid' => generateUuid(),
            'cli_route' => null,
            'http_route' => null,
            'title' => 'This is the first route.',
            'description' => 'Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
            'created_on' => time()
        );

        if (!empty($cliRoute)) {
            $data['cli_route'] = $cliRoute['uuid'];
        }

        if (!empty($httpRoute)) {
            $data['http_route'] = $httpRoute['uuid'];
        }

        return $data;

    }

    $data = array(
        'uuid' => generateUuid(),
        'cli_route' => null,
        'http_route' => null,
        'title' => 'This is the second route.',
        'description' => 'Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
        'created_on' => time()
    );

    if (!empty($cliRoute)) {
        $data['cli_route'] = $cliRoute['uuid'];
    }

    if (!empty($httpRoute)) {
        $data['http_route'] = $httpRoute['uuid'];
    }

    return $data;
}

function getHttpRouteData(array $restAPIData, $index) {

    if ($index % 2) {

        return array(
            'uuid' => generateUuid(),
            'method' => 'get',
            'pattern' => 'this is a pattern',
            'pattern_prefix' => '*',
            'pattern_suffix' => '*',
            'rest_api' => $restAPIData['uuid'],
            'title' => 'This is the first http route.',
            'description' => 'Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
            'created_on' => time()
        );

    }

    return array(
        'uuid' => generateUuid(),
        'method' => 'post',
        'pattern' => 'this is a second pattern',
        'pattern_prefix' => '+',
        'pattern_suffix' => '+',
        'rest_api' => $restAPIData['uuid'],
        'title' => 'This is the second http route.',
        'description' => 'Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
        'created_on' => time()
    );
}

function getCliRouteData(array $restAPIData, $index) {

    if ($index % 2) {

        return array(
            'uuid' => generateUuid(),
            'optional_params' => 'first,second,third',
            'mandatory_params' => 'another,yes',
            'rest_api' => $restAPIData['uuid'],
            'title' => 'This is the first cli route.',
            'description' => 'Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
            'created_on' => time()
        );

    }

    return array(
        'uuid' => generateUuid(),
        'optional_params' => 'first,second,third',
        'mandatory_params' => 'another,yes',
        'rest_api' => $restAPIData['uuid'],
        'title' => 'This is the second cli route.',
        'description' => 'Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
        'created_on' => time()
    );
}

function getRESTAPIsData(array $functionsData, $index, array $successAPI = null, array $failureAPI = null, array $view = null, array $renderedParser = null, array $params = null, array $subRestAPIs = null, array $subLogics = null) {

    $paramUuids = array();
    if (!empty($params)) {

        foreach($params as $oneParam) {
            $paramUuids[] = $oneParam['uuid'];
        }

    }

    $subRestAPIsUuids = array();
    if (!empty($subRestAPIs)) {

        foreach($subRestAPIs as $oneSubRestAPI) {
            $subRestAPIsUuids[] = $oneSubRestAPI['uuid'];
        }

    }

    $subLogicUuids = array();
    if (!empty($subLogics)) {

        foreach($subLogics as $oneSubLogic) {
            $subLogicUuids[] = $oneSubLogic['uuid'];
        }

    }

    if ($index % 2) {

        $data = array(
            'uuid' => generateUuid(),
            'function' => $functionsData['uuid'],
            'title' => 'This is the REST API title',
            'description' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
            'created_on' => time()
        );

        if (!empty($view)) {
            $data['view'] = $view['uuid'];
        }

        if (!empty($renderedParser)) {
            $data['rendered_parser'] = $renderedParser['uuid'];
        }

        if (!empty($successAPI)) {
            $data['success_api_rest_api'] = $successAPI['uuid'];
        }

        if (!empty($failureAPI)) {
            $data['failure_api_rest_api'] = $failureAPI['uuid'];
        }

        if (!empty($subRestAPIs)) {
            $data['sub_rest_apis'] = $subRestAPIs;
        }

        if (!empty($paramUuids)) {
            $data['params'] = $paramUuids;
        }

        if (!empty($subLogicUuids)) {
            $data['sub_logics'] = $subLogicUuids;
        }

        return $data;

    }

    $data = array(
        'uuid' => generateUuid(),
        'function' => $functionsData['uuid'],
        'title' => 'This is the second REST API title',
        'description' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
        'created_on' => time()
    );

    if (!empty($view)) {
        $data['view'] = $view['uuid'];
    }

    if (!empty($renderedParser)) {
        $data['rendered_parser'] = $renderedParser['uuid'];
    }

    if (!empty($successAPI)) {
        $data['success_api_rest_api'] = $successAPI['uuid'];
    }

    if (!empty($failureAPI)) {
        $data['failure_api_rest_api'] = $failureAPI['uuid'];
    }

    if (!empty($paramUuids)) {
        $data['sub_rest_apis'] = $subRestAPIsUuids;
    }

    if (!empty($paramUuids)) {
        $data['params'] = $paramUuids;
    }

    if (!empty($subLogicUuids)) {
        $data['sub_logics'] = $subLogicUuids;
    }

    return $data;


}

function getLogicsData(array $functionsData, $index, array $params = null, array $subLogics = null) {

    $paramUuids = array();
    if (!empty($params)) {

        foreach($params as $oneParam) {
            $paramUuids[] = $oneParam['uuid'];
        }

    }

    $subLogicUuids = array();
    if (!empty($subLogics)) {

        foreach($subLogics as $oneSubLogic) {
            $subLogicUuids[] = $oneSubLogic['uuid'];
        }

    }

    if ($index % 2) {

        $data = array(
            'uuid' => generateUuid(),
            'function' => $functionsData['uuid'],
            'title' => 'This is the logic title',
            'description' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
            'created_on' => time()
        );

        if (!empty($paramUuids)) {
            $data['params'] = $paramUuids;
        }

        if (!empty($subLogicUuids)) {
            $data['sub_logics'] = $subLogicUuids;
        }

        return $data;

    }

    $data = array(
        'uuid' => generateUuid(),
        'function' => $functionsData['uuid'],
        'title' => 'This is the second logic title',
        'description' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
        'created_on' => time()
    );

    if (!empty($paramUuids)) {
        $data['params'] = $paramUuids;
    }

    if (!empty($subLogicUuids)) {
        $data['sub_logics'] = $subLogicUuids;
    }

    return $data;


}

function getValidatorsData(array $functionsData, $index, array $view = null, array $renderedParser = null, array $subValidators = null) {

    $subValidatorUuids = array();
    if (!empty($subValidators)) {

        foreach($subValidators as $oneValidator) {
            $subValidatorUuids[] = $oneValidator['uuid'];
        }

    }

    if ($index % 2) {

        $data = array(
            'uuid' => generateUuid(),
            'function' => $functionsData['uuid'],
            'title' => 'This is the validator title',
            'description' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
            'created_on' => time()
        );

        if (!empty($view)) {
            $data['view'] = $view['uuid'];
        }

        if (!empty($renderedParser)) {
            $data['rendered_parser'] = $renderedParser['uuid'];
        }

        if (!empty($subViewUuids)) {
            $data['sub_validators'] = $subValidatorUuids;
        }

        return $data;

    }

    $data = array(
        'uuid' => generateUuid(),
        'function' => $functionsData['uuid'],
        'title' => 'This is the second validator title',
        'description' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
        'created_on' => time()
    );

    if (!empty($view)) {
        $data['view'] = $view['uuid'];
    }

    if (!empty($renderedParser)) {
        $data['rendered_parser'] = $renderedParser['uuid'];
    }

    if (!empty($subViewUuids)) {
        $data['sub_validators'] = $subValidatorUuids;
    }

    return $data;


}

function getSubViewsData(array $parentView, array $childView, $index) {

    if ($index % 2) {

        return array(
            'uuid' => generateUuid(),
            'parent' => $parentView['uuid'],
            'child' => $childView['uuid'],
            'created_on' => time()
        );

    }

    return array(
        'uuid' => generateUuid(),
        'parent' => $parentView['uuid'],
        'child' => $childView['uuid'],
        'created_on' => time()
    );

}

function getViewsData(array $functionsData, $index, array $view = null, array $subViews = null) {

    $subViewUuids = array();
    if (!empty($subViews)) {

        foreach($subViews as $oneView) {
            $subViewUuids[] = $oneView['uuid'];
        }

    }

    if ($index % 2) {

        $data = array(
            'uuid' => generateUuid(),
            'function' => $functionsData['uuid'],
            'title' => 'This is the view title',
            'description' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
            'created_on' => time()
        );

        if (!empty($view)) {
            $data['view'] = $view['uuid'];
        }

        if (!empty($subViewUuids)) {
            $data['sub_views'] = $subViewUuids;
        }

        return $data;

    }

    $data = array(
        'uuid' => generateUuid(),
        'function' => $functionsData['uuid'],
        'title' => 'This is the second view title',
        'description' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
        'created_on' => time()
    );

    if (!empty($view)) {
        $data['view'] = $view['uuid'];
    }

    if (!empty($subViewUuids)) {
        $data['sub_views'] = $subViewUuids;
    }

    return $data;


}


function getParamsData($variableName = null, $variableDelimiter = null, $value = null, array $renderedParser = null, array $validator = null) {

    $data = array(
        'uuid' => generateUuid(),
        'variable_name' => null,
        'variable_delimiter' => null,
        'value' => null,
        'rendered_parser' => null,
        'validator' => null,
        'created_on' => time()
    );

    if (!empty($variableName)) {
        $data['variable_name'] = $variableName;
    }

    if (!empty($variableDelimiter)) {
        $data['variable_delimiter'] = $variableDelimiter;
    }

    if (!empty($value)) {
        $data['value'] = $value;
    }

    if (!empty($renderedParser)) {
        $data['rendered_parser'] = $renderedParser;
    }

    if (!empty($validator)) {
        $data['validator'] = $validator;
    }

    return $data;

}

function getRenderedParserData(array $functionsData, $index) {

    if ($index % 2) {

        return array(
            'uuid' => generateUuid(),
            'function' => $functionsData['uuid'],
            'title' => 'This is the function title',
            'description' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
            'created_on' => time()
        );

    }

    return array(
        'uuid' => generateUuid(),
        'function' => $functionsData['uuid'],
        'title' => 'This is the second function title',
        'description' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
        'created_on' => time()
    );

}

function getSettingsData($index) {

    if ($index % 2) {

        return array(
            'uuid' => generateUuid(),
            'name' => 'my-new-software',
            'title' => 'This is the title',
            'description' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
            'created_on' => time()
        );

    }

    return array(
        'uuid' => generateUuid(),
        'name' => 'second-software',
        'title' => 'This is a second title',
        'description' => 'Just another description!',
        'created_on' => time()
    );

}

function getEnvironmentVariablesData($index) {

    if ($index % 2) {

        return array(
            'uuid' => generateUuid(),
            'keyname' => 'apis_irestful_software_name',
            'variable_name' => 'APIS_IRESTFUL_SOFTWARE_NAME',
            'notes' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
            'created_on' => time()
        );

    }

    return array(
        'uuid' => generateUuid(),
        'keyname' => 'second_apis_irestful_software_name',
        'variable_name' => 'SECOND_APIS_IRESTFUL_SOFTWARE_NAME',
        'notes' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
        'created_on' => time()
    );

}

function getLanguageData($index) {

    if ($index % 2) {

        return array(
            'uuid' => generateUuid(),
            'keyname' => 'langauge_name',
            'host' => 'http://my-language.languages.irestful.com',
            'port' => 80,
            'title' => 'This is the "Language Name" Language Processor.',
            'description' => 'Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
            'created_on' => time()
        );

    }

    return array(
        'uuid' => generateUuid(),
        'keyname' => 'second_langauge_name',
        'host' => 'http://second-language.languages.irestful.com',
        'port' => 80,
        'title' => 'This is the "Second Language Name" Language Processor.',
        'description' => 'Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
        'created_on' => time()
    );
}

function getFunctionData(array $languageData, $index) {

    if ($index % 2) {
        return array(
            'uuid' => generateUuid(),
            'url' => 'http://code.irestful.com/shared/validators/uuid.hh',
            'name' => 'uuid',
            'language' => $languageData['uuid'],
            'title' => 'This is the first title.',
            'description' => 'This is the first random description.',
            'created_on' => time()
        );
    }

    return array(
        'uuid' => generateUuid(),
        'url' => 'http://code.irestful.com/shared/views/json.hh',
        'name' => 'render',
        'language' => $languageData['uuid'],
        'title' => 'This is the second title.',
        'description' => 'This is the second random description.',
        'created_on' => time()
    );

}
