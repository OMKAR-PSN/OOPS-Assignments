/*Write a program to print the names of students by creating a Student class. If no name is passed 
while creating an object of the Student class, then the name should be "Unknown", otherwise the 
name should be equal to the String value passed while creating the object of the Student class.*/
______________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
 
class Student { 
private: 
    char name[100];   
 
public: 
    Student(const char* studentName = "Unknown") { 
         
        int i = 0; 
        while (studentName[i] != '\0' && i < 99) { 
            name[i] = studentName[i]; 
            i++; 
        } 
        name[i] = '\0';   
    } 
 
        void display() { 
        cout << "Student Name: " << name << endl; 
    } 
}; 
 
int main() { 
    Student student1("John Doe");   
    Student student2;               
 
     
    student1.display(); 
    student2.display(); 
 
    return 0; 
}
