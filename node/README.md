## Basics JS
 - need to add some info on starting JS

### Data types
 - complex data type (mutable)
   - Object data type
     - Unordered list of name-value pairs:
       - property:
         - data types (primitive or reference)
       - methods:
         - also called functions
     ```
     var myFirstObject = {
        firstName: "abcd",
        lastName: "efgh",
        fullName : function() {
            return this.firstName + " " + this.lastName;
        }
     };
     ```
 - primitive/simple data types (immutable)
   - Number
   - String
   - Boolean
   - Undefined
   - Null

### Reference Data Type and Primitive Data Types
 - Reference data type’s value is stored as a reference, it is not stored directly on the variable
   ```
   var object1 = {name: "abcd"};
   var object2 = object1;
   object1.name = "efgh";
   console.log(object1.name);    // This will print efgh
   console.log(object2.name);    // This will print efgh
   ```
 - Primitive data type's value is stored directly on the variable
   ```
   var string1 = "str1";
   var string2 = string1;
   string1 = "str3";
   console.log(string2);    // This will print str1
   console.log(string1);    // This will print str3
   ```

### Mode details on Object data type
  - Each data property (object property that store data) has not only the name-value pair, but also 3 attributes
  - All 3 attributes are set to true by default
    - Configurable Attribute: Specifies whether the property can be deleted or changed
    — Enumerable: Specifies whether the property can be returned in a for/in loop
    — Writable: Specifies whether the property can be changed
  - ECMAScript 5 specifies accessor properties along with the data properties noted above. The accessor properties are functions (getters and setters)

### Creating Objects (2 common ways):
  - Both ways are the same, there is no difference
  - Object Literals
    ```
    // Empty object
    var myBooks = {};

    // object with 4 items
    var mango = {
        color: "yellow",
        shape: "round",
        sweetness: 8

        howAreYou: function () {
            console.log("very good");
        }
    }
    ```
  - Object Constructor (using `new` keyword calls the constructor)
    ```
    var mango =  new Object ();

    mango.color = "yellow";
    mango.shape= "round";
    mango.sweetness = 8;

    mango.howSweetAmI = function () {
        console.log("Hmm Hmm Good");
    }
    ```

### Practical patterns for creating objects:
 - a normal object to be created and used once can simple be made using object literal, or object constructor and will look something like:
 ```
 var mangoFruit = {
     color: "yellow",
     sweetness: 8,
     fruitName: "Mango",
     nativeToLand: ["South America", "Central America"],
     showName: function () {
         console.log("This is " + this.fruitName);
      },
      nativeTo: function () {
          this.nativeToLand.forEach(function (eachCountry) {
              console.log("Grown in:" + eachCountry);
          });
      }
  }
  ```
 - For application needing a more robust method to avoid repetition, we can use one of the following:
   - Constructor Pattern for creating objects
       The pattern encapsulates all the functionalities and characteristics of all the fruits in by making just the single Fruit function with inheritance
       ```
       function Fruit(theColor, theSweetness, theFruitName, theNativeToLand) {
           this.color = theColor;
           this.sweetness = theSweetness;
           this.fruitName = theFruitName;
           this.nativeToLand = theNativeToLand;
           this.showName = function () {
               console.log("This is a " + this.fruitName);
           }
           this.nativeTo = function () {
               this.nativeToLand.forEach(function (eachCountry)  {
                   console.log("Grown in:" + eachCountry);
               });
           }
       }
       ```
       With this pattern in place, we can create all sorts of fruits.
       ```
       var mangoFruit = new Fruit("Yellow", 8, "Mango", ["South America", "Central America", "West Africa"]);
       mangoFruit.showName();        // This is a Mango
       mangoFruit.nativeTo();        // Grown in:South America, Grown in:Central America, Grown in:West Africa

       var pineappleFruit = new Fruit("Brown", 5, "Pineapple", ["United States"]);
       pineappleFruit.showName();    // This is a Pineapple
       ```
       We can further create own properties (not inherited) directly on the object itself
       ```
       var aMango = new Fruit("Yellow", 8, "Mango", ["South America", "Central America", "West Africa"]);    // create object

       // mangoSpice property is defined directly on aMango object, it is aMango's own property, not an inherited property
       aMango.mangoSpice = “some value”;    // Define a new property, mangoSpice directly on the aMango object
       console.log(aMango.mangoSpice);      // “some value”.   To access property of an object, use object.property

       aMango.printStuff = function () {return “Printing”;}.   // add a method
       aMango.printStuff ();    // To invoke a method of an object, use object.method()
       ```

   - Prototype Pattern for creating objects
       ```
       function Fruit() {
       }

       Fruit.prototype.color = "Yellow";
       Fruit.prototype.sweetness = 7;
       Fruit.prototype.fruitName = "Generic Fruit";
       Fruit.prototype.nativeToLand = "USA";

       Fruit.prototype.showName = function () {
           console.log("This is a " + this.fruitName);
       }

       Fruit.prototype.nativeTo = function () {
           console.log("Grown in:" + this.nativeToLand);
       }
       ```
       Call the Fruit() constructor to make a fruit object
       ```
       var mangoFruit = new Fruit ();
       mangoFruit.showName();    // This is a Generic Fruit
       mangoFruit.nativeTo();    // Grown in:USA
       ```

### Accessing properties of an object
 Accessing a property on an object that does not exist will result in `undefined`
 - Dot Notation
       ```
       var book = {
           title: "Ways to Go",
           pages: 280,
           bookMark1: "Page 20"
       };

       // To access properties of book object with dot notation:
       console.log(book.title);    // Ways to Go
       console.log(book.pages);    // 280
       ```
 - Bracket Notation
        ```
       var book = {
           title: "Ways to Go",
           pages: 280,
           bookMark1: "Page 20"
       };

       // To access properties of book object with dot notation:
       console.log(book["title"]);    // Ways to Go
       console.log(book["pages"]);    // 280
       ```

### test
