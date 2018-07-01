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
      sweetness: 8,

    howAreYou: function () {
      console.log("very good");
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

### 
