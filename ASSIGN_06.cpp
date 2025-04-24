/*Create two classes DM and DB which store the value of distances. DM stores distance in meters 
and centimeters and DB in feet and inches. Write a program that can read values for the class 
objects and add one object of DM with another object of DB. Use a friend function to carry out the addition 
operation. The object that stores the results may be a DM object or DB object, depending on the 
units in which the results are required. The display should be in the format of feet and inches or meters 
and centimeters depending on the object on display.*/
_________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
 
class DB; 
 
class DM { 
private: 
    int meters; 
    int centimeters; 
 
public: 
    DM() { 
        meters = 0; 
        centimeters = 0; 
    } 
 
    void read() { 
        cout << "Enter distance in meters and centimeters:\n"; 
        cout << "Meters: "; 
        cin >> meters; 
        cout << "Centimeters: "; 
        cin >> centimeters; 
    } 
 
    void display() const { 
        cout << "Distance: " << meters << " meters " << centimeters << " centimeters\n"; 
    } 
 
    friend DM add(const DM& d1, const DB& d2); // Friend function 
}; 
 
class DB { 
private: 
    int feet; 
    int inches; 
 
public: 
    DB() { 
        feet = 0; 
        inches = 0; 
    } 
 
    void read() { 
        cout << "Enter distance in feet and inches:\n"; 
        cout << "Feet: "; 
        cin >> feet; 
        cout << "Inches: "; 
        cin >> inches; 
    } 
 
    void display() const { 
cout << "Distance: " << feet << " feet " << inches << " inches\n"; 
} 
friend DM add(const DM& d1, const DB& d2); // Same friend function 
}; 
DM add(const DM& d1, const DB& d2) { 
  float total_cm_d1 = d1.meters * 100 + d1.centimeters; 
  float total_cm_d2 = d2.feet * 30.48 + d2.inches * 2.54; 
  float total_cm = total_cm_d1 + total_cm_d2; 
  
  DM result; 
  result.meters = static_cast<int>(total_cm) / 100; 
  result.centimeters = static_cast<int>(total_cm) % 100; 
return result; 
} 

int main() { 
DM d1, result_dm; 
DB d2; 
cout << "--- Input for DM Object ---\n"; 
d1.read(); 
cout << "\n--- Input for DB Object ---\n"; 
d2.read(); 
result_dm = add(d1, d2); 
cout << "\n--- Result in Meters and Centimeters ---\n"; 
result_dm.display(); 
return 0; 
}
