<?hh
include_once('src/tests/helpers/container_data.hh');
include_once('src/tests/helpers/random_data.hh');
include_once('src/tests/helpers/crud.hh');

final class validatorsTest extends \PHPUnit_Framework_TestCase {
    private $softwareNameInDatastore;
    private $newSoftwareConfigUrl;
    private $datastoreConfigUrl;
    private $containerData;
    private $preAdditionalData;
    private $postAdditionalContainerData;
    public function setUp() {

        $languageData = getLanguageData(0);
        $functionData = getFunctionData($languageData, 0);
        $viewData = getViewsData($functionData, 0);
        $renderedParserData = getRenderedParserData($functionData, 0);

        $oneSubValidator = getValidatorsData($functionData, 0);

        $this->baseRoute = '/';
        $this->softwareNameInDatastore = 'apis_irestful';
        $this->newSoftwareConfigUrl = 'http://code.irestful.com/configs/softwares/apis/validators.json';
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
            ),
            'http://code.irestful.com/configs/softwares/apis/views.json' => array(
                'base_route' => '/',
                'container_data' => getViewsContainerData(),
                'data' => $viewData
            ),
            'http://code.irestful.com/configs/softwares/apis/rendered_parser.json' => array(
                'base_route' => '/',
                'container_data' => getRenderedParserContainerData(),
                'data' => $renderedParserData
            )
        );
        $this->containerData = getValidatorsContainerData();
        $this->data = array(
            'first' => getValidatorsData($functionData, 0, $viewData, $renderedParserData, array($oneSubValidator)),
            'second' => getValidatorsData($functionData, 1, $viewData, $renderedParserData, array($oneSubValidator))
        );

        $this->preAdditionalData = array(
            $oneSubValidator
        );

        $this->postAdditionalContainerData = array(
            getSubValidatorsContainerData()
        );
    }

    public function tearDown() {

    }

    public function testSingle_Success() {
        crud($this, $this->baseRoute, $this->dependencies, $this->softwareNameInDatastore, $this->newSoftwareConfigUrl, $this->containerData, $this->data, $this->preAdditionalData, $this->postAdditionalContainerData, array('sub_validators'));
    }

}
