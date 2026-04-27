#include <vector>
#include <string>

struct Transaction {
    std::string type; // "INCOME" or "EXPENSE"
    std::string source;
    double amount;
};

class Report {
public:
    static std::vector<Transaction> history;
    
    static void addTransaction(std::string t, std::string s, double a) {
        history.push_back({t, s, a});
    }
};

// Initialize the static member
std::vector<Transaction> Report::history = {};