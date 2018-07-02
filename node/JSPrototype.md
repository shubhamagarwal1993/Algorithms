# Prototype
 - Following are 2 imp concepts with prototype

### Prototype Property
  - Every JS function (object) has a prototype property which is empty by default
    - Can attach properties and methods on this prototype property when you want to implement inheritance
    - This prototype property is not enumerable; that is, it isn’t accessible in a for/in loop
    ```
      function PrintStuff(myDocuments) {
          this.documents = myDocuments;
      }

      // We add the print() method to PrintStuff prototype property so that other instances (objects) can inherit it:
      PrintStuff.prototype.print = function() {
          console.log(this.documents);
      }

      // Create a new object with the PrintStuff() constructor, thus allowing this new object to inherit PrintStuff's properties and methods
      var newObj = new PrintStuff("I am a new Object and I can print");

      // newObj inherited all the properties and methods, including the print method, from the PrintStuff function
      // Now newObj can call print directly, even though we never created a print() method on it
      newObj.print();    // I am a new Object and I can print
    ```
    - Most browsers have a __proto__ "pseudo" property that allows you to access an object's prototype property in browsers
    - The prototype property is used primarily for inheritance; you add methods and properties on a function’s prototype
      property to make those methods and properties available to instances of that function.

### Prototype Attribute
  - A characteristic of the object, which tells us the object’s “parent”
    - An object’s prototype attribute points to the object’s “parent” — the object it inherited its properties from
    - The prototype attribute is normally referred to as the prototype object, and it is set automatically when you create a new object
    ```
      function PrintStuff(myDocuments) {
          this.documents = myDocuments;
      }

      PrintStuff.prototype.print = function() {
          console.log(this.documents);
      }

      // Create a new object with the PrintStuff() constructor, thus allowing this new object to inherit PrintStuff's properties and methods
      var newObj = new PrintStuff("I am a new Object and I can print");

      newObj‘s prototype is PrintStuff.prototype
    ```
    - The __proto__ “pseudo” property contains an object’s prototype object 
    - The object attributes are prototype, class, and extensible attributes

## Constructor
 - A constructor is a function used for initializing new objects, and you use the new keyword to call the constructor
 ```
   function Account() {
   }

   var userAccount = new Account();
 ```
 - All objects that inherit from another object also inherit a constructor property
 - This constructor property is simply a property (like any variable) that holds or points to the constructor of the object
 ```
   // The constructor in this example is Object()
   var myObj = new Object();

   // The myObj constructor:
   console.log(myObj.constructor);    // Object()

   function Account() {
   }

   var userAccount = new Account();
   console.log(userAccount.constructor);    // Account()
 ```

## Setting prototype attribute of objects
 #### Prototype Attribute of Objects created with new Object() or Object Literal
  - All objects created with object literals and with the Object constructor inherits from Object.prototype
  - Therefore, Object.prototype is the prototype attribute (or the prototype object) of all objects created with new Object () or with {}
  - Object.prototype itself does not inherit any methods or properties from any other object
  ```
    // The userAccount object inherits from Object and as such its prototype attribute is Object.prototype
    var userAccount = new Object();

    // This demonstrates the use of an object literal to create the userAccount object
    // The userAccount object inherits from Object; therefore, its prototype attribute is Object.prototype just as the userAccount object does above
    var userAccount = {name: “Mike”}
  ```
 #### Prototype Attribute of Objects created with a Constructor Function
  - Objects created with the new keyword and any constructor other than the Object() constructor, get their prototype from the constructor function
  ```
    function Account() {
    }

    // userAccount initialized with the Account () constructor and as such its prototype attribute (or prototype object) is Account.prototype
    var userAccount = new Account()
  ```
 - Any array such as var myArray = new Array (), gets its prototype from Array.prototype and it inherits Array.prototype’s properties
 - 2 general ways an object's prototype attribute is set when an object is created:
   - If an object is created with an object literal (var newObj = {}), it inherits properties from Object.prototype
     and we say its prototype object (or prototype attribute) is Object.prototype
   - If an object is created from a constructor function such as new Object(), new Fruit() or new Array() or new Anything(),
     it inherits from that constructor (Object(), Fruit(), Array(), or Anything())
     ```
       function Fruit() {
       }

       var aFruit = new Fruit();
       // aFruit's prototype is Fruit.prototype

       var aArray = new Array();
       // aArray's prototype is Array.prototype

       var anObj = new Object();
       // anObj's prototype is Object.prototype
     ```

