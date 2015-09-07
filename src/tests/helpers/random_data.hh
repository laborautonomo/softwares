<?hh
include_once('src/shared/logics/uuid.hh');

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
