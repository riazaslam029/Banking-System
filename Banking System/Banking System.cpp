#include <iostream>
#include <string>
using namespace std;

const int MAX_CUSTOMERS = 50;
const int MAX_TRANSACTIONS = 100;

class Transaction {
public:
    string type;     // Deposit, Withdraw, Transfer
    double amount;
    string details;  // Extra info (e.g., "to account 102")

    Transaction() : type(""), amount(0), details("") {}
    Transaction(string t, double a, string d) : type(t), amount(a), details(d) {}
};

class Account {
public:
    int accountNumber;
    double balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;

    Account() : accountNumber(0), balance(0), transactionCount(0) {}

    void deposit(double amount) {
        balance += amount;
        if (transactionCount < MAX_TRANSACTIONS) {
            transactions[transactionCount++] = Transaction("Deposit", amount, "");
        }
        cout << "✅ Deposit successful! New Balance: " << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "❌ Insufficient balance!\n";
            return;
        }
        balance -= amount;
        if (transactionCount < MAX_TRANSACTIONS) {
            transactions[transactionCount++] = Transaction("Withdraw", amount, "");
        }
        cout << "✅ Withdrawal successful! New Balance: " << balance << "\n";
    }

    void transfer(Account& receiver, double amount) {
        if (amount > balance) {
            cout << "❌ Insufficient balance for transfer!\n";
            return;
        }
        balance -= amount;
        receiver.balance += amount;

        if (transactionCount < MAX_TRANSACTIONS) {
            transactions[transactionCount++] = Transaction("Transfer Out", amount, "To Acc " + to_string(receiver.accountNumber));
        }
        if (receiver.transactionCount < MAX_TRANSACTIONS) {
            receiver.transactions[receiver.transactionCount++] = Transaction("Transfer In", amount, "From Acc " + to_string(accountNumber));
        }
        cout << "✅ Transfer successful! Your Balance: " << balance << "\n";
    }

    void showTransactions() {
        cout << "\n--- Transaction History (Acc " << accountNumber << ") ---\n";
        for (int i = 0; i < transactionCount; i++) {
            cout << i + 1 << ". " << transactions[i].type
                << " - " << transactions[i].amount
                << " " << transactions[i].details << "\n";
        }
    }
};

class Customer {
public:
    string name;
    int customerID;
    Account account;

    Customer() : name(""), customerID(0) {}
    Customer(string n, int id, int accNum, double initDeposit) {
        name = n;
        customerID = id;
        account.accountNumber = accNum;
        account.balance = initDeposit;
    }

    void showInfo() {
        cout << "\n--- Customer Info ---\n";
        cout << "Customer ID: " << customerID << "\n";
        cout << "Name: " << name << "\n";
        cout << "Account Number: " << account.accountNumber << "\n";
        cout << "Balance: " << account.balance << "\n";
    }
};

// Global storage (arrays instead of vectors)
Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

// Helper function to find account by account number
Account* findAccount(int accNum) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].account.accountNumber == accNum) {
            return &customers[i].account;
        }
    }
    return nullptr;
}

// Create a new customer with account
void createCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        cout << "❌ Cannot add more customers.\n";
        return;
    }

    string name;
    int customerID, accNum;
    double initDeposit;

    cout << "Enter Customer ID: ";
    cin >> customerID;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Account Number: ";
    cin >> accNum;

    // Ensure unique account number
    if (findAccount(accNum) != nullptr) {
        cout << "❌ Account number already exists!\n";
        return;
    }

    cout << "Enter Initial Deposit: ";
    cin >> initDeposit;

    customers[customerCount++] = Customer(name, customerID, accNum, initDeposit);
    cout << "✅ Customer account created successfully!\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== Banking System Menu =====\n";
        cout << "1. Create Customer\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Fund Transfer\n";
        cout << "5. Show Customer Info\n";
        cout << "6. Show Transactions\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int accNum, accNum2;
        double amount;

        switch (choice) {
        case 1:
            createCustomer();
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            if (Account* acc = findAccount(accNum)) {
                acc->deposit(amount);
            }
            else {
                cout << "❌ Account not found!\n";
            }
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            if (Account* acc = findAccount(accNum)) {
                acc->withdraw(amount);
            }
            else {
                cout << "❌ Account not found!\n";
            }
            break;

        case 4:
            cout << "Enter Your Account Number: ";
            cin >> accNum;
            cout << "Enter Receiver Account Number: ";
            cin >> accNum2;
            cout << "Enter Transfer Amount: ";
            cin >> amount;
            if (Account* acc1 = findAccount(accNum)) {
                if (Account* acc2 = findAccount(accNum2)) {
                    acc1->transfer(*acc2, amount);
                }
                else {
                    cout << "❌ Receiver account not found!\n";
                }
            }
            else {
                cout << "❌ Your account not found!\n";
            }
            break;

        case 5:
            cout << "Enter Account Number: ";
            cin >> accNum;
            if (Account* acc = findAccount(accNum)) {
                for (int i = 0; i < customerCount; i++) {
                    if (customers[i].account.accountNumber == accNum) {
                        customers[i].showInfo();
                    }
                }
            }
            else {
                cout << "❌ Account not found!\n";
            }
            break;

        case 6:
            cout << "Enter Account Number: ";
            cin >> accNum;
            if (Account* acc = findAccount(accNum)) {
                acc->showTransactions();
            }
            else {
                cout << "❌ Account not found!\n";
            }
            break;

        case 7:
            cout << "Exiting... Goodbye!\n";
            break;

        default:
            cout << "❌ Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}