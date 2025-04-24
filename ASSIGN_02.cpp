/*Modify the program of exercise 1 to include constructors for all three classes.*/
____________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
class Account { 
protected: 
char customerName[50]; 
int accountNumber; 
char accountType[10]; 
    double balance; 
 
public: 
    Account() { 
        cout << "Enter customer name: "; 
        cin.ignore(); // clear buffer 
        cin.getline(customerName, 50); 
 
        cout << "Enter account number: "; 
        cin >> accountNumber; 
 
        cout << "Enter account type (Savings/Current): "; 
        cin >> accountType; 
 
        cout << "Enter initial balance: "; 
        cin >> balance; 
    } 
 
    void deposit() { 
        double amount; 
        cout << "Enter amount to deposit: "; 
        cin >> amount; 
        if (amount > 0) { 
            balance += amount; 
            cout << "Deposited: " << amount << endl; 
        } else { 
            cout << "Invalid deposit amount.\n"; 
        } 
    } 
 
    void displayBalance() const { 
        cout << "Current Balance: " << balance << endl; 
    } 
 
    double getBalance() const { 
        return balance; 
    } 
 
    void withdraw(double amount) { 
        if (amount > 0 && amount <= balance) { 
            balance -= amount; 
            cout << "Withdrawn: " << amount << endl; 
        } else { 
            cout << "Invalid withdrawal amount or insufficient balance.\n"; 
        } 
    } 
}; 
 
// Savings Account 
class SavAcct : public Account { 
public: 
    SavAcct() : Account() { 
        // Constructor of base class handles initialization 
    } 
 
    void computeAndDepositInterest() { 
        double rate; 
        int years; 
        cout << "Enter interest rate (%): "; 
        cin >> rate; 
        cout << "Enter number of years: "; 
        cin >> years; 
 
        double interest = balance; 
        for (int i = 0; i < years; ++i) { 
            interest += (interest * rate / 100.0); 
        } 
        double earned = interest - balance; 
        balance = interest; 
 
        cout << "Interest of " << earned << " added. New balance: " << balance << endl; 
    } 
 
    void withdraw() { 
        double amount; 
        cout << "Enter amount to withdraw: "; 
        cin >> amount; 
        Account::withdraw(amount); 
    } 
}; 
 
// Current Account 
class CurAcct : public Account { 
    const double minBalance = 500.0; 
    const double serviceCharge = 50.0; 
 
public: 
    CurAcct() : Account() { 
        // Constructor of base class handles initialization 
    } 
 
    void checkMinBalance() { 
        if (balance < minBalance) { 
            balance -= serviceCharge; 
            cout << "Balance below minimum. Service charge of " << serviceCharge << " imposed.\n"; 
        } else { 
            cout << "Minimum balance maintained.\n"; 
        } 
    } 
 
    void withdraw() { 
        double amount; 
        cout << "Enter amount to withdraw: "; 
        cin >> amount; 
        if (amount > 0 && amount <= balance) { 
            balance -= amount; 
            cout << "Withdrawn: " << amount << endl; 
            checkMinBalance(); 
        } else { 
            cout << "Invalid withdrawal amount or insufficient balance.\n"; 
        } 
    } 
}; 
 
int main() { 
    char type; 
    cout << "Select account type (S for Savings, C for Current): "; 
    cin >> type; 
 
    if (type == 'S' || type == 's') { 
        SavAcct savings; 
        savings.deposit(); 
        savings.computeAndDepositInterest(); 
        savings.withdraw(); 
        savings.displayBalance(); 
    } else if (type == 'C' || type == 'c') { 
        CurAcct current; 
        current.deposit(); 
        current.withdraw(); 
        current.displayBalance(); 
    } else { 
        cout << "Invalid account type selected.\n"; 
    } 
 
    return 0; 
} 
