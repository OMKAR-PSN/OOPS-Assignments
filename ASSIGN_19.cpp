/*Create a class named 'Rectangle' with two data members- length and breadth and a function to 
calculate the area which is 'length*breadth'. The class has three constructors which are : 
    1 - having no parameter - values of both length and breadth are assigned zero.  
    2 - having two numbers as parameters - the two numbers are assigned as length and breadth respectively. 
    3 - having one number as parameter - both length and breadth are assigned that number. 
Now, create objects of the 'Rectangle' class having none, one and two parameters and print their 
areas.*/
_____________________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
class Rectangle { 
private: 
float length, breadth; 
public: 
Rectangle() { 
length = 0; 
breadth = 0; 
} 
Rectangle(float l, float b) { 
        length = l; 
        breadth = b; 
    } 
    Rectangle(float side) { 
        length = side; 
        breadth = side; 
    } 
 
    float calculateArea() { 
        return length * breadth; 
    } 
 
    void inputDimensions() { 
        cout << "Enter length: "; 
        cin >> length; 
        cout << "Enter breadth: "; 
        cin >> breadth; 
    } 
}; 
 
int main() { 
    float l, b, side; 
 
    Rectangle rect1; 
 
 
    Rectangle rect2; 
    rect2.inputDimensions();   
    cout << "Enter side for square: "; 
    cin >> side; 
    Rectangle rect3(side); 
    cout << "Area of rect1 (default constructor): " << rect1.calculateArea() << endl; 
    cout << "Area of rect2 (user input): " << rect2.calculateArea() << endl; 
    cout << "Area of rect3 (square with side " << side << "): " << rect3.calculateArea() << endl; 

  return 0; 
}
