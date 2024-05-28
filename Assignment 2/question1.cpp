#include <bits/stdc++.h>
using namespace std;

class Account {
protected:
    int AccountNumber;
    string HolderName;
    string Address;
    string AccountType;
    long long Funds;
    vector<string> TransactionHistory;
    vector<string> LoanHistory;

public:
    Account(int accNum, string name, string addr, string type, long long initial)
        : AccountNumber(accNum), HolderName(name), Address(addr), AccountType(type), Funds(initial) {}

    void Deposit(long long amt) {
        Funds += amt;
        TransactionHistory.push_back("Deposit: " + to_string(amt) + " at " + currentDateTime());
    }

    void Withdraw(long long amt) {
        if (Funds >= amt) {
            Funds -= amt;
            TransactionHistory.push_back("Withdrawal: " + to_string(amt) + " at " + currentDateTime());
        } else {
            cout << "Insufficient Funds." << endl;
        }
    }

    void UpdateInfo(string name, string addr) {
        HolderName = name;
        Address = addr;
    }

    void TakeLoan(long long amt) {
        Funds += amt;
        LoanHistory.push_back("Loan: " + to_string(amt) + " at " + currentDateTime());
    }

    void TransferFunds(Account &toAccount, long long amt) {
        if (Funds >= amt) {
            Funds -= amt;
            toAccount.Funds += amt;
            TransactionHistory.push_back("Transferred: " + to_string(amt) + " to Account " + to_string(toAccount.AccountNumber) + " at " + currentDateTime());
            toAccount.TransactionHistory.push_back("Received: " + to_string(amt) + " from Account " + to_string(AccountNumber) + " at " + currentDateTime());
        } else {
            cout << "Insufficient Funds." << endl;
        }
    }

    void viewPassbook() {
        cout << "Account Number: " << AccountNumber << endl;
        cout << "Account Holder: " << HolderName << endl;
        cout << "Address: " << Address << endl;
        cout << "Account Type: " << AccountType << endl;
        cout << "Current Funds: " << Funds << endl;
        cout << "Transaction History: " << endl;
        for (const auto &entry : TransactionHistory) {
            cout << entry << endl;
        }
        cout << "Loan History: " << endl;
        for (const auto &entry : LoanHistory) {
            cout << entry << endl;
        }
    }

    void searchTransactionHistory(string date, long long amt) const {
        cout << "Searching for transactions on " << date << " with amount " << amt << ":" << endl;
        for (const auto &entry : TransactionHistory) {
            if (entry.find(date) != string::npos && entry.find(to_string(amt)) != string::npos) {
                cout << entry << endl;
            }
        }
    }

    static string currentDateTime() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return to_string(ltm->tm_year + 1900) + "-" + to_string(ltm->tm_mon + 1) + "-" + to_string(ltm->tm_mday);
    }
};

class JointAccount : public Account {
private:
    string JointHolderName;

public:
    JointAccount(int accNum, string primaryName, string jointName, string addr, string type, long long initFunds)
        : Account(accNum, primaryName, addr, type, initFunds), JointHolderName(jointName) {}

    void viewPassbook () {
        cout << "Joint Account Number: " << AccountNumber << endl;
        cout << "Primary Account Holder: " << HolderName << endl;
        cout << "Joint Account Holder: " << JointHolderName << endl;
        cout << "Address: " << Address << endl;
        cout << "Account Type: " << AccountType << endl;
        cout << "Current Funds: " << Funds << endl;
        cout << "Transaction History: " << endl;
        for (const auto &entry : TransactionHistory) {
            cout << entry << endl;
        }
        cout << "Loan History: " << endl;
        for (const auto &entry : LoanHistory) {
            cout << entry << endl;
        }
    }
};

int main() {
    Account acc1(1, "John Doe", "123 Main St", "Savings", 1000);
    JointAccount acc2(2, "Jane Smith", "Bob Smith", "456 Oak St", "Checking", 2000);

    acc1.Deposit(500);
    acc1.Withdraw(300);
    acc1.TakeLoan(1000);
    acc1.UpdateInfo("John Doe Jr.", "789 Pine St");

    acc2.Deposit(1000);
    acc2.Withdraw(500);

    acc1.TransferFunds(acc2, 200);

    cout << "Account 1 Passbook:" << endl;
    acc1.viewPassbook();

    cout << "\nAccount 2 Passbook:" << endl;
    acc2.viewPassbook();

    cout << "\nSearching transactions in Account 1:" << endl;
    acc1.searchTransactionHistory("2024-05-28", 500);

    return 0;
}
