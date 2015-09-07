<?hh
function keyname(string $input) {

    $matches = array();
    preg_match_all('/[a-z\_]+/s', $input, $matches);

    if (!isset($matches[0][0]) || ($matches[0][0] != $input)) {
        throw new \Exception('Keynames can only contain lower case letters and hyphens.  Input: '.$input, 500);
    }

    return $matches[0][0];
};
