<?php

class Grandparent {
    public function printgp() {
        echo 'I am grandparent ' . PHP_EOL;
    }

    public function printItem($string) {
        echo 'GP: ' . $string . PHP_EOL;
    }
}

class ParentClass extends Grandparent {
    public function printParent() {
        echo 'I am parent ' . PHP_EOL;
    }

    public function printItem($string) {
        echo 'Parent: ' . $string . PHP_EOL;
    }
}

class Child extends ParentClass {
    public function printChild() {
        echo 'I am child ' . PHP_EOL;
    }

    public function printItem($string) {
        echo 'Child: ' . $string . PHP_EOL;
    }
}

$gp = new Grandparent();
$parent = new ParentClass();
$child = new Child();

$gp->printgp();
$parent->printParent();
$child->printChild();

$child->printItem('abcd');
$child->printParent();
$child->printgp();

?>
