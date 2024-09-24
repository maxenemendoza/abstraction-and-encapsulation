#include <iostream>
#include <iomanip>
using namespace std;

class SubMenu { // base class
    public:
    // pure virtual functions
    virtual void deposit() = 0; 
    virtual void withdraw() = 0; 
    virtual void checkBalance() = 0; 
    virtual void displaySubMenu() = 0; 
};

// validates only for numbers
bool isNumber(const string &str) {
    for (char const &c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

class SavingsAccount : public SubMenu { // derived class for savings
    private: 
    int subChoice;
    double balance; 
    double depositAmount;
    double withdrawAmount;

    public:
    SavingsAccount() : balance(1000), depositAmount(0), withdrawAmount(0) {}; // constructor for initialization

    void deposit() override {
        cout << "Balance: Php " << fixed << setprecision(2) << balance << endl;
        cout << "Enter amount to be deposited: Php ";
        cin >> depositAmount;

        if (depositAmount > 0){
            balance += depositAmount;

            cout << "You have successfully deposited Php " << fixed << setprecision(2) << depositAmount << " to your Savings Account." << endl;
            cout << "New Balance: Php " << balance << endl;
        }
        else {
            cout << "Failed to deposit Php " << fixed << setprecision(2) << depositAmount << " to your Savings Account." << endl;
            cout << "Please enter a valid amount." << endl;
        }
    }

    void withdraw() override {
        cout << "Balance: Php "<< fixed << setprecision(2) << balance << endl;
        cout << "Enter amount to be withdrawn: Php ";
        cin >> withdrawAmount;

        if (withdrawAmount > 0 && withdrawAmount <= balance){
            balance -= withdrawAmount;

            cout << "You have successfully withdrawn Php " << fixed << setprecision(2) << withdrawAmount << " from your Savings Account." << endl;
            cout << "New Balance: Php " << balance << endl;
        }
        else {
            cout << "Failed to withdraw Php " << fixed << setprecision(2) << withdrawAmount << " from your Savings Account." << endl;
            cout << "Please enter a valid amount." << endl;
        }
    }

    void checkBalance() override {
        cout << "Balance: Php " << fixed << setprecision(2) << balance << endl;
    }

    void displaySubMenu() override { 
        do {
            cout << "Sub Menu for Savings Account" << endl;
            cout << "1 - Deposit" << endl;
            cout << "2 - Withdraw" << endl;
            cout << "3 - Check Balance" << endl;
            cout << "4 - Back" << endl;
            cout << "Enter choice: ";
            cin >> subChoice;

            switch (subChoice){
                case 1:
                deposit();
                break; // return to current sub menu

                case 2:
                withdraw();
                break; // return to current sub menu

                case 3:
                checkBalance();
                break; // return to current sub menu

                case 4:
                return; // return to main menu

                default:
                cout << "Invalid input! Try again." << endl;
            }
        } while (subChoice != 4);
    }
};

class CurrentAccount : public SubMenu { // derived class for current
    private: 
    int subChoice;
    double balance; 
    double depositAmount;
    double withdrawAmount;

    public:
    CurrentAccount() : balance(0), depositAmount(0), withdrawAmount(0) {};

    void deposit() override {
        cout << "Balance: Php " << fixed << setprecision(2) << balance << endl;
        cout << "Enter amount to be deposited: Php ";
        cin >> depositAmount;

        if (depositAmount > 0){
            balance += depositAmount;

            cout << "You have successfully deposited Php " << fixed << setprecision(2) << depositAmount << " to your Current Account." << endl;
            cout << "New Balance: Php " << balance << endl;
        }
        else {
            cout << "Failed to deposit Php " << fixed << setprecision(2) << depositAmount << " to your Current Account." << endl;
            cout << "Please enter a valid amount." << endl;
        }
    }

    void withdraw() override {
        cout << "Balance: Php "<< fixed << setprecision(2) << balance << endl;
        cout << "Enter amount to be withdrawn: Php ";
        cin >> withdrawAmount;

        if (withdrawAmount > 0 && withdrawAmount <= balance){
            balance -= withdrawAmount;

            cout << "You have successfully withdrawn Php " << fixed << setprecision(2) << withdrawAmount << " from your Current Account." << endl;
            cout << "New Balance: Php " << balance << endl;
        }
        else {
            cout << "Failed to withdraw Php " << fixed << setprecision(2) << withdrawAmount << " from your Current Account." << endl;
            cout << "Please enter a valid amount." << endl;
        }
    }

    void checkBalance() override {
        cout << "Balance: Php " << fixed << setprecision(2) << balance << endl;
    }

    void displaySubMenu() override { 
        do {
            cout << "Sub Menu for Current Account" << endl;
            cout << "1 - Deposit" << endl;
            cout << "2 - Withdraw" << endl;
            cout << "3 - Check Balance" << endl;
            cout << "4 - Back" << endl;
            cout << "Enter choice: ";
            cin >> subChoice;

            switch (subChoice){
                case 1:
                deposit();
                break; // return to current sub menu

                case 2:
                withdraw();
                break; // return to current sub menu

                case 3:
                checkBalance();
                break; // return to current sub menu

                case 4:
                return; // return to main menu

                default:
                cout << "Invalid input! Try again." << endl;
            }
        } while (subChoice != 4);
    }
};

int main (){
    int menuChoice;
    SavingsAccount savings; 
    CurrentAccount current;

    do {
        cout << "Main Menu" << endl;
        cout << "1 - Savings Account" << endl;
        cout << "2 - Current Account" << endl;
        cout << "3 - Exit" << endl;
        cout << "Enter choice: ";
        cin >> menuChoice;

        switch (menuChoice){
            case 1:
            savings.displaySubMenu();
            break; // return to main menu

            case 2:
            current.displaySubMenu();
            break; // return to main menu

            case 3:
            cout << "Thank you for banking with us!" << endl;
            break; 

            default:
            cout << "Invalid input. Try again!" << endl;
        }
    } while (menuChoice != 3);
    
    return 0;
}