<?hh
include_once('src/tests/helpers/container_data.hh');
include_once('src/tests/helpers/random_data.hh');
include_once('src/tests/helpers/crud.hh');

final class renderedParserTest extends \PHPUnit_Framework_TestCase {
    private $softwareNameInDatastore;
    private $newSoftwareConfigUrl;
    private $datastoreConfigUrl;
    private $containerData;
    public function setUp() {

        $languageData = getLanguageData(0);
        $functionData = getFunctionData($languageData, 0);

        $this->baseRoute = '/';
        $this->softwareNameInDatastore = 'apis_irestful';
        $this->newSoftwareConfigUrl = 'http://code.irestful.com/configs/softwares/apis/rendered_parser.json';
        $this->dependencies = array(
            'http://code.irestful.com/configs/softwares/apis/datastore.json' => null,
            'http://code.irestful.com/configs/softwares/apis/languages.json' => array(
                'base_route' => '/',
                'container_data' => getLanguageContainerData(),
                'data' => $languageData
            ),
            'http://code.irestful.com/configs/softwares/apis/functions.json' => array(
                'base_route' => '/',
                'container_data' => getFunctionsContainerData(),
                'data' => $functionData
            )
        );
        $this->containerData = getRenderedParserContainerData();
        $this->data = array(
            'first' => getRenderedParserData($functionData, 0),
            'second' => getRenderedParserData($functionData, 1)
        );
    }

    public function tearDown() {

    }

    public function testSingle_Success() {
        crud($this, $this->baseRoute, $this->dependencies, $this->softwareNameInDatastore, $this->newSoftwareConfigUrl, $this->containerData, $this->data);
    }

}
