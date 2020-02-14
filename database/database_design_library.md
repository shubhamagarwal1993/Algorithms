# Library book checkout database layout

### Library
- id (int)        : Unique ID of library
- name (string)   : Name of library
- address (string): Adress of library

### User
- id (int)      : Unique ID of user
- first (string): first name of user
- last (string) : last name of user
- email (string): email of user

### Book
- library_id (int - foreign Key - library.id): id of library to which book belongs
- title (string)                             : title/name of book
- author (int - foreign key - user.id)       : id of user who wrote the book
- publication_date (datetime)                : When book was published
- isbn (string)                              : ISBN alpha numberic string
- catalog_id (int)                           : Catalog ID unique to book in library

// This maintains unique catalog_id in each library
CONSTRAINT catalog_id UNIQUE (catalog_id, library_id)

// This table helps user be part of many or no libraries
### Library_Card
- user_id (int - foreign key - user.ud)      : The id of the user
- library_id (int - foreign key - library.id): The id of the library

### Checkout
- id (int)                                           : The checkout id, will be needed to record transactions, as well as one user can checkout multiple copies of the same book from the same library
- user_id (int - foreign key - user.id)              : The user who checked out a book
- library_id (int - foreign key - library.id)        : The library from which the user checked out a book
- catalog_id (int - foreign key - library.catalog_id): The unique combination of a book in a library
- created (datetime)                                 : The date and time on which the user checked out the book
- returned (datetime)                                : The date and time on which the book was returned

