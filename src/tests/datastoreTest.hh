<?hh
final class softwareTest extends \PHPUnit_Framework_TestCase {

    public function setUp() {

    }

    public function tearDown() {

    }


    private function generateUuid() {
        include_once('src/shared/logics/uuid.hh');
        return generateUuid();
    }

    private function executeCurlRequest(string $host, string $httpMethod, string $uri, array $data = null) {

        include_once('src/shared/logics/curl/execute.hh');

        $params = Map<string, string> {
            'host' => $host,
            'port' => 80,
            'uri' => $uri,
            'http_method' => $httpMethod
        };

        if (!empty($data)) {
            $params['data'] = $data;
        }

        return execute($params);
    }

    private function execute(string $httpMethod, string $uri, array $data = null) {

        return $this->executeCurlRequest('http://apis-datastore.softwares.irestful.com', $httpMethod, $uri, $data);
    }

    private function saveSoftwareInDataStore_Success() {

        $data = array(
            'config_url' => 'http://code.irestful.com/configs/softwares/apis/datastore.json'
        );

        $host = 'http://softwares.irestful.com';
        $uri = '/';

        $output = $this->executeCurlRequest($host, 'post', $uri, $data);

        $this->assertEquals($output['http_code'], 200);
    }

    private function insertSoftware_Success(string $name) {

        $data = array('software_name' => $name);
        $output = $this->execute('post', '/', $data);

        $this->assertEquals($output['http_code'], 200);
    }

    private function retrieveSoftware_Success(string $name, array $containers = array()) {

        $uri = '/'.$name;
        $output = $this->execute('get', $uri);
        $data = json_decode($output['content'], true);

        $this->assertEquals($output['http_code'], 200);
        $this->assertEquals($data['name'], $name);
        $this->assertEquals(count($data['containers']), count($containers));

    }


    private function deleteSoftware_Success(string $name) {

        $uri = '/'.$name;
        $output = $this->execute('delete', $uri);

        $this->assertEquals($output['http_code'], 200);
    }

    public function testSoftware_Success() {

        $this->saveSoftwareInDataStore_Success();

        $name = 'my_software';

        $this->insertSoftware_Success($name);
        $this->retrieveSoftware_Success($name);
        $this->deleteSoftware_Success($name);
    }

    private function getSimpleContainerData(string $container) {
        return array(
            'name' => $container,
            'fields' => array(
                'uuid' => array(
                    'is_primary_key' => true,
                    'type' => 'binary',
                    'length' => 16,
                    'validator' => array(
                        'language' => array(
                            'name' => 'hack',
                            'host' => 'http://hack.languages.irestful.com',
                            'port' => 80
                        ),
                        'function' => array(
                            'url' => 'http://code.irestful.com/shared/validators/uuid.hh',
                            'name' => 'uuid',
                            'language' => 'hack'
                        )
                    )
                ),
                'slug' => array(
                    'type' => 'varchar',
                    'length' => 255,
                    'validator' => array(
                        'language' => array(
                            'name' => 'hack',
                            'host' => 'http://hack.languages.irestful.com',
                            'port' => 80
                        ),
                        'function' => array(
                            'url' => 'http://code.irestful.com/shared/validators/slug.hh',
                            'name' => 'slug',
                            'language' => 'hack'
                        )
                    )
                ),
                'title' => array(
                    'type' => 'varchar',
                    'length' => 255
                ),
                'description' => array(
                    'type' => 'text'
                ),
                'created_on' => array(
                    'type' => 'bigint',
                    'length' => 11
                ),
                'last_updated_on' => array(
                    'type' => 'bigint',
                    'length' => 11,
                    'default' => 'null'
                )
            )
        );
    }

    private function insertContainer_Success(string $software, string $container) {

        $uri = '/'.$software;
        $data = $this->getSimpleContainerData($container);
        $output = $this->execute('post', $uri, $data);

        $this->assertEquals($output['http_code'], 200);
    }


    private function retrieveContainer_Success(string $software, string $container) {

        $uri = '/'.$software.'/'.$container;
        $output = $this->execute('get', $uri);
        $data = json_decode($output['content'], true);

        $this->assertEquals($output['http_code'], 200);
        $this->assertEquals($data['name'], $container);

        $shouldBeData = $this->getSimpleContainerData($container);
        $this->assertEquals($data['fields'], $shouldBeData['fields']);
    }

    private function deleteContainer_Success(string $software, string $container) {

        $uri = '/'.$software.'/'.$container;
        $output = $this->execute('delete', $uri);

        $this->assertEquals($output['http_code'], 200);

    }

