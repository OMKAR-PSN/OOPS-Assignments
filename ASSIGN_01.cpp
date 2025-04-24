/*1. Assume that a bank maintains two kinds of accounts for customers, one called as savings and the 
other as current account. The savings account provides compound interest and withdrawal facilities 
but no chequebook facility. The current account provides cheque book facility but no interest. 
Current account holders should also maintain a minimum balance and if the balance falls below this level a 
service charge is imposed. Create a class account that stores customer name, account number and 
type of account. From this derive the classes cur_acct and sav_acct to make them more specific to their 
requirements. Include necessary member functions in order to achieve the following tasks: 
(a) Accept the deposit from a customer and update the balance. 
(b) Display the balance. 
(c) Compute and deposit interest. 
(d) Permit withdrawal and update the balance. 
(e) Check for the minimum balance, impose penalty, necessary and update the balance. 
Do not use any constructors. Use member functions to initialize class members.*/ 


#include <iostream> 
using namespace std; 
class Account { 
protected: 
char customerName[50]; 
int accountNumber; 
char accountType[10]; 
double balance; 
public: 
    void initialize() { 
        cout << "Enter customer name: "; 
        cin.ignore(); // clear input buffer before getline-style input 
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
        savings.initialize(); 
        savings.deposit(); 
        savings.computeAndDepositInterest(); 
        savings.withdraw(); 
        savings.displayBalance(); 
    } else if (type == 'C' || type == 'c') { 
        CurAcct current; 
        current.initialize(); 
        current.deposit(); 
        current.withdraw(); 
        current.displayBalance(); 
    } else { 
        cout << "Invalid account type selected.\n"; 
    } 
return 0; 
}
