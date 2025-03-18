#include <iostream>
using namespace std;


void displayMenu();
void checkBalance(double balance);
double depositMoney(double balance);
double withdrawMoney(double balance);

int main() {
    double balance = 0.0; 
    int choice;
    bool running = true;

    while (running) {
        displayMenu(); 
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(balance); 
                break;
            case 2:
                balance = depositMoney(balance); 
                break;
            case 3:
                balance = withdrawMoney(balance); 
                break;
            case 4:
                cout << "\nExiting the system. Thank you!\n" << endl;
                running = false; 
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n" << endl;
        }
    }

    return 0;
}


void displayMenu() {
    cout << "--- Menu ---" << endl;
    cout << "\n1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Exit" << endl;
}


void checkBalance(double balance) {
    cout << "\nYour current balance is: $" << balance << endl << endl;
}


double depositMoney(double balance) {
    double amount;
    cout << "Enter the amount to deposit: $";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "\n$" << amount << " deposited successfully.\n" << endl;
    } else {
        cout << "\nInvalid amount. Deposit failed.\n" << endl;
    }

    return balance;
}


double withdrawMoney(double balance) {
    double amount;
    cout << "Enter the amount to withdraw: $";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "\n$" << amount << " withdrawn successfully.\n" << endl;
    } else if (amount > balance) {
        cout << "\nInsufficient funds. Withdrawal failed.\n" << endl;
    } else {
        cout << "\nInvalid amount. Withdrawal failed.\n" << endl;
    }

    return balance;
}
