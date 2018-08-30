<?php

    function flatten($input) {

        $arr = [];

        foreach($input as $v) {
            if(is_array($v)) {
                $arr = array_merge($arr, flatten($v));
            } else {
                array_push($arr, $v);
            }
        }

        return $arr;
    }

    $arr = [1, [2, 3], [[[4]]]];
    var_dump(json_encode(flatten($arr)));

?>
