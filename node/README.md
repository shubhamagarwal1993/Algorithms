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
       }

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
       }

       // To access properties of book object with dot notation:
       console.log(book["title"]);    // Ways to Go
       console.log(book["pages"]);    // 280
     ```

### Own and Inherited properties
 - Objects have inherited properties and own properties. The own properties are properties that were defined on the object, while the inherited properties were inherited from the object’s Prototype object
 - To find out if a property exists on an object (either as an inherited or an own property), you use the in operator:
   ```
     var school = {schoolName: "MIT"};    // Create new school object with a property name schoolName

     console.log("schoolName" in school); // true    Prints true because schoolName is an own property on the school object
     console.log("schoolType" in school); // false   Prints false because we did not define a schoolType property on the school object, and neither did the object inherit a schoolType property from its prototype object Object.prototype
     console.log("toString" in school);   // true    Prints true because the school object inherited the toString method from Object.prototype
   ```
 - hasOwnProperty
     To find out if an object has a specific property as one of its own property, you use the hasOwnProperty method.
     This method is very useful because from time to time you need to enumerate an object and you want only the own properties, not the inherited ones
     ```
       var school = {schoolName: "MIT"};    // Create new school object with a property name schoolName

       console.log(school.hasOwnProperty ("schoolName"));    // true    Prints true because schoolName is an own property on the school object

       console.log(school.hasOwnProperty ("toString"));      // false    Prints false because the school object inherited the toString method from Object.prototype, therefore toString is not an own property of the school object
     ```
 - Accessing and Enumerating Properties on Objects
     To access the enumerable(own and inherited) properties on objects, you use the for/in loop or a general for loop
     ```
       var school = {schoolName: "MIT", schoolAccredited: true, schoolLocation: "Massachusetts"};    // Create a new school object with 3 own properties: schoolName, schoolAccredited, and schoolLocation

       for (var eachItem in school) {     // Prints schoolName, schoolAccredited, schoolLocation
           console.log(eachItem);
       }
     ```
 - Accessing inherited properties
     Properties inherited from Object.prototype are not enumerable, so the for/in loop does not show them
     However, inherited properties that are enumerable are revealed in the for/in loop iteration
     ```
       var school = {schoolName: "MIT", schoolAccredited: true, schoolLocation: "Massachusetts"};    // Create a new school object with 3 own properties: schoolName, schoolAccredited, and schoolLocation

       for(var eachItem in school) {
           console.log(eachItem);    // Prints schoolName, schoolAccredited, schoolLocation
       }

       // Create a new HigherLearning function that the school object will inherit from
       function HigherLearning () {
           this.educationLevel = "University";
       }

       // Implement inheritance with the HigherLearning constructor
       var school = new HigherLearning ();
       school.schoolName = "MIT";
       school.schoolAccredited = true;
       school.schoolLocation = "Massachusetts";

       for (var eachItem in school) {
           console.log(eachItem);    // Prints educationLevel, schoolName, schoolAccredited, and schoolLocation
       }

       // The educationLevel property is not actually inherited by objects that use the HigherLearning constructor; instead,
          the educationLevel property is created as a new property on each object that uses the HigherLearning constructor.
          The reason the property is not inherited is because we use of the "this" keyword to define the property.
     ```

### Deleting properties of an object
 - 
