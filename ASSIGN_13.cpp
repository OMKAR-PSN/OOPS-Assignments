/*We want to calculate the total marks of each student of a class in Physics,Chemistry and 
Mathematics and the average marks of the class. The number of students in the class are entered by 
the user. Create a class named Marks with data members for roll number, name and marks. Create three 
other classes inheriting the Marks class, namely Physics, Chemistry and Mathematics, which are used 
to define marks in individual subject of each student. Roll number of each student will be generated 
automatically.*/
________________________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
 
int rollCounter = 1;  // Global counter for roll number generation 
 
class Marks { 
protected: 
    int rollNo; 
    char name[50]; 
 
public: 
    Marks() { 
        rollNo = rollCounter++; 
    } 
 
    void inputName() { 
        cout << "Enter name: "; 
        cin >> name; 
    } 
 
    void displayName() { 
        cout << "Roll No: " << rollNo << ", Name: " << name; 
    } 
 
    int getRollNo() { 
        return rollNo; 
    } 
 
    const char* getName() { 
        return name; 
    } 
}; 
 
class Physics : public Marks { 
protected: 
    int physicsMarks; 
 
public: 
    void inputPhysicsMarks() { 
        inputName(); 
        cout << "Enter Physics marks: "; 
        cin >> physicsMarks; 
    } 
 
    int getPhysicsMarks() { 
        return physicsMarks; 
    } 
}; 
 
class Chemistry : public Physics { 
protected: 
    int chemistryMarks; 
 
public: 
    void inputChemistryMarks() { 
        inputPhysicsMarks(); 
        cout << "Enter Chemistry marks: "; 
        cin >> chemistryMarks; 
    } 
 
    int getChemistryMarks() { 
        return chemistryMarks; 
    } 
}; 
 
class Mathematics : public Chemistry { 
protected: 
    int mathMarks; 
 
public: 
    void inputAllMarks() { 
        inputChemistryMarks(); 
        cout << "Enter Mathematics marks: "; 
        cin >> mathMarks; 
    } 
 
    int getMathMarks() { 
        return mathMarks; 
    } 
 
    int getTotalMarks() { 
        return getPhysicsMarks() + getChemistryMarks() + getMathMarks(); 
    } 
 
    void displayStudentSummary() { 
        displayName(); 
        cout << ", Physics: " << getPhysicsMarks() 
             << ", Chemistry: " << getChemistryMarks() 
             << ", Mathematics: " << getMathMarks() 
             << ", Total: " << getTotalMarks() << endl; 
    } 
}; 
 
int main() { 
    int num; 
    cout << "Enter number of students: "; 
    cin >> num; 
 
    Mathematics students[num]; 
    int totalPhysics = 0, totalChem = 0, totalMath = 0; 
 
    for (int i = 0; i < num; i++) { 
        cout << "\nEntering details for Student " << i + 1 << ":\n"; 
        students[i].inputAllMarks(); 
        totalPhysics += students[i].getPhysicsMarks(); 
        totalChem += students[i].getChemistryMarks(); 
        totalMath += students[i].getMathMarks(); 
    } 
 
    cout << "\n---- Students Summary ----\n"; 
    for (int i = 0; i < num; i++) { 
        students[i].displayStudentSummary(); 
    } 
 
    double avgPhysics = (double)totalPhysics / num; 
    double avgChem = (double)totalChem / num; 
    double avgMath = (double)totalMath / num; 
    double avgTotal = (avgPhysics + avgChem + avgMath); 
 
    cout << "\n--- Class Averages ---\n"; 
    cout << "Physics Average: " << avgPhysics << endl; 
    cout << "Chemistry Average: " << avgChem << endl; 
    cout << "Mathematics Average: " << avgMath << endl; 
    cout << "Overall Average (Total Marks / Student): " << avgTotal << endl; 

  return 0; 
} 
