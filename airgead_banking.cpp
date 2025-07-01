#include "airgead_banking.h"
#include <iostream>

// Function to pause execution and wait for any key press
void AirgeadBanking::pressAnyKeyToContinue() {
    std::cout << "Press any key to continue...";
    std::cin.ignore(); // Ignore any previous newline characters in the buffer
    std::cin.get();    // Wait for the user to press Enter
}

// Constructor implementation
AirgeadBanking::AirgeadBanking(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears)
    : m_initialInvestment(validatePositiveInput(t_initialInvestment)),
    m_monthlyDeposit(validatePositiveInput(t_monthlyDeposit)),
    m_interestRate(validatePositiveInput(t_interestRate)),
    m_numberOfYears(t_numberOfYears) {}

double AirgeadBanking::validatePositiveInput(double value) {
    if (value <= 0) {
        std::cerr << "Error: Please enter a positive value." << std::endl;
        exit(1);
    }
    return value;

}

void AirgeadBanking::printDetails(int year, double yearEndBalance, double interestEarned) {
    std::cout << year << "\t\t$" << std::fixed << std::setprecision(2) << yearEndBalance
        << "\t\t$" << interestEarned << std::endl;
}

// Function to calculate balance with monthly deposit
double AirgeadBanking::balanceWithMonthlyDeposit() {
    double balance = m_initialInvestment;
    double monthlyInterestRate = m_interestRate / 100 / 12;
    double interestEarnedThisYear = 0.0;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        interestEarnedThisYear = 0.0;

        for (int month = 0; month < 12; ++month) {
            balance += m_monthlyDeposit;
            double interest = balance * monthlyInterestRate;
            balance += interest;
            interestEarnedThisYear += interest;
        }

        printDetails(year, balance, interestEarnedThisYear);

        // Add "Press any key to continue" after each year's result
        pressAnyKeyToContinue();
    }

    return balance;
}

// Function to calculate balance without monthly deposit
double AirgeadBanking::calculateBalanceWithoutMonthlyDeposit() {
    double balance = m_initialInvestment;
    double monthlyInterestRate = m_interestRate / 100 / 12;
    double interestEarnedThisYear = 0.0;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        interestEarnedThisYear = 0.0;

        for (int month = 0; month < 12; ++month) {
            double interest = balance * monthlyInterestRate;
            balance += interest;
            interestEarnedThisYear += interest;
        }

        printDetails(year, balance, interestEarnedThisYear);

        // Add "Press any key to continue" after each year's result
        pressAnyKeyToContinue();
    }

    return balance;
}

// Function to prompt user input and allow different test scenarios
void AirgeadBanking::promptUser() {
    char choice;
    do {
        std::cout << "\nWould you like to test different values? (y/n): "; // Ask user for a choice
        std::cin >> choice; // user input
        if (choice == 'y') {
            std::cout << "Enter new initial investment amount: ";
            std::cin >> m_initialInvestment;
            std::cout << "Enter new monthly deposit amount: ";
            std::cin >> m_monthlyDeposit;
            std::cout << "Enter new annual interest rate: ";
            std::cin >> m_interestRate;
            std::cout << "Enter new number of years: ";
            std::cin >> m_numberOfYears;
        }
    } while (choice == 'y');
}
