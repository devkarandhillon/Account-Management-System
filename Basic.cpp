
#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    int accountNumber;
    string accountHolder;
    double balance;
    bool accountCreated;

public:
    // Constructor
    Account()
    {
        accountNumber = 0;
        accountHolder = "";
        balance = 0;
        accountCreated = false;
    }

    // Create a new account
    void createAccount()
    {
        if (accountCreated)
        {
            cout << "\nAccount already exists!\n";
            return;
        }

        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Account Holder Name: ";
        getline(cin >> ws, accountHolder);

        cout << "Enter Opening Balance: ";
        cin >> balance;

        if (balance < 0)
        {
            cout << "Opening balance cannot be negative!\n";
            accountNumber = 0;
            accountHolder = "";
            balance = 0;
            return;
        }

        accountCreated = true;

        cout << "\nAccount created successfully!\n";
    }

    // Deposit money
    void deposit()
    {
        if (!accountCreated)
        {
            cout << "\nPlease create an account first.\n";
            return;
        }

        double amount;

        cout << "\nEnter amount to deposit: ";
        cin >> amount;

        if (amount > 0)
        {
            balance = balance + amount;
            cout << "Money deposited successfully!\n";
        }
        else
        {
            cout << "Please enter a valid amount.\n";
        }
    }

    // Withdraw money
    void withdraw()
    {
        if (!accountCreated)
        {
            cout << "\nPlease create an account first.\n";
            return;
        }

        double amount;

        cout << "\nEnter amount to withdraw: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Please enter a valid amount.\n";
        }
        else if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Money withdrawn successfully!\n";
        }
        else
        {
            cout << "Insufficient balance!\n";
        }
    }

    // Display account details
    void displayAccount()
    {
        if (!accountCreated)
        {
            cout << "\nNo account found. Please create an account first.\n";
            return;
        }

        cout << "\n====== ACCOUNT DETAILS ======\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Current Balance: Rs. " << balance << endl;
        cout << "=============================\n";
    }
};

int main()
{
    Account a;
    int choice;

    do
    {
        cout << "\n===== ACCOUNT MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n";
            return 0;
        }

        switch (choice)
        {
        case 1:
            a.createAccount();
            break;

        case 2:
            a.deposit();
            break;

        case 3:
            a.withdraw();
            break;

        case 4:
            a.displayAccount();
            break;

        case 5:
            cout << "\nThank you for using the system!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}