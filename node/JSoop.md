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
  var johnSmith = {
 firstName: "John",
 lastName: "Smith",
 address: { //Composition
 street: "123 Duncannon Street",
 city: "London",
 country: "United Kingdom"
 }
};

var nickSmith = {
 firstName: "Nick",
 lastName: "Smith",
 address: { //Composition
 street: "321 Oxford Street",
 city: "London",
 country: "United Kingdom"
 }
};

johnSmith.parent = nickSmith; //Association

var company = {
 name: "ACME Inc.",
 employees: []
};

//Aggregation
company.employees.push(johnSmith);
company.employees.push(nickSmith);
  ```
