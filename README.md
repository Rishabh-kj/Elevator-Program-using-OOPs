# Elevator-Program-using-OOPs
**This program utilizes Object-Oriented Programming (OOP) principles, specifically inheritance and polymorphism, to model a basic elevator system implemented in C++. The program simulates the basic functionality of an elevator system, including user interaction for selecting floors and moving the elevator up or down.**

**Technical Details: -**
(1) Headers Included: The code includes several standard C++ headers like iostream, vector, ctime, algorithm, and string to use corresponding functionalities.

(2) Enums: Two enums are declared - States (representing the direction of elevator movement: UP or DOWN) and Floor (representing different floors of the building).

(3) Classes: -
[i] Building: This class represents a building. It has a virtual function getlocation() to get the location of the building. The constructor of the class prompts the user to enter the name of the building, and the destructor prints a farewell message upon the destruction of the class.
[ii] Person: This class represents a person entering the building. Its constructor initiliases the name of the person. This class also has a function authorisationstatus() that allows the user to grant or refuse authorisation to the person wanting to use the elevator. The destructor prints a farewell message upon the destruction of the class.
[iii] Elevator: This class represents an elevator in the building. It inherits from the classes Building and Person. The constructor of Elevator initialises the constructors of Building and Person, end the program if authorisation was refused for the person, and asks if the user wishes to go up or down using the elevator, provided authorisation was granted. The class has several functions to set the floor selections, move the elevator accordingly, and print messages for arriving at each floor. The destructor prints a farewell message upon the destruction of the class.
