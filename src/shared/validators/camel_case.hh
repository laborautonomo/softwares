<?hh
function camelCase(string $input) {

    $matches = array();
    preg_match_all('/[a-zA-Z]+/s', $input, $matches);

    if (isset($matches[0][0]) && ($matches[0][0] == $input)) {
        return strtolower($matches[0][0]);
    }

    throw new \Exception('The given input ('.$input.') is not a valud camelCase input.', 500);
};
