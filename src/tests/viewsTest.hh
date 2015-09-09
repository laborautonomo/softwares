<?hh
include_once('src/tests/helpers/container_data.hh');
include_once('src/tests/helpers/random_data.hh');
include_once('src/tests/helpers/crud.hh');

final class viewsTest extends \PHPUnit_Framework_TestCase {
    private $softwareNameInDatastore;
    private $newSoftwareConfigUrl;
    private $datastoreConfigUrl;
    private $containerData;
    private $preAdditionalData;
    private $postAdditionalContainerData;
    public function setUp() {

        $languageData = getLanguageData(0);
        $functionData = getFunctionData($languageData, 0);

        $view = getViewsData($functionData, 0);
        $oneSubView = getViewsData($functionData, 1);

        $this->baseRoute = '/';
        $this->softwareNameInDatastore = 'apis_irestful';
        $this->newSoftwareConfigUrl = 'http://code.irestful.com/configs/softwares/apis/views.json';
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
        $this->containerData = getViewsContainerData();
        $this->data = array(
            'first' => getViewsData($functionData, 0, $view, array($oneSubView)),
            'second' => getViewsData($functionData, 1, $view, array($oneSubView))
        );

        $this->preAdditionalData = array(
            $view,
            $oneSubView
        );

        $this->postAdditionalContainerData = array(
            getSubViewsContainerData()
        );
    }

    public function tearDown() {

    }

    public function testSingle_Success() {
        crud($this, $this->baseRoute, $this->dependencies, $this->softwareNameInDatastore, $this->newSoftwareConfigUrl, $this->containerData, $this->data, $this->preAdditionalData, $this->postAdditionalContainerData, array('sub_views'));
    }

}
