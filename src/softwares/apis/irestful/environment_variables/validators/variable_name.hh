<?hh
function variableName(string $input) {

    $matches = array();
    preg_match_all('/[A-Z\_]+/s', $input, $matches);

    if (!isset($matches[0][0]) || ($matches[0][0] != $input)) {
        throw new \Exception('Environment variables can only contain upper case letters and underscores.  Input: '.$input, 500);
    }

    return $matches[0][0];
};
