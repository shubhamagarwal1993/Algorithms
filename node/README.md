## Basics JS

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

###
