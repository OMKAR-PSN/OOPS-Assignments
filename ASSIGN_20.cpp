/*Suppose you have a Piggie Bank with an initial amount of $50 and you have to add some more 
amount to it. Create a class 'AddAmount' with a data member named 'amount' with an initial value 
of $50. Now make two constructors of this class as follows: 
        1 - without any parameter - no amount will be added to the Piggie Bank 
        2 - having a parameter which is the amount that will be added to the Piggie Bank 
Create an object of the 'AddAmount' class and display the final amount in the Piggie Bank.*/
_________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
class AddAmount { 
private: 
    float amount; 
 
public: 
    AddAmount() { 
        amount = 50.0;  // Initial amount is $50 
    } 
    AddAmount(float addedAmount) { 
        amount = 50.0 + addedAmount;  // Initial amount + added amount 
    } 
    void displayAmount() { 
        cout << "Final amount in the Piggie Bank: $" << amount << endl; 
    } 
}; 
 
int main() { 
  float addedAmount; 
  
  AddAmount bank1; 
  bank1.displayAmount();  // Display initial amount of $50 
  cout << "Enter the amount to add to the Piggie Bank: $"; 
  cin >> addedAmount; 
  
  AddAmount bank2(addedAmount); 
  bank2.displayAmount();   
    
  return 0; 
}
