 /*An educational institution wishes to maintain a database of its employees. The database is divided 
into several classes whose hierarchical relationships are shown in following figure. The figure also shows 
the minimum information required for each class. Specify all classes and define functions to create 
the database and retrieve individual details as and when needed.*/ 
________________________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
 
class Employee { 
protected: 
    int empID; 
    char name[50]; 
    char address[100]; 
 
public: 
    void getEmployeeDetails() { 
        cout << "Enter Employee ID: "; 
        cin >> empID; 
        cin.ignore();  // flush newline 
        cout << "Enter Name: "; 
        cin.getline(name, 50); 
        cout << "Enter Address: "; 
        cin.getline(address, 100); 
    } 
 
    void showEmployeeDetails() const { 
        cout << "Employee ID: " << empID << endl; 
        cout << "Name: " << name << endl; 
        cout << "Address: " << address << endl; 
    } 
}; 
class Teaching : public Employee { 
protected: 
    char subject[30]; 
    char qualification[50]; 
 
public: 
    void getTeachingDetails() { 
        getEmployeeDetails(); 
        cout << "Enter Subject: "; 
        cin.getline(subject, 30); 
        cout << "Enter Qualification: "; 
        cin.getline(qualification, 50); 
    } 
 
    void showTeachingDetails() const { 
        showEmployeeDetails(); 
        cout << "Subject: " << subject << endl; 
        cout << "Qualification: " << qualification << endl; 
    } 
}; 
 
class Professor : public Teaching { 
    char designation[30]; 
    char researchArea[50]; 
 
public: 
    void getProfessorDetails() { 
        getTeachingDetails(); 
        cout << "Enter Designation: "; 
        cin.getline(designation, 30); 
        cout << "Enter Research Area: "; 
        cin.getline(researchArea, 50); 
    } 
 
    void showProfessorDetails() const { 
        showTeachingDetails(); 
        cout << "Designation: " << designation << endl; 
        cout << "Research Area: " << researchArea << endl; 
    } 
}; 
 
class NonTeaching : public Employee { 
    char department[30]; 
    char duty[50]; 
 
public: 
    void getNonTeachingDetails() { 
        getEmployeeDetails(); 
        cout << "Enter Department: "; 
        cin.getline(department, 30); 
        cout << "Enter Duty: "; 
        cin.getline(duty, 50); 
    } 
 
    void showNonTeachingDetails() const { 
        showEmployeeDetails(); 
        cout << "Department: " << department << endl; 
        cout << "Duty: " << duty << endl; 
    } 
}; 
 
class Admin : public Employee { 
    char role[30]; 
    int officeNo; 
 
public: 
    void getAdminDetails() { 
        getEmployeeDetails(); 
        cout << "Enter Role: "; 
        cin.getline(role, 30); 
        cout << "Enter Office Number: "; 
        cin >> officeNo; 
    } 
 
    void showAdminDetails() const { 
        showEmployeeDetails(); 
        cout << "Role: " << role << endl; 
        cout << "Office No: " << officeNo << endl; 
    } 
}; 
 
int main() { 
    int choice; 
    cout << "Select Employee Type:\n"; 
    cout << "1. Professor\n"; 
    cout << "2. Non-Teaching\n"; 
    cout << "3. Admin\n"; 
    cout << "Enter your choice: "; 
    cin >> choice; 
 
    switch (choice) { 
        case 1: { 
            Professor prof; 
            prof.getProfessorDetails(); 
            cout << "\n--- Professor Details ---\n"; 
            prof.showProfessorDetails(); 
            break; 
        } 
        case 2: { 
            NonTeaching nt; 
            nt.getNonTeachingDetails(); 
            cout << "\n--- Non-Teaching Staff Details ---\n"; 
            nt.showNonTeachingDetails(); 
            break; 
        } 
        case 3: { 
            Admin ad; 
            ad.getAdminDetails(); 
            cout << "\n--- Admin Staff Details ---\n"; 
            ad.showAdminDetails(); 
            break; 
        } 
        default: 
            cout << "Invalid choice.\n"; 
    } 
 
    return 0; 
} 
