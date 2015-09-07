<?hh
function uuid(string $uuid) {
    return hex2bin(str_replace('-', '', $uuid));
};
