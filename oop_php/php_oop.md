## Inheritance
 - 3 type of inheritance
   - Single
   - Multiple
   - Multi-level inheritance
 - PHP is a single inheritance language, and does not support multiple inheritance
 - PHP supports multilevel inheritance (also called hierarchical inheritance), and single inheritance
     ```
       // Single inheritance
       <?php
     
       class Foo {
           public function printItem($string) {
               echo 'Foo: ' . $string . PHP_EOL;
           }
     
           public function printPHP() {
               echo 'PHP is great.' . PHP_EOL;
           }
       }
     
       class Bar extends Foo {
           public function printItem($string) {
               echo 'Bar: ' . $string . PHP_EOL;
           }
       }
     
       $foo = new Foo();
       $bar = new Bar();
       $foo->printItem('baz');    // Output: 'Foo: baz'
       $foo->printPHP();          // Output: 'PHP is great' 
       $bar->printItem('baz');    // Output: 'Bar: baz'
       $bar->printPHP();          // Output: 'PHP is great'
     
       ?>
     ```
     ```
       // Multilevel inheritance

     ```
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
     ```

