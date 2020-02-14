# Design Patterns
Provides a general reusable solution, and defines relationships and interactions between classes or objects. There are three types of design patterns:

## Creational Patterns:
These design patterns are all about class instantiation or object creation. Types of creational design patterns:
  - Class-creational patterns
    - Use inheritance effectively in the instantiation process.
  - Object-creational patterns
    - Use delegation effectively.

 ### Factory Method
   - If you want to create multiple instances of similar kind and want to achieve loose coupling.
   - A class implementing factory design pattern works as a bridge between multiple classes.
   - Consider an example of using multiple database servers like SQL Server and Oracle. If you are developing an application using SQL Server database as back end, but in future need to change database to oracle, you will need to modify all your code, so as factory design patterns maintain loose coupling and easy implementation we should go for factory for achieving loose coupling and creation of similar kind of object.
 ### Abstract Factory
 ### Builder
 ### Object Pool
 ### Prototype
 ### Singleton
   - Simple DBConnection class to connect to a database and access the database at multiple locations from code.
   - Creating an instance of DBConnection class and using it for doing database operations wherever required results in creating multiple connections from the database as each instance of DBConnection class will have a separate connection to the database.
   - Instead create DBConnection class as a singleton class, so that only one instance of DBConnection is created and a single connection is established. Because we can manage DB Connection via one instance so we can control load balance, unnecessary connections, etc.

## Structural Patterns:
These design patterns are about organizing different classes and objects to form larger structures and provide new functionality.

### Adapter Patterns:
 - When 2 interfaces are not compatible with each other and want to establish a relationship between them through an adapter.
 - Adapter pattern converts the interface of a class into another interface or classes the client expects that is adapter lets classes works together that could not otherwise because of incompatibility.
### Bridge
### Composite
### Decorator
### Facade
### Flyweight
### Private Class Data
### Proxy
### Curiously Recurring Template
### Interface-based Programming (IBP)

## Behavioral Patterns:
Behavioral patterns are about identifying common communication patterns between objects and realize these patterns.

### Chain of responsibility
### Command
### Interpreter
### Iterator
### Mediator
### Memento
### Null Object
### Observer
### State
### Strategy
### Template method
 - Template pattern defines the skeleton of an algorithm in an operation deferring some steps to sub-classes.
 - Template method lets subclasses redefine certain steps of an algorithm without changing the algorithm structure.
 - For example, if in a project no source code changes can be made, so you can't modify the structure 
 - If you want to extend the behavior of a module, such that we can make the module behave in new and different ways as the requirements of the application change, or to meet the needs of new applications.
### Visitor
### Model-View-Controller (MVC)

# Usage and remembering
- Cannot remember all the patterns, just be familiar
- See the ones that you have experience with, and why you chose that over others.
