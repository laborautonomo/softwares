<?hh
function url(string $input) {

    if (filter_var($input, FILTER_VALIDATE_URL) === false) {
        throw new \Exception('The given input is not a valid URL.  Input: '.$input, 500);
    }

    return $input;
};
