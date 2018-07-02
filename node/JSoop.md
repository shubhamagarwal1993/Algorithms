## What is OOP
 - a widely accepted definition to classify a programming language as Object Oriented is based on two requirements:
   - Its capability to model a problem through objects
   - Its support of a few principles that grant modularity and code reuse

#### Model a program through objects
  - Language must enable a developer to describe the reality using objects and to define relationships among objects such as:
    - Association: This is the object’s capability to refer another independent object
    - Aggregation: This is the object’s capability to embed one or more independent objects
    - Composition: This is the object’s capability to embed one or more dependent objects

#### Support of basic OOP principles
  - Language must support the following principles:
    - Encapsulation: This is the capability to concentrate into a single entity data and code that manipulates it, hiding its internal details
    - Inheritance: This is the mechanism by which an object acquires some or all features from one or more other objects
    - Polymorphism: This is the capability to process objects differently based on their data type or structure

### Showing that JavaScript objects support Association, Aggregation and Composition
  - An example of how the three basic relationships can be implemented in JavaScript
  ```
    // Composition: address (a dependent object) is embedded inside object johnSmith
    var johnSmith = {
        firstName: "John",
        lastName: "Smith",
        address: {
            street: "123 Duncannon Street",
            city: "London",
            country: "United Kingdom"
        }
    };

    // Composition: address (a dependent object) is embedded inside object nickSmith
    var nickSmith = {
        firstName: "Nick",
        lastName: "Smith",
        address: {
            street: "321 Oxford Street",
            city: "London",
            country: "United Kingdom"
        }
    };

    // Association: object nickSmith is referred by another independent object johnSmith
    johnSmith.parent = nickSmith;

    var company = {
        name: "ACME Inc.",
        employees: []
    };

    // Aggregation: object johnSmith and nickSmith (independent objects) embedded inside object company
    company.employees.push(johnSmith);
    company.employees.push(nickSmith);
  ```

### Showing that JavaScript objects support Encapsulation
 - JavaScript objects are entities supporting data and functions
 - JavaScript objects do not care about privacy, and dosen't have an advanced native support to hide internal details
 - All the properties and methods are publicly accessible if no caution is taken
   - We can apply several techniques in order to define an object’s internal state and protect it from external access
     by using getters and setters to exploiting closures.

### Showing that JavaScript objects support Inheritance
 - supported by JavaScript in its basic level through the so-called Prototypal Inheritance

### Showing that JavaScript objects support Polymorphism
 - 

## What makes JS not an OOP
 - JS does not have classes
 - By our definition, there is no explicit reference to classes.
 - Features and principles are required for objects, but classes are not a real requirement

