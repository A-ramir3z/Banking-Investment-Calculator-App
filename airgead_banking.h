#ifndef AIRGEAD_BANKING_H_
#define AIRGEAD_BANKING_H_

#include <iostream>
#include <iomanip>

class AirgeadBanking {
private:
    // Private members
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_interestRate;
    int m_numberOfYears;

    // Function to validate positive input
    double validatePositiveInput(double value);

public:
    // Constructor
    AirgeadBanking(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears);

    // Member functions
    double balanceWithMonthlyDeposit();
    double calculateBalanceWithoutMonthlyDeposit();
    void printDetails(int year, double yearEndBalance, double interestEarned);
    void promptUser();

    // Function to pause and wait for user input
    void pressAnyKeyToContinue();
};

#endif // AIRGEAD_BANKING_H_