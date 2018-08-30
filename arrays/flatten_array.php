<?php

    function flatten_recursive($input) {

        $arr = [];

        foreach($input as $v) {
            if(is_array($v)) {
                $arr = array_merge($arr, flatten_recursive($v));
            } else {
                array_push($arr, $v);
            }
        }

        return $arr;
    }

    function flatten_iterative($input) {

        $arr = [];
        $index = 0;
        $input_size = count($input);

        while($index < $input_size) {

            $var = $input[$index];

            if(is_array($var)) {
                $temp = $var;
                // second loop
                $has_an_array = true;
                while($has_an_array) {
                    $has_an_array = false;
                    foreach($temp as $temp_key => $temp_val) {
                        if(is_array($temp_val)) {
                            $has_an_array = true;
                            // extract level
                            foreach($temp_val as $k => $v) {
                                array_push($temp, $v);
                            }
                            unset($temp[$temp_key]);
                        } else {
                            array_push($arr, $temp_val);
                            unset($temp[$temp_key]);
                        }
                    }
                }
            } else {
                array_push($arr, $var);
            }

            $index++;
        }

        return $arr;
    }

    $input_arr = [1, [2, 3], [[[4]]], [[[[[[[[5, 6, 7, [[8, 9, [], [], [], [[[]]]]]]]]]]]]]];
    var_dump(json_encode(flatten_recursive($input_arr)));
    var_dump(json_encode(flatten_iterative($input_arr)));

?>
