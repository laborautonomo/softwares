<?hh
include_once('src/tests/helpers/container_data.hh');
include_once('src/tests/helpers/random_data.hh');
include_once('src/tests/helpers/crud.hh');

final class permissionsTest extends \PHPUnit_Framework_TestCase {
    private $baseRoute;
    private $softwareNameInDatastore;
    private $newSoftwareConfigUrl;
    private $dependencies;
    private $containerData;
    private $data;
    public function setUp() {

        $this->baseRoute = '/';
        $this->softwareNameInDatastore = 'apis_irestful';
        $this->newSoftwareConfigUrl = 'http://code.irestful.com/configs/softwares/apis/authentication/permissions.json';
        $this->dependencies = array(
            'http://code.irestful.com/configs/softwares/apis/datastore.json' => null
        );
        $this->containerData = getPermissionContainerData();
        $this->data = array(
            'first' => getPermissionData(0),
            'second' => getPermissionData(1)
        );
    }

    public function tearDown() {

    }

    public function testSingle_Success() {
        crud($this, $this->baseRoute, $this->dependencies, $this->softwareNameInDatastore, $this->newSoftwareConfigUrl, $this->containerData, $this->data);
    }

}
