/*All the banks operating in India are controlled by RBI. RBI has set a well defined guideline (e.g. 
minimum interest rate, minimum balance allowed, maximum withdrawal limit etc) which all banks 
must follow. For example, suppose RBI has set minimum interest rate applicable to a saving bank 
account to be 4% annually; however, banks are free to use 4% interest rate or to set any rates above 
it.*/
________________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
class RBI { 
protected: 
    float minInterestRate; 
    float minBalance; 
    float maxWithdrawalLimit; 
 
public: 
    RBI() { 
        minInterestRate = 4.0;       // Minimum interest rate in % 
        minBalance = 1000.0;         // Minimum balance in ₹ 
        maxWithdrawalLimit = 25000;  // Maximum withdrawal in ₹ 
    } 
 
    void showRBIRules() { 
        cout << "\n--- RBI Guidelines ---\n"; 
        cout << "Minimum Interest Rate: " << minInterestRate << "%\n"; 
        cout << "Minimum Balance: ₹" << minBalance << endl; 
        cout << "Maximum Withdrawal Limit: ₹" << maxWithdrawalLimit << endl; 
    } 
 
    float getMinInterest() { return minInterestRate; } 
    float getMinBalance() { return minBalance; } 
    float getMaxWithdrawal() { return maxWithdrawalLimit; } 
}; 
class SBI : public RBI { 
    float interestRate; 
    float minBalanceBank; 
    float withdrawalLimit; 
 
public: 
    void inputPolicies() { 
        cout << "\nEnter SBI Bank Policies:\n"; 
        cout << "Enter interest rate (%): "; 
        cin >> interestRate; 
        cout << "Enter minimum balance (₹): "; 
        cin >> minBalanceBank; 
        cout << "Enter maximum withdrawal limit (₹): "; 
        cin >> withdrawalLimit; 
    } 
 
    void showPolicies() { 
        cout << "\n--- SBI Bank Policies ---\n"; 
        cout << "Interest Rate: " << interestRate << "%\n"; 
        cout << "Minimum Balance: ₹" << minBalanceBank << endl; 
        cout << "Withdrawal Limit: ₹" << withdrawalLimit << endl; 
 
        cout << "\nPolicy Compliance Check:\n"; 
        if (interestRate >= getMinInterest()) 
            cout << "✔ Interest rate follows RBI guidelines.\n"; 
        else 
            cout << "✘ Interest rate is below RBI minimum.\n"; 
 
        if (minBalanceBank >= getMinBalance()) 
            cout << "✔ Minimum balance follows RBI guidelines.\n"; 
        else 
            cout << "✘ Minimum balance is below RBI requirement.\n"; 
 
        if (withdrawalLimit <= getMaxWithdrawal()) 
            cout << "✔ Withdrawal limit follows RBI guidelines.\n"; 
        else 
            cout << "✘ Withdrawal limit exceeds RBI maximum.\n"; 
    } 
}; 
 
class ICICI : public RBI { 
    float interestRate; 
    float minBalanceBank; 
    float withdrawalLimit; 
 
public: 
    void inputPolicies() { 
        cout << "\nEnter ICICI Bank Policies:\n"; 
        cout << "Enter interest rate (%): "; 
        cin >> interestRate; 
        cout << "Enter minimum balance (₹): "; 
        cin >> minBalanceBank; 
        cout << "Enter maximum withdrawal limit (₹): "; 
        cin >> withdrawalLimit; 
    } 
 
    void showPolicies() { 
        cout << "\n--- ICICI Bank Policies ---\n"; 
        cout << "Interest Rate: " << interestRate << "%\n"; 
        cout << "Minimum Balance: ₹" << minBalanceBank << endl; 
        cout << "Withdrawal Limit: ₹" << withdrawalLimit << endl; 
 
        cout << "\nPolicy Compliance Check:\n"; 
        if (interestRate >= getMinInterest()) 
            cout << "✔ Interest rate follows RBI guidelines.\n"; 
        else 
            cout << "✘ Interest rate is below RBI minimum.\n"; 
 
        if (minBalanceBank >= getMinBalance()) 
            cout << "✔ Minimum balance follows RBI guidelines.\n"; 
        else 
            cout << "✘ Minimum balance is below RBI requirement.\n"; 
 
        if (withdrawalLimit <= getMaxWithdrawal()) 
            cout << "✔ Withdrawal limit follows RBI guidelines.\n"; 
        else 
            cout << "✘ Withdrawal limit exceeds RBI maximum.\n"; 
    } 
}; 
 
int main() { 
    RBI rbi; 
    SBI sbi; 
    ICICI icici; 
 
    rbi.showRBIRules(); 
 
    sbi.inputPolicies(); 
    icici.inputPolicies(); 
 
    sbi.showPolicies(); 
    icici.showPolicies(); 
 
    return 0; 
} 
