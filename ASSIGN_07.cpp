/*1. Write a SimpleCircle class declaration (only) with one member variable: itsRadius. Include a 
default constructor, a destructor, and accessor methods for radius. 
2. Using the class you created in Exercise 1, write the implementation of the default constructor, 
initializing itsRadius with the value 5. 
3. Using the same class, add a second constructor that takes a value as its parameter and assigns 
that 
value to itsRadius. 
4. Create a prefix and postfix increment operator for your SimpleCircle class that increments 
itsRadius. 
5. Provide a copy constructor for SimpleCircle. 
6. Provide an assignment operator for SimpleCircle. 
7. Write a program that creates two SimpleCircle objects. Use the default constructor on one and 
instantiate the other with the value 9. Call the increment operator on each and then print their 
values. Finally, assign the second to the first and print its values.*/
_________________________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
 
class SimpleCircle { 
private: 
    int itsRadius; 
 
public: 
    SimpleCircle() { 
        itsRadius = 5; 
    } 
 
    SimpleCircle(int radius) { 
        itsRadius = radius; 
    } 
    ~SimpleCircle() {} 
 
    int getRadius() { 
        return itsRadius; 
    } 
 
    void setRadius(int radius) { 
        itsRadius = radius; 
    } 
 
    SimpleCircle(const SimpleCircle &circle) { 
        itsRadius = circle.itsRadius; 
    } 
 
    SimpleCircle& operator=(const SimpleCircle &circle) { 
        if (this != &circle) { 
            itsRadius = circle.itsRadius; 
        } 
        return *this; 
    } 
 
    SimpleCircle& operator++() { 
        ++itsRadius; 
        return *this; 
    } 
 
    SimpleCircle operator++(int) { 
        SimpleCircle temp = *this; 
        itsRadius++; 
        return temp; 
    } 
 
    void display() { 
        cout << "Radius: " << itsRadius << endl; 
    } 
}; 
 
int main() { 
    int userRadius; 
 
    SimpleCircle circle1; 
  cout << "Default Circle 1 created with radius 5." << endl; 
  cout << "Enter radius for Circle 2: "; 
  cin >> userRadius; 
  
  SimpleCircle circle2(userRadius); 
  cout << "\nBefore increment:" << endl; 
  cout << "Circle 1: "; circle1.display(); 
  cout << "Circle 2: "; circle2.display(); 
  ++circle1;      // Prefix increment 
  circle2++;      // Postfix increment
  
  cout << "\nAfter increment:" << endl; 
  cout << "Circle 1 (prefix ++): "; circle1.display(); 
  cout << "Circle 2 (postfix ++): "; circle2.display(); 
  circle1 = circle2; 
 
  cout << "\nAfter assignment (circle1 = circle2):" << endl; 
  cout << "Circle 1: "; circle1.display(); 
  cout << "Circle 2: "; circle2.display(); 
return 0; 
}
