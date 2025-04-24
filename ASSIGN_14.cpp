/*We want to store the information of different vehicles. Create a class named Vehicle with two 
data member named mileage and price. Create its two subclasses 
*Car with data members to store ownership cost, warranty (by years), seating capacity and fuel type 
(diesel or petrol). 
*Bike with data members to store the number of cylinders, number of gears, cooling type(air, liquid 
or oil), wheel type(alloys or spokes) and fuel tank size(in inches).
Make another two subclasses Audi and Ford of Car, each having a data member to store the model 
type. Next, make two subclasses Bajaj and TVS, each having a data member to store the make-type. 
Now, store and print the information of an Audi and a Ford car (i.e. model type, ownership cost, 
warranty, seating capacity, fuel type, mileage and price.) Do the same for a Bajaj and a TVS bike.*/
______________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
 
class Vehicle { 
protected: 
    float mileage; 
    float price; 
 
public: 
    void inputVehicle() { 
        cout << "Enter mileage: "; 
        cin >> mileage; 
        cout << "Enter price: "; 
        cin >> price; 
    } 
 
    void displayVehicle() { 
        cout << "Mileage: " << mileage << " km/l\n"; 
        cout << "Price: $" << price << endl; 
    } 
}; 
 
class Car : public Vehicle { 
protected: 
    float ownershipCost; 
    int warrantyYears; 
    int seatingCapacity; 
    char fuelType[10]; // diesel or petrol 
 
public: 
    void inputCar() { 
        inputVehicle(); 
        cout << "Enter ownership cost: "; 
        cin >> ownershipCost; 
        cout << "Enter warranty (in years): "; 
        cin >> warrantyYears; 
        cout << "Enter seating capacity: "; 
        cin >> seatingCapacity; 
        cout << "Enter fuel type (diesel/petrol): "; 
        cin >> fuelType; 
    } 
 
    void displayCar() { 
        displayVehicle(); 
        cout << "Ownership Cost: $" << ownershipCost << endl; 
        cout << "Warranty: " << warrantyYears << " years\n"; 
        cout << "Seating Capacity: " << seatingCapacity << endl; 
        cout << "Fuel Type: " << fuelType << endl; 
    } 
}; 
 
class Audi : public Car { 
    char modelType[20]; 
 
public: 
    void inputAudi() { 
        cout << "\n--- Enter Audi Car Info ---\n"; 
        inputCar(); 
        cout << "Enter model type: "; 
        cin >> modelType; 
    } 
 
    void displayAudi() { 
        cout << "\n--- Audi Car Info ---\n"; 
        cout << "Model Type: " << modelType << endl; 
        displayCar(); 
    } 
}; 
 
class Ford : public Car { 
    char modelType[20]; 
 
public: 
    void inputFord() { 
        cout << "\n--- Enter Ford Car Info ---\n"; 
        inputCar(); 
        cout << "Enter model type: "; 
        cin >> modelType; 
    } 
 
    void displayFord() { 
        cout << "\n--- Ford Car Info ---\n"; 
        cout << "Model Type: " << modelType << endl; 
        displayCar(); 
    } 
}; 
 
 
class Bike : public Vehicle { 
protected: 
    int numCylinders; 
    int numGears; 
    char coolingType[10];    
    char wheelType[10];      
    float fuelTankSize; 
 
public: 
    void inputBike() { 
        inputVehicle(); 
        cout << "Enter number of cylinders: "; 
        cin >> numCylinders; 
        cout << "Enter number of gears: "; 
        cin >> numGears; 
        cout << "Enter cooling type (air/liquid/oil): "; 
        cin >> coolingType; 
        cout << "Enter wheel type (alloys/spokes): "; 
        cin >> wheelType; 
        cout << "Enter fuel tank size (in inches): "; 
        cin >> fuelTankSize; 
    } 
 
    void displayBike() { 
        displayVehicle(); 
        cout << "Cylinders: " << numCylinders << ", Gears: " << numGears << endl; 
        cout << "Cooling Type: " << coolingType << ", Wheel Type: " << wheelType << endl; 
        cout << "Fuel Tank Size: " << fuelTankSize << " inches\n"; 
    } 
}; 
 
class Bajaj : public Bike { 
    char makeType[20]; 
 
public: 
    void inputBajaj() { 
        cout << "\n--- Enter Bajaj Bike Info ---\n"; 
        inputBike(); 
        cout << "Enter make type: "; 
        cin >> makeType; 
    } 
 
    void displayBajaj() { 
        cout << "\n--- Bajaj Bike Info ---\n"; 
        cout << "Make Type: " << makeType << endl; 
        displayBike(); 
    } 
}; 
 
class TVS : public Bike { 
    char makeType[20]; 
 
public: 
    void inputTVS() { 
        cout << "\n--- Enter TVS Bike Info ---\n"; 
        inputBike(); 
        cout << "Enter make type: "; 
        cin >> makeType; 
    } 
 
    void displayTVS() { 
        cout << "\n--- TVS Bike Info ---\n"; 
        cout << "Make Type: " << makeType << endl; 
        displayBike(); 
    } 
}; 
 
int main() { 
    Audi a; 
    Ford f; 
    Bajaj b; 
    TVS t; 
 
    a.inputAudi(); 
    f.inputFord(); 
    b.inputBajaj(); 
    t.inputTVS(); 
 
    a.displayAudi(); 
    f.displayFord(); 
    b.displayBajaj(); 
    t.displayTVS(); 
return 0; 
}
