<?hh
include_once('src/tests/helpers/container_data.hh');
include_once('src/tests/helpers/random_data.hh');
include_once('src/tests/helpers/crud.hh');

final class restAPIsTest extends \PHPUnit_Framework_TestCase {
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
        $validatorsData = getValidatorsData($functionData, 0);
        $paramsData = getParamsData('my->variable', '->');
        $logicData = getLogicsData($functionData, 0);

        $subRestAPI = getRESTAPIsData($functionData, 0);

        $this->baseRoute = '/';
        $this->softwareNameInDatastore = 'apis_irestful';
        $this->newSoftwareConfigUrl = 'http://code.irestful.com/configs/softwares/apis/restapis.json';
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
            ),
            'http://code.irestful.com/configs/softwares/apis/validators.json' => array(
                'base_route' => '/',
                'container_data' => getValidatorsContainerData(),
                'data' => $validatorsData
            ),
            'http://code.irestful.com/configs/softwares/apis/params.json' => array(
                'base_route' => '/',
                'container_data' => getParamsContainerData(),
                'data' => $paramsData
            ),
            'http://code.irestful.com/configs/softwares/apis/logics.json' => array(
                'base_route' => '/',
                'container_data' => getLogicsContainerData(),
                'data' => $logicData
            )
        );

        $this->containerData = getRestAPIsContainerData();
        $this->data = array(
            'first' => getRESTAPIsData($functionData, 0, $subRestAPI, $subRestAPI, $viewData, $renderedParserData, array($paramsData), array($subRestAPI), array($logicData)),
            'second' => getRESTAPIsData($functionData, 1, $subRestAPI, $subRestAPI, $viewData, $renderedParserData, array($paramsData), array($subRestAPI), array($logicData))
        );

        $this->preAdditionalData = array(
            $subRestAPI
        );

        $this->postAdditionalContainerData = array(
            getRestAPIsParams(),
            getRestAPIsSubLogics(),
            getRestAPIsSubRestAPIs()
        );
    }

    public function tearDown() {

    }

    public function testSingle_Success() {
        crud($this, $this->baseRoute, $this->dependencies, $this->softwareNameInDatastore, $this->newSoftwareConfigUrl, $this->containerData, $this->data, $this->preAdditionalData, $this->postAdditionalContainerData, array('sub_rest_apis', 'sub_logics', 'params'));
    }

}
