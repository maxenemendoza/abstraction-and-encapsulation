#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <limits>
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

void clearScreen() {
    system("cls"); // clear screen
}

void pause() {
    system("pause"); // pause screen 
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
        string input;

        do {
            cout << "Enter amount to be deposited: Php ";
            cin >> input;
        } while (!isNumber(input));

        depositAmount = stod(input);  // Convert the validated input to a double

        if (depositAmount > 0){
            balance += depositAmount;
            cout << endl << "You have successfully deposited Php " << fixed << setprecision(2) << depositAmount << " to your Savings Account." << endl;
            cout << "New Balance: Php " << balance << endl;
        }
        else {
            cout << endl << "Failed to deposit Php " << fixed << setprecision(2) << depositAmount << " to your Savings Account." << endl;
            cout << "Note: Enter valid amount only. Amount cannot be 0 or negative." << endl;
        }
        pause();
    }

    void withdraw() override {
        cout << "Balance: Php "<< fixed << setprecision(2) << balance << endl;
        string input;

        do {
            cout << "Enter amount to be withdrawn: Php ";
            cin >> input;
        } while (!isNumber(input)); 

        withdrawAmount = stod(input); 

        if (withdrawAmount > 0 && withdrawAmount <= balance){
            balance -= withdrawAmount;

            cout << endl << "You have successfully withdrawn Php " << fixed << setprecision(2) << withdrawAmount << " from your Savings Account." << endl;
            cout << "New Balance: Php " << balance << endl;
        }
        else {
            cout << endl << "Failed to withdraw Php " << fixed << setprecision(2) << withdrawAmount << " from your Savings Account." << endl;
            cout << "Note: Enter valid amount only. Amount cannot be 0, negative, or greater than balance." << endl;
        }
        pause();
    }

    void checkBalance() override {
        cout << "Balance: Php " << fixed << setprecision(2) << balance << endl;
        pause();
    }

    void displaySubMenu() override { 
        do {
            clearScreen();
            cout << "||========== Sub Menu for Savings Account ==========||" << endl;
            cout << "   1 - Deposit" << endl;
            cout << "   2 - Withdraw" << endl;
            cout << "   3 - Check Balance" << endl;
            cout << "   4 - Back" << endl;
            cout << "||==================================================||" << endl;
            cout << endl;
            cout << "Enter choice: ";
            cin >> subChoice;
            cout << endl;

            // Check if the input is valid (a number)
            if (cin.fail()) { 
                cin.clear(); // Clear the fail state (caused by invalid input)
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Note: Enter a number from 1 to 3 only." << endl;
                pause();
                continue; // Restart the loop
            }

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
                cout << "Returning to Main Menu ... " << endl;
                pause();
                return; // return to main menu

                default:
                cout <<"Note: Enter a number from 1 to 4 only." << endl;
                pause();
            }
        } while (subChoice != 4); // loops until user goes back to main menu
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
        string input;

        do {
            cout << "Enter amount to be deposited: Php ";
            cin >> input;
        } while (!isNumber(input));

        depositAmount = stod(input);  // Convert the validated input to a double

        if (depositAmount > 0){
            balance += depositAmount;

            cout << endl << "You have successfully deposited Php " << fixed << setprecision(2) << depositAmount << " to your Current Account." << endl;
            cout << "New Balance: Php " << balance << endl;
        }
        else {
            cout << endl << "Failed to deposit Php " << fixed << setprecision(2) << depositAmount << " to your Current Account." << endl;
            cout << "Note: Enter valid amount only. Amount cannot be 0 or negative." << endl;
        }
        pause();
    }

    void withdraw() override {
        cout << "Balance: Php "<< fixed << setprecision(2) << balance << endl;
        string input;

        do {
            cout << "Enter amount to be withdrawn: Php ";
            cin >> input;
        } while (!isNumber(input)); 

        withdrawAmount = stod(input); 

        if (withdrawAmount > 0 && withdrawAmount <= balance){
            balance -= withdrawAmount;

            cout << endl << "You have successfully withdrawn Php " << fixed << setprecision(2) << withdrawAmount << " from your Current Account." << endl;
            cout << "New Balance: Php " << balance << endl;
        }
        else {
            cout << endl << "Failed to withdraw Php " << fixed << setprecision(2) << withdrawAmount << " from your Current Account." << endl;
            cout << "Note: Enter valid amount only. Amount cannot be 0, negative, or greater than balance." << endl;
        }
        pause();
    }

    void checkBalance() override {
        cout << "Balance: Php " << fixed << setprecision(2) << balance << endl;
        pause();
    }

    void displaySubMenu() override { 
        do {
            clearScreen();
            cout << "||========== Sub Menu for Current Account ==========||" << endl;
            cout << "   1 - Deposit" << endl;
            cout << "   2 - Withdraw" << endl;
            cout << "   3 - Check Balance" << endl;
            cout << "   4 - Back" << endl;
            cout << "||==================================================||" << endl;
            cout << endl;
            cout << "Enter choice: ";
            cin >> subChoice;
            cout << endl;

            // Check if the input is valid (a number)
            if (cin.fail()) { 
                cin.clear(); // Clear the fail state (caused by invalid input)
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Note: Enter a number from 1 to 3 only." << endl;
                pause();
                continue; // Restart the loop
            }

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
                cout << "Returning to Main Menu ... " << endl;
                pause();
                return; // return to main menu

                default:
                cout << "Note: Enter a number from 1 to 4 only." << endl;
                pause();
            }
        } while (subChoice != 4); // loops until user goes back to main menu
    }
};

int main (){
    int menuChoice;
    SavingsAccount savings; 
    CurrentAccount current;

    do {
        clearScreen();
        cout << "||========== Main Menu ==========||" << endl;
        cout << "   1 - Savings Account" << endl;
        cout << "   2 - Current Account" << endl;
        cout << "   3 - Exit" << endl;
        cout << "||===============================||" << endl;
        cout << endl;
        cout << "Enter choice: ";
        cin >> menuChoice;
        cout << endl;

        // Check if the input is valid (a number)
        if (cin.fail()) { 
            cin.clear(); // Clear the fail state (caused by invalid input)
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Note: Enter a number from 1 to 3 only." << endl;
            pause();
            continue; // Restart the loop
        }

        switch (menuChoice){
            case 1:

            cout << "You have selected Savings Account." << endl;
            pause();
            savings.displaySubMenu();
            break; // return to main menu

            case 2:
            cout << "You have selected Current Account." << endl;
            pause();
            current.displaySubMenu();
            break; // return to main menu

            case 3:
            cout << "Thank you for banking with us!" << endl;
            pause();
            break; 

            default:
            cout << "Note: Enter a number from 1 to 3 only." << endl;
            pause();
        }
    } while (menuChoice != 3); // loops until user exits
    
    return 0;
}