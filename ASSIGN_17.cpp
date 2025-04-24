/*Write a program to implement bank functionality in the above scenario. Note: Create few classes 
namely Customer, Account, RBI (Base Class) and few derived classes (SBI, ICICI, PNB etc). Assume 
and implement required member variables and functions in each class.*/
_____________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
class RBI { 
protected: 
    float minInterestRate; 
    float minBalance; 
    float maxWithdrawal; 
 
public: 
    RBI() { 
        minInterestRate = 4.0; 
        minBalance = 1000.0; 
        maxWithdrawal = 25000.0; 
    } 
 
    void showRBIRules() { 
        cout << "\n--- RBI Guidelines ---\n"; 
        cout << "Minimum Interest Rate: " << minInterestRate << "%\n"; 
        cout << "Minimum Balance: ₹" << minBalance << endl; 
        cout << "Maximum Withdrawal Limit: ₹" << maxWithdrawal << endl; 
    } 
 
    float getMinInterestRate() { return minInterestRate; } 
    float getMinBalance() { return minBalance; } 
    float getMaxWithdrawal() { return maxWithdrawal; } 
}; 
 
class Customer { 
protected: 
    string name; 
    int age; 
    int customerID; 
 
public: 
    void inputCustomerDetails() { 
        cout << "Enter Customer Name: "; 
        cin >> name; 
        cout << "Enter Age: "; 
        cin >> age; 
        cout << "Enter Customer ID: "; 
        cin >> customerID; 
    } 
 
    void showCustomerDetails() { 
        cout << "\n--- Customer Details ---\n"; 
        cout << "Name: " << name << "\nAge: " << age << "\nCustomer ID: " << customerID << endl; 
    } 
}; 
class Account : public Customer { 
protected: 
    float balance; 
    float interestRate; 
 
public: 
    void createAccount(float irate) { 
        interestRate = irate; 
        cout << "Enter initial deposit amount: ₹"; 
        cin >> balance; 
    } 
 
    void deposit() { 
        float amt; 
        cout << "Enter deposit amount: ₹"; 
        cin >> amt; 
        balance += amt; 
        cout << "New Balance: ₹" << balance << endl; 
    } 
 
    void withdraw(float maxLimit) { 
        float amt; 
        cout << "Enter withdrawal amount: ₹"; 
        cin >> amt; 
        if (amt <= balance && amt <= maxLimit) { 
            balance -= amt; 
            cout << "Withdrawal successful. Remaining Balance: ₹" << balance << endl; 
        } else { 
            cout << "Withdrawal failed! Amount exceeds limit or insufficient balance.\n"; 
        } 
    } 
 
    void showAccount() { 
        cout << "\n--- Account Info ---\n"; 
        cout << "Balance: ₹" << balance << "\nInterest Rate: " << interestRate << "%\n"; 
    } 
 
    float getBalance() { return balance; } 
    float getInterestRate() { return interestRate; } 
}; 
 
class SBI : public RBI, public Account { 
public: 
    void openSBIAccount() { 
        cout << "\nOpening SBI Account\n"; 
        inputCustomerDetails(); 
        createAccount(4.5); // SBI gives 4.5% 
    } 
 
    void checkCompliance() { 
        cout << "\n--- SBI Policy Compliance ---\n"; 
        if (interestRate >= getMinInterestRate()) 
            cout << "✔ Interest rate OK\n"; 
        else 
            cout << "✘ Interest rate below RBI minimum\n"; 
 
        if (balance >= getMinBalance()) 
            cout << "✔ Minimum balance OK\n"; 
        else 
            cout << "✘ Minimum balance not maintained\n"; 
    } 
}; 
 
class ICICI : public RBI, public Account { 
public: 
    void openICICIAccount() { 
        cout << "\nOpening ICICI Account\n"; 
        inputCustomerDetails(); 
        createAccount(5.0); // ICICI gives 5.0% 
    } 
 
    void checkCompliance() { 
        cout << "\n--- ICICI Policy Compliance ---\n"; 
        if (interestRate >= getMinInterestRate()) 
            cout << "✔ Interest rate OK\n"; 
        else 
            cout << "✘ Interest rate below RBI minimum\n"; 
 
        if (balance >= getMinBalance()) 
            cout << "✔ Minimum balance OK\n"; 
        else 
            cout << "✘ Minimum balance not maintained\n"; 
    } 
}; 
class PNB : public RBI, public Account { 
public: 
    void openPNBAccount() { 
        cout << "\nOpening PNB Account\n"; 
        inputCustomerDetails(); 
        createAccount(4.25); // PNB gives 4.25% 
    } 
 
    void checkCompliance() { 
        cout << "\n--- PNB Policy Compliance ---\n"; 
        if (interestRate >= getMinInterestRate()) 
            cout << "✔ Interest rate OK\n"; 
        else 
            cout << "✘ Interest rate below RBI minimum\n"; 
 
        if (balance >= getMinBalance()) 
            cout << "✔ Minimum balance OK\n"; 
        else 
            cout << "✘ Minimum balance not maintained\n"; 
    } 
}; 
 
int main() { 
    int choice; 
    SBI sbi; 
    ICICI icici; 
    PNB pnb; 
 
    cout << "----- Welcome to Bank System -----\n"; 
    cout << "1. Create SBI Account\n"; 
    cout << "2. Create ICICI Account\n"; 
    cout << "3. Create PNB Account\n"; 
    cout << "Enter your choice: "; 
    cin >> choice; 
 
    switch (choice) { 
        case 1: 
            sbi.openSBIAccount(); 
            sbi.showCustomerDetails(); 
            sbi.showAccount(); 
            sbi.deposit(); 
            sbi.withdraw(sbi.getMaxWithdrawal()); 
            sbi.checkCompliance(); 
            break; 
 
        case 2: 
            icici.openICICIAccount(); 
            icici.showCustomerDetails(); 
            icici.showAccount(); 
            icici.deposit(); 
            icici.withdraw(icici.getMaxWithdrawal()); 
            icici.checkCompliance(); 
            break; 
 
        case 3: 
            pnb.openPNBAccount(); 
            pnb.showCustomerDetails(); 
            pnb.showAccount(); 
            pnb.deposit(); 
            pnb.withdraw(pnb.getMaxWithdrawal()); 
            pnb.checkCompliance(); 
            break; 
 
        default: 
            cout << "Invalid choice!" << endl; 
    } 
 
    return 0; 
}
