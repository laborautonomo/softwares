<?hh
function getSettingsContainerData($name) {
    return array(
        'name' => $name,
        'fields' => array(
            'uuid' => array(
                'is_primary_key' => true,
                'type' => 'binary',
                'length' => 16,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/shared/validators/uuid.hh',
                        'name' => 'uuid',
                        'language' => 'hack'
                    ),
                    'rendered_parser' => array(
                        'url' => 'http://code.irestful.com/shared/rendered_parsers/uuid.hh',
                        'name' => 'uuid'
                    )
                )
            ),
            'name' => array(
                'type' => 'varchar',
                'is_unique' => true,
                'length' => 255,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/softwares/apis/irestful/settings/validators/name.hh',
                        'name' => 'name',
                        'language' => 'hack'
                    )
                )
            ),
            'title' => array(
                'type' => 'varchar',
                'length' => 255,
                'default' => 'not null'
            ),
            'description' => array(
                'type' => 'text',
                'default' => 'null'
            ),
            'created_on' => array(
                'type' => 'bigint',
                'length' => 11,
                'default' => 'not null'
            ),
            'last_updated_on' => array(
                'type' => 'bigint',
                'length' => 11,
                'default' => 'null'
            )
        )
    );
}

function getEnvironmentVariableContainerData($name) {
    return array(
        'name' => $name,
        'fields' => array(
            'uuid' => array(
                'is_primary_key' => true,
                'type' => 'binary',
                'length' => 16,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/shared/validators/uuid.hh',
                        'name' => 'uuid',
                        'language' => 'hack'
                    ),
                    'rendered_parser' => array(
                        'url' => 'http://code.irestful.com/shared/rendered_parsers/uuid.hh',
                        'name' => 'uuid'
                    )
                )
            ),
            'keyname' => array(
                'type' => 'varchar',
                'is_unique' => true,
                'length' => 255,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/softwares/apis/irestful/shared/validators/keyname.hh',
                        'name' => 'keyname'
                    )
                )
            ),
            'variable_name' => array(
                'type' => 'varchar',
                'length' => 255,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/softwares/apis/irestful/environment_variables/validators/variable_name.hh',
                        'name' => 'variableName'
                    )
                )
            ),
            'notes' => array(
                'type' => 'text',
                'default' => 'null'
            ),
            'created_on' => array(
                'type' => 'bigint',
                'length' => 11,
                'default' => 'not null'
            ),
            'last_updated_on' => array(
                'type' => 'bigint',
                'length' => 11,
                'default' => 'null'
            )
        )
    );
}

function getLanguageContainerData($name) {
    return array(
        'name' => $name,
        'fields' => array(
            'uuid' => array(
                'is_primary_key' => true,
                'type' => 'binary',
                'length' => 16,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/shared/validators/uuid.hh',
                        'name' => 'uuid',
                        'language' => 'hack'
                    ),
                    'rendered_parser' => array(
                        'url' => 'http://code.irestful.com/shared/rendered_parsers/uuid.hh',
                        'name' => 'uuid'
                    )
                )
            ),
            'keyname' => array(
                'type' => 'varchar',
                'is_unique' => true,
                'length' => 255,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/softwares/apis/irestful/shared/validators/keyname.hh',
                        'name' => 'keyname',
                        'language' => 'hack'
                    )
                )
            ),
            'host' => array(
                'type' => 'varchar',
                'length' => 255,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/softwares/apis/irestful/shared/validators/url.hh',
                        'name' => 'url',
                        'language' => 'hack'
                    )
                )
            ),
            'port' => array(
                'type' => 'int',
                'length' => 11,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/shared/validators/integer.hh',
                        'name' => 'integer',
                        'language' => 'hack'
                    )
                )
            ),
            'title' => array(
                'type' => 'varchar',
                'length' => 255,
                'default' => 'not null'
            ),
            'description' => array(
                'type' => 'text',
                'default' => 'not null'
            ),
            'created_on' => array(
                'type' => 'bigint',
                'length' => 11,
                'default' => 'not null'
            ),
            'last_updated_on' => array(
                'type' => 'bigint',
                'length' => 11,
                'default' => 'null'
            )
        )
    );
}

function getFunctionsContainerData($name) {
    return array(
        'name' => $name,
        'fields' => array(
            'uuid' => array(
                'is_primary_key' => true,
                'type' => 'binary',
                'length' => 16,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/shared/validators/uuid.hh',
                        'name' => 'uuid',
                        'language' => 'hack'
                    ),
                    'rendered_parser' => array(
                        'url' => 'http://code.irestful.com/shared/rendered_parsers/uuid.hh',
                        'name' => 'uuid'
                    )
                )
            ),
            'url' => array(
                'type' => 'varchar',
                'length' => 255,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/softwares/apis/irestful/shared/validators/url.hh',
                        'name' => 'url',
                        'language' => 'hack'
                    )
                )
            ),
            'name' => array(
                'type' => 'varchar',
                'length' => 255,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/shared/validators/camel_case.hh',
                        'name' => 'camelCase',
                        'language' => 'hack'
                    )
                )
            ),
            'language' => array(
                'foreign_key' => array(
                    'referenced_container' => 'languages',
                    'referenced_field' => 'uuid'
                ),
                'type' => 'binary',
                'length' => 16,
                'default' => 'not null',
                'validator' => array(
                    'language' => array(
                        'name' => 'hack',
                        'host' => 'http://hack.languages.irestful.com',
                        'port' => 80
                    ),
                    'function' => array(
                        'url' => 'http://code.irestful.com/shared/validators/uuid.hh',
                        'name' => 'uuid',
                        'language' => 'hack'
                    ),
                    'rendered_parser' => array(
                        'url' => 'http://code.irestful.com/shared/rendered_parsers/uuid.hh',
                        'name' => 'uuid'
                    )
                )
            ),
            'title' => array(
                'type' => 'varchar',
                'length' => 255,
                'default' => 'not null'
            ),
            'description' => array(
                'type' => 'text',
                'default' => 'not null'
            ),
            'created_on' => array(
                'type' => 'bigint',
                'length' => 11,
                'default' => 'not null'
            ),
            'last_updated_on' => array(
                'type' => 'bigint',
                'length' => 11,
                'default' => 'null'
            )
        )
    );
}
