<?hh
include_once('src/tests/helpers/container_data.hh');
include_once('src/tests/helpers/random_data.hh');
include_once('src/tests/helpers/crud.hh');

final class rolesTest extends \PHPUnit_Framework_TestCase {
    private $softwareNameInDatastore;
    private $newSoftwareConfigUrl;
    private $datastoreConfigUrl;
    private $containerData;
    private $preAdditionalData;
    private $postAdditionalContainerData;
    public function setUp() {

        $permissionData = getPermissionData(0);

        $this->baseRoute = '/';
        $this->softwareNameInDatastore = 'apis_irestful';
        $this->newSoftwareConfigUrl = 'http://code.irestful.com/configs/softwares/apis/authentication/roles.json';
        $this->dependencies = array(
            'http://code.irestful.com/configs/softwares/apis/datastore.json' => null,
            'http://code.irestful.com/configs/softwares/apis/authentication/permissions.json' => array(
                'base_route' => '/',
                'container_data' => getPermissionContainerData(),
                'data' => $permissionData
            )
        );
        $this->containerData = getRolesContainerData();
        $this->data = array(
            'first' => getRolesData(0, array($permissionData)),
            'second' => getRolesData(1, array($permissionData))
        );

        $this->preAdditionalData = array(

        );

        $this->postAdditionalContainerData = array(
            getRolePermissions()
        );
    }

    public function tearDown() {

    }

    public function testSingle_Success() {
        crud($this, $this->baseRoute, $this->dependencies, $this->softwareNameInDatastore, $this->newSoftwareConfigUrl, $this->containerData, $this->data, $this->preAdditionalData, $this->postAdditionalContainerData, array('permissions'));
    }

}
