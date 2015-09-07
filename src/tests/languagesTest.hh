<?hh
include_once('src/tests/helpers/container_data.hh');
include_once('src/tests/helpers/random_data.hh');
include_once('src/tests/helpers/crud.hh');

final class languagesTest extends \PHPUnit_Framework_TestCase {

    private $softwareNameInDatastore;
    private $newSoftwareConfigUrl;
    private $datastoreConfigUrl;
    private $containerData;
    private $firstData;
    private $secondData;
    public function setUp() {

        $this->softwareNameInDatastore = 'apis_irestful';
        $this->newSoftwareConfigUrl = 'http://code.irestful.com/configs/softwares/apis/languages.json';
        $this->datastoreConfigUrl = 'http://code.irestful.com/configs/softwares/apis/datastore.json';
        $this->containerData = getLanguageContainerData('languages');
        $this->firstData = getLanguageData(0);
        $this->secondData = getLanguageData(1);
    }

    public function tearDown() {

    }

    public function testSingle_Success() {

        $baseRoute = '/';

        //create the datastore software:
        saveNewSoftware($this->datastoreConfigUrl);

        //create the software, in our datastore:
        insertSoftwareInDatastore($this->softwareNameInDatastore);

        //interact with functions:
        preCrud($this->softwareNameInDatastore, $this->newSoftwareConfigUrl, $this->containerData);
        crud($this, $baseRoute, $this->newSoftwareConfigUrl, $this->firstData, $this->secondData);

        //delete settings container:
        deleteContainerFromDatastore($this->softwareNameInDatastore, $this->containerData['name']);

        //delete the software from datastore:
        deleteSoftwareFromDatastore($this->softwareNameInDatastore);
    }

}