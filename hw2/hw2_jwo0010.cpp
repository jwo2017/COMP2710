//  Jonathan Osborne
//  jwo0010
//  hw2_jwo0010.cpp
//  This program takes the input from user of loan amount,
//      interest rate, and monthly amount of payment.
//      The program gives user a table showing how long
//      it will take to pay the loan back.
//  I recieved no help for this homework assignment.

#include <iostream>
#include <cmath>
using namespace std;
#include <iomanip>

int amortizeThis(float loanAmount, float interestRate, float monthlyAmount);

int monthCount = 0;
float totalInterest = 0;
int main(int argc, const char * argv[]) {
    float loanAmount, interestRate, monthlyAmount;
    
    cout << "Loan Amount: ";
    cin >> loanAmount;
    cout << "Interest Rate (% per year): ";
    cin >> interestRate;
    cout << "Monthly Payments: ";
    cin >> monthlyAmount;
    if (((interestRate / 12) * 0.01 * loanAmount) > monthlyAmount) {
        cout << "You must pay a monthly amount greater than initial interest.\n";
        return 0;
    }
    cout << "******************************************************\n\tAmortization Table\n"
    << "******************************************************\nMonth   Balance   Payment   Rate   Interest " <<
    "   Principal\n0   " << loanAmount << "   N/A   N/A   N/A N/A\n";
    amortizeThis(loanAmount, interestRate, monthlyAmount);
    
    cout << "******************************************************\n\nIt takes " << monthCount
    << " months to pay off the loan. \nTotal interest paid is: $" << totalInterest << "\n";
    return 0;
}

int amortizeThis(float loanAmount, float interestRate, float monthlyAmount) {
    
    float interest = 0, principal = 0;
    float intRatePerMonth = (interestRate / 12) * 0.01;
    
    while (loanAmount > 0) {
        
        if (loanAmount < monthlyAmount) {
            interest = loanAmount * intRatePerMonth;
            monthlyAmount = loanAmount + interest;
            loanAmount = 0;
            totalInterest += interest;
            monthCount++;
            principal = monthlyAmount - interest;
        }
        else {
            interest = loanAmount * intRatePerMonth;
            principal = monthlyAmount - interest;
            totalInterest += interest;
            monthCount++;
            loanAmount -= principal;
        }
        
        
        cout << std::fixed << std::setprecision(2) << monthCount << "   $" << loanAmount << "   $" << monthlyAmount << "   "
            << setprecision(1) << intRatePerMonth * 100 << setprecision(2) << "   $"
            << interest << "   $" << principal << "\n";
    }
    return 0;
}