### Use of Prototype
 - 2 important ways the prototype is used in JavaScript:
   - Prototype property: Prototype-bases inheritance
     - JavaScript has a prototype-based inheritance mechanism
     - Example of inheritance in JavaScript
     ```
       function Plant() {
           this.country = "Mexico";
           this.isOrganic = true;
       }

       // Add the showNameAndColor method to the Plant prototype property
       Plant.prototype.showNameAndColor = function () {
           console.log("I am a " + this.name + " and my color is " + this.color);
       }

       // Add the amIOrganic method to the Plant prototype property
       Plant.prototype.amIOrganic = function() {
         if(this.isOrganic) {
             console.log("I am organic, Baby!");
         }
       }

       function Fruit(fruitName, fruitColor) {
           this.name = fruitName;
           this.color = fruitColor;
       }

       // Set the Fruit's prototype to Plant's constructor, thus inheriting all of Plant.prototype methods and properties
       Fruit.prototype = new Plant();

       // Creates a new object, aBanana, with the Fruit constructor
       var aBanana = new Fruit("Banana", "Yellow");

       // aBanana uses the name property from the aBanana object prototype, which is Fruit.prototype
       console.log(aBanana.name);    // Banana

       // Use showNameAndColor method from Fruit object prototype, which is Plant.prototype
       // The aBanana object inherits all the properties and methods from both the Plant and Fruit functions
       console.log(aBanana.showNameAndColor());    // I am a Banana and my color is yellow
     ```
     - Any object that uses the Fruit() constructor will inherit all the Fruit.prototype properties and methods and all the
       properties and methods from the Fruit’s prototype, which is Plant.prototype
     - This is the principal manner in which inheritance is implemented in JavaScript and the integral role the prototype chain has in the process
   - Prototype Attribute: Accessing Properties on Objects
     - Prototype is important for accessing properties and methods of objects
     - The prototype attribute (or prototype object) of any object is the “parent” object where the inherited properties were originally defined. If we wanted to find out where the prototype properties came from, we would first check to see if the object created it itself; if not, the search will move to it's prototype parent to see if the object inherited it from parent object. If it was not created by parent object, then the search continues to the parent of the parent's object
     - The prototype chain
        ```
          The chain from an object’s prototype to its prototype’s prototype and onwards. And JavaScript uses this prototype chain to look for properties and methods of an object.

          If you want to access a property of an object, the search for the property begins directly on the object. If the JS runtime can’t find the property there, it then looks for the property on the object’s prototype—the object it inherited its properties from.

          If the property is not found on the object’s prototype, the search for the property then moves to prototype of the object’s prototype (the father of the object’s father—the grandfather). And this continues until there is no more prototype (no more great-grand father; no more lineage to follow).

          If the property does not exist on any of the object’s prototype in its prototype chain, then the property does not exist and undefined is returned.
        ```
     - Example of the prototype chain
     ```
       function People() {
           this.superstar = "Michael Jackson";
       }

       // Define "athlete" property on the People prototype so that "athlete" is accessible by all objects that use the People() constructor
       People.prototype.athlete = "Tiger Woods";

       var famousPerson = new People();
       famousPerson.superstar = "Steve Jobs";

       // The search for superstar will first look for the superstar property on the famousPerson object, and since we defined it there, that is the property that will be used. Because we have overwritten the famousPerson’s superstar property with one directly on the famousPerson object, the search will NOT proceed up the prototype chain. 
       console.log(famousPerson.superstar);    // Steve Jobs

       // Note that in ECMAScript 5 you can set a property to read only, and in that case you cannot overwrite it as we just did.

      // This will show the property from the famousPerson prototype (People.prototype), since the athlete property was not defined on the famousPerson object itself.
      console.log(famousPerson.athlete);    // Tiger Woods

       // In this example, the search proceeds up the prototype chain and find the toString method on Object.prototype, from which the Fruit object inherited—all objects ultimately inherits from Object.prototype as we have noted before.
       console.log(famousPerson.toString());    // [object Object]
     ```
     - All built-in constructors (Array(), Number(), String(), etc.) were created from the Object constructor, and as such their prototype is Object.prototype
     
