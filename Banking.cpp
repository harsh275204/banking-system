#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    string time;

    Transaction(string t, double a, string tm) : type(t), amount(a), time(tm) {}
};

class Account {
private:
    string username;
    string pin;
    double balance;
    vector<Transaction> history;

    string currentTime() {
        time_t now = time(0);
        char* dt = ctime(&now);
        string t(dt);
        t.pop_back(); // remove newline
        return t;
    }

public:
    Account(string u, string p, double b = 0.0) {
        username = u;
        pin = p;
        balance = b;
    }

    bool authenticate(string u, string p) {
        return (u == username && p == pin);
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount, currentTime()));
        cout << "✅ Deposited Rs." << amount << " successfully.\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "❌ Insufficient funds!\n";
        } else {
            balance -= amount;
            history.push_back(Transaction("Withdraw", amount, currentTime()));
            cout << "✅ Withdrawn Rs." << amount << " successfully.\n";
        }
    }

    void checkBalance() {
        cout << "💰 Current Balance: Rs." << balance << "\n";
    }

    void showHistory() {
        cout << "\n📜 Transaction History:\n";
        for (auto &t : history) {
            cout << t.type << " of Rs." << t.amount << " on " << t.time << "\n";
        }
    }
};

int main() {
    // Predefined account for demo
    Account acc("harsh", "1234", 5000);

    string user, pin;
    cout << "=== Welcome to C++ Banking System ===\n";
    cout << "Enter Username: ";
    cin >> user;
    cout << "Enter PIN: ";
    cin >> pin;

    if (!acc.authenticate(user, pin)) {
        cout << "❌ Invalid login! Exiting...\n";
        return 0;
    }

    int choice;
    double amount;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                acc.checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc.withdraw(amount);
                break;
            case 4:
                acc.showHistory();
                break;
            case 5:
                cout << "👋 Thank you for banking with us!\n";
                break;
            default:
                cout << "❌ Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
