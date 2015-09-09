<?hh
function getLogicsParams() {
    return array(
        'name' => 'logics_params',
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
            'parent' => array(
                'foreign_key' => array(
                    'referenced_container' => 'logics',
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
            'child' => array(
                'foreign_key' => array(
                    'referenced_container' => 'params',
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
            'created_on' => array(
                'type' => 'bigint',
                'length' => 11,
                'default' => 'not null'
            )
        )
    );
}

function getSubLogicsContainerData() {
    return array(
        'name' => 'logics_sub_logic',
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
            'parent' => array(
                'foreign_key' => array(
                    'referenced_container' => 'logics',
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
            'child' => array(
                'foreign_key' => array(
                    'referenced_container' => 'logics',
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
            'created_on' => array(
                'type' => 'bigint',
                'length' => 11,
                'default' => 'not null'
            )
        )
    );
}

function getLogicsContainerData() {
    return array(
        'name' => 'logics',
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
            'function' => array(
                'foreign_key' => array(
                    'referenced_container' => 'functions',
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

function getSubValidatorsContainerData() {
    return array(
        'name' => 'validators_sub_validators',
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
            'parent' => array(
                'foreign_key' => array(
                    'referenced_container' => 'validators',
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
            'child' => array(
                'foreign_key' => array(
                    'referenced_container' => 'validators',
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
            'created_on' => array(
                'type' => 'bigint',
                'length' => 11,
                'default' => 'not null'
            )
        )
    );
}

function getValidatorsContainerData() {
    return array(
        'name' => 'validators',
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
            'function' => array(
                'foreign_key' => array(
                    'referenced_container' => 'functions',
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
            'view' => array(
                'foreign_key' => array(
                    'referenced_container' => 'views',
                    'referenced_field' => 'uuid'
                ),
                'type' => 'binary',
                'length' => 16,
                'default' => 'null',
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
            'rendered_parser' => array(
                'foreign_key' => array(
                    'referenced_container' => 'rendered_parsers',
                    'referenced_field' => 'uuid'
                ),
                'type' => 'binary',
                'length' => 16,
                'default' => 'null',
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

function getSubViewsContainerData() {
    return array(
        'name' => 'views_sub_views',
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
            'parent' => array(
                'foreign_key' => array(
                    'referenced_container' => 'views',
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
            'child' => array(
                'foreign_key' => array(
                    'referenced_container' => 'views',
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
            'created_on' => array(
                'type' => 'bigint',
                'length' => 11,
                'default' => 'not null'
            )
        )
    );
}


function getViewsContainerData() {
    return array(
        'name' => 'views',
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
            'function' => array(
                'foreign_key' => array(
                    'referenced_container' => 'functions',
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
            'view' => array(
                'foreign_key' => array(
                    'referenced_container' => 'views',
                    'referenced_field' => 'uuid'
                ),
                'type' => 'binary',
                'length' => 16,
                'default' => 'null',
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

function getParamsContainerData() {
    return array(
        'name' => 'params',
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
            'variable_name' => array(
                'type' => 'varchar',
                'length' => 255,
                'default' => 'null'
            ),
            'variable_delimiter' => array(
                'type' => 'varchar',
                'length' => 255,
                'default' => 'null'
            ),
            'value' => array(
                'type' => 'varchar',
                'length' => 255,
                'default' => 'null'
            ),
            'rendered_parser' => array(
                'foreign_key' => array(
                    'referenced_container' => 'rendered_parsers',
                    'referenced_field' => 'uuid'
                ),
                'type' => 'binary',
                'length' => 16,
                'default' => 'null',
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
            'validator' => array(
                'foreign_key' => array(
                    'referenced_container' => 'validators',
                    'referenced_field' => 'uuid'
                ),
                'type' => 'binary',
                'length' => 16,
                'default' => 'null',
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

function getRenderedParserContainerData() {
    return array(
        'name' => 'rendered_parsers',
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
            'function' => array(
                'foreign_key' => array(
                    'referenced_container' => 'functions',
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

function getSettingsContainerData() {
    return array(
        'name' => 'settings',
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

function getEnvironmentVariableContainerData() {
    return array(
        'name' => 'environment_variables',
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

function getLanguageContainerData() {
    return array(
        'name' => 'languages',
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

function getFunctionsContainerData() {
    return array(
        'name' => 'functions',
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
