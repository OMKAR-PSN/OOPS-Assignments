/*Make a class named Fruit with a data member to calculate the number of fruits in a basket. 
Create two other class named Apples and Mangoes to calculate the number of apples and mangoes in the 
basket. Print the number of fruits of each type and the total number of fruits in the basket.*/
________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
 
class Fruit { 
protected: 
    int totalFruits; 
 
public: 
    Fruit() { 
        totalFruits = 0; 
    } 
 
    void addToTotal(int count) { 
        totalFruits += count; 
    } 
 
    void displayTotalFruits() { 
        cout << "Total fruits in basket: " << totalFruits << endl; 
    } 
}; 
 
class Apples : public Fruit { 
private: 
    int numApples; 
 
public: 
    Apples(int n) { 
        numApples = n; 
        addToTotal(n);  // update base class total 
    } 
 
    void displayApples() { 
        cout << "Number of apples: " << numApples << endl; 
    } 
 
    int getAppleCount() { 
        return numApples; 
    } 
}; 
 
class Mangoes : public Fruit { 
private: 
    int numMangoes; 
 
public: 
    Mangoes(int n) { 
        numMangoes = n; 
        addToTotal(n);  // update base class total 
    } 
 
    void displayMangoes() { 
        cout << "Number of mangoes: " << numMangoes << endl; 
    } 
 
    int getMangoCount() { 
        return numMangoes; 
    } 
}; 
 
int main() { 
    int appleCount, mangoCount; 
  
  cout << "Enter number of apples: "; 
  cin >> appleCount; 
  cout << "Enter number of mangoes: "; 
  cin >> mangoCount; 
  
  Apples a(appleCount); 
  Mangoes m(mangoCount); 

  cout << "\n--- Fruit Basket Summary ---\n"; 
  a.displayApples(); 
  m.displayMangoes(); 
  cout << "Total fruits in basket: " << (a.getAppleCount() + m.getMangoCount()) << endl; 
return 0; 
} 
