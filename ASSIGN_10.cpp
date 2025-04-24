/*1. Write the code that declares a class called Employee with these data members: age, 
yearsOfService and Salary. 
2. Rewrite the Employee class to make the data members private, and provide public accessor 
methods to get and set each of the data members. 
3. Write a program with the Employee class that makes two Employees; sets their age, 
YearsOfService, and Salary; and prints their values. 
4. Continuing from assignment 3, provide a method of Employee that reports how many thousands of 
dollars the employee earns, rounded to the nearest 1,000. 
5. Change the Employee class so that you can initialize age, YearsOfService, and Salary when you 
create the employee.*/
________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
 
class Employee { 
private: 
    int age; 
    int yearsOfService; 
    double salary; 
 
public: 
    Employee(int a, int y, double s) { 
        age = a; 
        yearsOfService = y; 
        salary = s; 
    } 
 
    Employee() { 
        age = 0; 
        yearsOfService = 0; 
        salary = 0.0; 
    } 
 
    void setAge(int a) { 
        age = a; 
    } 
 
    void setYearsOfService(int y) { 
        yearsOfService = y; 
    } 
 
    void setSalary(double s) { 
        salary = s; 
    } 
 
    int getAge() const { 
        return age; 
    } 
 
    int getYearsOfService() const { 
        return yearsOfService; 
    } 
 
    double getSalary() const { 
        return salary; 
    } 
 
    int getSalaryInThousands() const { 
        return static_cast<int>((salary + 500) / 1000); // round to nearest 1000 
    } 
 
    void printDetails() const { 
        cout << "Age: " << age << "\n"; 
        cout << "Years of Service: " << yearsOfService << "\n"; 
        cout << "Salary: $" << salary << "\n"; 
        cout << "Rounded Salary (Thousands): $" << getSalaryInThousands() << "000\n"; 
        cout << "----------------------\n"; 
    } 
}; 
 
int main() { 
  Employee emp1, emp2; 
  int age, service; 
  double salary; 
  
  cout << "Enter details for Employee 1:\n"; 
  cout << "Age: "; 
  cin >> age; 
  cout << "Years of Service: "; 
  cin >> service; 
  cout << "Salary: "; 
  cin >> salary; 
  emp1 = Employee(age, service, salary);   
  
  cout << "\nEnter details for Employee 2:\n"; 
  cout << "Age: "; 
  cin >> age; 
  cout << "Years of Service: "; 
  cin >> service; 
  cout << "Salary: "; 
  cin >> salary; 
  emp2 = Employee(age, service, salary); 
  
  cout << "\n--- Employee 1 ---\n"; 
  emp1.printDetails(); 
  cout << "--- Employee 2 ---\n"; 
  emp2.printDetails(); 
return 0; 
}
