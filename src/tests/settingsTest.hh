<?hh
include_once('src/shared/logics/uuid.hh');
include_once('src/tests/helpers/crud.hh');

final class settingsTest extends \PHPUnit_Framework_TestCase {

    private $softwareNameInDatastore;
    private $newSoftwareConfigUrl;
    private $datastoreConfigUrl;
    private $containerData;
    private $firstData;
    private $secondData;
    public function setUp() {

        $this->softwareNameInDatastore = 'apis_irestful';
        $this->newSoftwareConfigUrl = 'http://code.irestful.com/configs/softwares/apis/settings.json';
        $this->datastoreConfigUrl = 'http://code.irestful.com/configs/softwares/apis/datastore.json';
        $this->containerData = $this->getContainerData();
        $this->firstData = $this->getFirstData();
        $this->secondData = $this->getSecondData();
    }

    public function tearDown() {

    }

    private function getContainerData() {
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
                            'url' => 'http://code.irestful.com/softwares/settings/apis/validators/name.hh',
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

    private function getFirstData() {

        return array(
            'uuid' => generateUuid(),
            'name' => 'my-new-software',
            'title' => 'This is the title',
            'description' => ' Pellentesque elit massa, vehicula eget nisi sed, aliquam tempus magna. In quis blandit ipsum. Integer tempor eros sapien, laoreet facilisis est congue et. Ut vestibulum vehicula nisl vitae tincidunt. Sed aliquet arcu eu augue laoreet vulputate. Nullam tincidunt, purus et laoreet fringilla, felis turpis condimentum nulla, a finibus ipsum mauris at ex. Morbi consectetur sem tortor, ut tincidunt sem volutpat in. ',
            'created_on' => time()
        );

    }

    private function getSecondData() {

        return array(
            'uuid' => generateUuid(),
            'name' => 'second-software',
            'title' => 'This is a second title',
            'description' => 'Just another description!',
            'created_on' => time()
        );

    }

    public function testSingle_Success() {

        $baseRoute = '/';

        crud(
            $this,
            $baseRoute,
            $this->softwareNameInDatastore,
            $this->newSoftwareConfigUrl,
            $this->datastoreConfigUrl,
            $this->containerData,
            $this->firstData,
            $this->secondData
        );
    }

}
