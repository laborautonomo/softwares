<?hh
include_once('src/tests/helpers/container_data.hh');
include_once('src/tests/helpers/random_data.hh');
include_once('src/tests/helpers/crud.hh');

final class httpRoutesTest extends \PHPUnit_Framework_TestCase {
    private $baseRoute;
    private $softwareNameInDatastore;
    private $newSoftwareConfigUrl;
    private $dependencies;
    private $containerData;
    private $data;
    public function setUp() {

        $languageData = getLanguageData(0);
        $functionData = getFunctionData($languageData, 0);
        $viewData = getViewsData($functionData, 0);
        $renderedParserData = getRenderedParserData($functionData, 0);
        $validatorsData = getValidatorsData($functionData, 0);
        $paramsData = getParamsData('my->variable', '->');
        $logicData = getLogicsData($functionData, 0);
        $restAPIData = getRESTAPIsData($functionData, 0);

        $this->baseRoute = '/';
        $this->softwareNameInDatastore = 'apis_irestful';
        $this->newSoftwareConfigUrl = 'http://code.irestful.com/configs/softwares/apis/http_routes.json';
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
            ),
            'http://code.irestful.com/configs/softwares/apis/restapis.json' => array(
                'base_route' => '/',
                'container_data' => getRestAPIsContainerData(),
                'data' => $restAPIData
            )
        );

        $this->containerData = getHttpRoutesContainerData();
        $this->data = array(
            'first' => getHttpRouteData($restAPIData, 0),
            'second' => getHttpRouteData($restAPIData, 1)
        );
    }

    public function tearDown() {

    }

    public function testSingle_Success() {
        crud($this, $this->baseRoute, $this->dependencies, $this->softwareNameInDatastore, $this->newSoftwareConfigUrl, $this->containerData, $this->data);
    }

}
