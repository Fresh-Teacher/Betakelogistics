#include <iostream>
#include <string>
#include <algorithm>

class LoanCalculator {
private:
    double principal;
    int years;
    const double INTEREST_RATE = 0.10;

public:
    LoanCalculator(double p, int y) : principal(p), years(y) {}

    double calculateInterest() {
        return principal * INTEREST_RATE * years;
    }

    double calculateTotalAmount() {
        return principal + calculateInterest();
    }
};

class StringOperations {
private:
    std::string str;

public:
    StringOperations(const std::string& s) : str(s) {}

    std::string copy() { return str; }

    std::string reverse() {
        std::string rev = str;
        std::reverse(rev.begin(), rev.end());
        return rev;
    }

    std::string uppercase() {
        std::string up = str;
        std::transform(up.begin(), up.end(), up.begin(), ::toupper);
        return up;
    }

    std::string lowercase() {
        std::string low = str;
        std::transform(low.begin(), low.end(), low.begin(), ::tolower);
        return low;
    }

    std::string compare() {
        return str == str ? "equal" : "not equal";
    }
};

int main() {
    double loanAmount;
    int loanPeriod;
    std::string companyName;

    std::cout << "Enter loan amount: ";
    std::cin >> loanAmount;
    std::cout << "Enter loan period (years): ";
    std::cin >> loanPeriod;
    std::cout << "Enter company name: ";
    std::cin.ignore();
    std::getline(std::cin, companyName);

    LoanCalculator loan(loanAmount, loanPeriod);
    StringOperations strOps(companyName);

    std::cout << "\nLoan Details:\n";
    std::cout << "Principal: $" << loanAmount << std::endl;
    std::cout << "Period: " << loanPeriod << " years" << std::endl;
    std::cout << "Interest: $" << loan.calculateInterest() << std::endl;
    std::cout << "Total Amount: $" << loan.calculateTotalAmount() << std::endl;

    std::cout << "\nString Operations on Company Name:\n";
    std::cout << "Copy: " << strOps.copy() << std::endl;
    std::cout << "Reverse: " << strOps.reverse() << std::endl;
    std::cout << "Uppercase: " << strOps.uppercase() << std::endl;
    std::cout << "Lowercase: " << strOps.lowercase() << std::endl;
    std::cout << "Strings are " << strOps.compare() << std::endl;

    return 0;
}