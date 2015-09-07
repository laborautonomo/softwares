<?hh
include_once('src/tests/helpers/container_data.hh');
include_once('src/tests/helpers/random_data.hh');
include_once('src/tests/helpers/crud.hh');

final class functionsTest extends \PHPUnit_Framework_TestCase {

    private $languageSoftwareConfigUrl;
    private $languageContainerData;
    private $languageData;

    private $softwareNameInDatastore;
    private $newSoftwareConfigUrl;
    private $datastoreConfigUrl;
    private $containerData;

    private $firstData;
    private $secondData;
    public function setUp() {

        $this->languageSoftwareConfigUrl = 'http://code.irestful.com/configs/softwares/apis/languages.json';
        $this->languageContainerData = getLanguageContainerData('languages');
        $this->languageData = getLanguageData(0);

        $this->softwareNameInDatastore = 'apis_irestful';
        $this->newSoftwareConfigUrl = 'http://code.irestful.com/configs/softwares/apis/functions.json';
        $this->datastoreConfigUrl = 'http://code.irestful.com/configs/softwares/apis/datastore.json';
        $this->containerData = getFunctionsContainerData('functions');

        $this->firstData = getFunctionData($this->languageData, 0);
        $this->secondData = getFunctionData($this->languageData, 1);
    }

    public function tearDown() {

    }
    
    public function testSingle_Success() {

        $baseRoute = '/';

        //create the datastore software:
        saveNewSoftware($this->datastoreConfigUrl);

        //create the language software:
        saveNewSoftware($this->languageSoftwareConfigUrl);

        //setup the language software with its containers:
        insertSoftwareInDatastore($this->softwareNameInDatastore);
        insertContainerInDatastore($this->softwareNameInDatastore, $this->languageContainerData);

        //insert a language:
        crudInsert('apis-irestful-languages', $baseRoute, $this->languageData);

        //interact with functions:
        preCrud($this->softwareNameInDatastore, $this->newSoftwareConfigUrl, $this->containerData);
        crud($this, $baseRoute, $this->newSoftwareConfigUrl, $this->firstData, $this->secondData);

        //delete function container:
        deleteContainerFromDatastore($this->softwareNameInDatastore, $this->containerData['name']);

        //delete the language and its container:
        crudDelete('apis-irestful-languages', $baseRoute, $this->languageData['uuid']);
        deleteContainerFromDatastore($this->softwareNameInDatastore, $this->languageContainerData['name']);

        //delete the software from datastore:
        deleteSoftwareFromDatastore($this->softwareNameInDatastore);
    }

}