    public function testContainer() {

        $this->saveSoftwareInDataStore_Success();

        $software = 'my_software';
        $container = 'my_container';

        $this->insertSoftware_Success($software);
        $this->insertContainer_Success($software, $container);
        $this->retrieveContainer_Success($software, $container);

        $this->deleteContainer_Success($software, $container);
        $this->deleteSoftware_Success($software);

    }

    private function getSimpleData() {

        return array(
            'uuid' => $this->generateUuid(),
            'slug' => 'simple-slug',
            'title' => 'This is a random title.',
            'description' => ' Nam at felis feugiat, vehicula mauris eget, finibus tortor. Fusce varius risus non velit sollicitudin, nec mattis nisi semper. Curabitur sed lacus viverra, vehicula quam non, fringilla urna. Morbi a sodales augue. Suspendisse aliquam lorem in bibendum consequat. Vivamus varius rhoncus felis, finibus cursus mauris posuere vel. Donec ullamcorper odio fermentum volutpat semper. Cras ut erat commodo, euismod nunc vel, pretium justo. Fusce at nisi sit amet erat pharetra imperdiet ut vitae libero. Proin aliquet eros id orci venenatis, id lacinia quam luctus. Etiam id faucibus orci, at interdum urna. Ut tincidunt nulla dolor, vitae viverra ipsum consectetur id. ',
            'created_on' => time()
        );

    }

    private function insertElement_Success(string $software, string $container, array $data) {

        $uri = '/'.$software.'/'.$container;
        $output = $this->execute('post', $uri, $data);

        $this->assertEquals($output['http_code'], 200);
    }

    private function retrieveElementByUuid_Success(string $software, string $container, string $uuid, array $data) {

        $uri = '/'.$software.'/'.$container.'/'.$uuid;
        $output = $this->execute('get', $uri);

        $retrievedData = json_decode($output['content'], true);

        $this->assertEquals($output['http_code'], 200);
        $this->assertEquals($retrievedData, $data);

    }

    private function retrieveElementByUniqueIdentifier_Success(string $software, string $container, string $fieldName, string $fieldValue, array $data) {

        $uri = '/'.$software.'/'.$container.'/'.$fieldName.'/'.$fieldValue;

        $output = $this->execute('get', $uri);
        $retrievedData = json_decode($output['content'], true);

        $this->assertEquals($output['http_code'], 200);
        $this->assertEquals($retrievedData, $data);

    }

    private function retrieveElementsWithPagination_Success(string $software, string $container, integer $index, integer $amount, array $queryParams, array $data) {

        $uri = '/'.$software.'/'.$container.'/elements/'.$index.'/'.$amount.'?'.http_build_query($queryParams);

        $output = $this->execute('get', $uri);

        $retrievedData = json_decode($output['content'], true);

        $this->assertEquals($output['http_code'], 200);
        $this->assertEquals($retrievedData['elements'], $data);

    }

    private function deleteElement_Success(string $software, string $container, string $uuid) {

        $uri = '/'.$software.'/'.$container.'/'.$uuid;
        $output = $this->execute('delete', $uri);

        $this->assertEquals($output['http_code'], 200);
    }

    public function testElement() {

        $this->saveSoftwareInDataStore_Success();

        $software = 'my_software';
        $container = 'my_container';

        $data = $this->getSimpleData();
        sleep(2); //we sleep to get different created_on timestamps
        $secondData = $this->getSimpleData();
        $queryParams = array('order_by' => 'created_on');

        //insert the software, then the container, then the element:
        $this->insertSoftware_Success($software);
        $this->insertContainer_Success($software, $container);

        //insert, retrieve then delete one element:
        $this->insertElement_Success($software, $container, $data);
        $this->retrieveElementByUuid_Success($software, $container, $data['uuid'], $data);
        $this->retrieveElementByUniqueIdentifier_Success($software, $container, 'slug', $data['slug'], $data);
        $this->deleteElement_Success($software, $container, $data['uuid']);

        //insert 2 elements and retrieve them with pagination:
        $this->insertElement_Success($software, $container, $data);
        $this->insertElement_Success($software, $container, $secondData);
        $this->retrieveElementsWithPagination_Success($software, $container, 0, 2, $queryParams, array($data, $secondData));
        $this->retrieveElementsWithPagination_Success($software, $container, 0, 1, $queryParams, array($data));
        $this->retrieveElementsWithPagination_Success($software, $container, 1, 1, $queryParams, array($secondData));
        $this->deleteElement_Success($software, $container, $data['uuid']);
        $this->deleteElement_Success($software, $container, $secondData['uuid']);

        //delete the software, container then the element:
        $this->deleteContainer_Success($software, $container);
        $this->deleteSoftware_Success($software);

    }

}
