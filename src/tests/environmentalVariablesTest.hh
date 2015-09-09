<?hh
include_once('src/tests/helpers/container_data.hh');
include_once('src/tests/helpers/random_data.hh');
include_once('src/tests/helpers/crud.hh');

final class environmentVariablesTest extends \PHPUnit_Framework_TestCase {
    private $baseRoute;
    private $softwareNameInDatastore;
    private $newSoftwareConfigUrl;
    private $dependencies;
    private $containerData;
    private $data;
    public function setUp() {

        $this->baseRoute = '/';
        $this->softwareNameInDatastore = 'apis_irestful';
        $this->newSoftwareConfigUrl = 'http://code.irestful.com/configs/softwares/apis/environment_variables.json';
        $this->dependencies = array(
            'http://code.irestful.com/configs/softwares/apis/datastore.json' => null
        );
        $this->containerData = getEnvironmentVariableContainerData();
        $this->data = array(
            'first' => getEnvironmentVariablesData(0),
            'second' => getEnvironmentVariablesData(1)
        );
    }
    
    public function tearDown() {

    }

    public function testSingle_Success() {
        crud($this, $this->baseRoute, $this->dependencies, $this->softwareNameInDatastore, $this->newSoftwareConfigUrl, $this->containerData, $this->data);
    }
}
