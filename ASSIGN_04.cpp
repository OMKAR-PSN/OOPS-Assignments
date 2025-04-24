/*Consider a class network of the following figure. The class master derives information from both 
account and admin classes which in turn derives information from the class person. Define all the 
four classes and write a program to create, update and display the information contained in master 
objects.*/ 
_______________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
class Person { 
protected: 
    char name[50]; 
    int code; 
 
public: 
    void getPerson() { 
        cout << "Enter name: "; 
        cin.ignore(); 
        cin.getline(name, 50); 
        cout << "Enter code: "; 
        cin >> code; 
    } 
 
    void showPerson() const { 
        cout << "Name: " << name << endl; 
        cout << "Code: " << code << endl; 
    } 
}; 
class Account : virtual public Person { 
protected: 
    float pay; 
 
public: 
    void getAccount() { 
        cout << "Enter pay: "; 
        cin >> pay; 
    } 
 
    void showAccount() const { 
        cout << "Pay: " << pay << endl; 
    } 
}; 
 
class Admin : virtual public Person { 
protected: 
    int experience; 
 
public: 
    void getAdmin() { 
        cout << "Enter experience (in years): "; 
        cin >> experience; 
    } 
 
    void showAdmin() const { 
        cout << "Experience: " << experience << " years" << endl; 
    } 
}; 
class Master : public Account, public Admin { 
public: 
    void create() { 
        getPerson(); 
        getAccount(); 
        getAdmin(); 
    } 
 
    void update() { 
        cout << "\n--- Update Data ---\n"; 
        create(); // just re-enter all info for simplicity 
    } 
 
    void display() const { 
        cout << "\n--- Displaying Master Information ---\n"; 
        showPerson(); 
        showAccount(); 
        showAdmin(); 
    } 
}; 
 
int main() { 
    Master m; 
    int choice; 
 
    do { 
        cout << "\nMenu:\n"; 
        cout << "1. Create Record\n"; 
        cout << "2. Update Record\n"; 
        cout << "3. Display Record\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                m.create(); 
                break; 
            case 2: 
                m.update(); 
                break; 
            case 3: 
                m.display(); 
                break; 
            case 4: 
                cout << "Exiting program.\n"; 
                break; 
            default: 
                cout << "Invalid choice.\n"; 
        } 
 
    } while (choice != 4); 
 
    return 0; 
}
