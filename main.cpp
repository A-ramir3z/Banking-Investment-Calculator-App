/* 
Alejandro Ramirez Valdes
CS-210 Programming Languages
October 10, 2024

This program aims to provide the user with a friendly interface to calculate 
investment growth given certain parameters. It complies with the companys
specifications.
*/



#include "airgead_banking.h"
#include <memory>
#include <string> // Use <string> for std::string

int main() {
    try {
        // User input variables
        double initialInvestment, monthlyDeposit, interestRate;
        int numberOfYears;

        // Display welcome message
        std::string separator(53, '-'); // Create a string with '-'
        std::cout << separator << std::endl; //print the string with '-'
        std::cout << "Welcome to the Airgead Banking Investment Calculator!" << std::endl;
        std::cout << "This program will help you understand the power of compound interest.\n" << std::endl;
  

        // Get user input
        std::cout << separator << std::endl; 
        std::cout << separator << std::endl; 
        std::cout << "Enter your initial investment amount ($): ";
        std::cin >> initialInvestment;
        std::cout << "Enter your monthly deposit amount ($): ";
        std::cin >> monthlyDeposit;
        std::cout << "Enter annual interest rate (in %): ";
        std::cin >> interestRate;
        std::cout << "Enter number of years for the investment: ";
        std::cin >> numberOfYears;
        std::cout << separator << std::endl; 


        // Clear any previous input buffer
        std::cin.ignore();

        // Instantiate the AirgeadBanking class using smart pointer
        auto airgead = std::make_unique<AirgeadBanking>(initialInvestment, monthlyDeposit, interestRate, numberOfYears);

        // Calculate and display balances without monthly deposit
        std::cout << "\nResults Without Monthly Deposits:\n";
        std::cout << "Year\t\tEnding Balance\t\tInterest Earned" << std::endl;
        airgead->calculateBalanceWithoutMonthlyDeposit();

        // Calculate and display balances with monthly deposit
        std::cout << "\nResults With Monthly Deposits:\n";
        std::cout << "Year\t\tEnding Balance\t\tInterest Earned" << std::endl;
        airgead->balanceWithMonthlyDeposit();

        // Prompt user to test different values
        airgead->promptUser();

        // End of program
        std::cout << "\nThank you for using the Airgead Banking Investment Calculator!" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
