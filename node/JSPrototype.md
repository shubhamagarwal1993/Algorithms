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
   - 
