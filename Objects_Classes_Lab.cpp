// Matthew Chhim, 1/30/2026, The purpose of this program is to create a BankAccount class and provide bank management methods for multiple accounts, Objects and Classes I Lab 
#include <iostream>
#include <vector>

// BankAccount class definition

class BankAccount {
public: 
	// Constructor for BankAccount
	BankAccount() {
		accountNumber = "000000";
		accountHolderName = "Default Name";
		balance = 0.0;
	}

	BankAccount(std::string id, std::string name, double initialBalance) {
		accountNumber = id;
		accountHolderName = name;
		balance = initialBalance;
	}

	// Accessor methods or getters
	std::string getAccountNumber() const {
		return accountNumber;
	}

	std::string getaccountHolderName() const {
		return accountHolderName;
	}

	double getBalance() const {
		return balance;
	}

	// Deposit and Withdraw methods
	void deposit(double amount) {
		balance += amount;
	}

	void withdraw(double amount) {
		if (amount > balance) {
			std::cout << "\nInsufficient funds. Withdrawal amount exceeds current balance.\n" << std::endl;
		} else {
			balance -= amount;
		}
	}


private: 
	// Private members
	std::string accountNumber;
	std::string accountHolderName;
	double balance;
};



int main() {
	std::vector<BankAccount> accounts;
	int option;




	do {

	std::cout << "--- Bank Account Management System ---\n" << std::endl;
	std::cout << "1. Add new bank account: \n" << std::endl;
	std::cout << "2. Deposit Funds: \n" << std::endl;
	std::cout << "3. Withdraw Funds: \n" << std::endl;
	std::cout << "4. Display Accounts: \n" << std::endl;
	std::cout << "5. Quit. \n" << std::endl;
	std::cout << "What would you like to do next? \n" << std::endl;
	std::cin >> option;

	switch (option) {

	case 1: {
		// Add new Bank account
		std::string id, name;
		double initialBalance;

		std::cout << "\n Creating a new bank account. \n" << std::endl;


		std::cout << "Enter Account Number: ";
		std::cin >> id;

		// Clear newline
		std::cin.ignore();

		std::cout << "\nEnter Account Holder name: ";
		std::cin >> name;

		// Input validation for starting balance
		std::cout << "\nEnter your starting balance: ";
		while (!(std::cin >> initialBalance) || initialBalance < 0) {
			std::cout << "\nInvalid input. Please enter a non-negative number for the starting balance: ";
			std::cin.clear();
			std::cin.ignore(1000, '\n');

		}

		// Create object using constructor and add to vector
		BankAccount newAccount(id, name, initialBalance);
		accounts.push_back(newAccount);

		std::cout << "\nAccount created successfully.\n" << std::endl;
		break;
	}

	case 2: {
		// Deposit Funds
		std::string depositId;
		double depositAmount;
		bool foundDeposit = false;

		std::cout << "\n--- Deposit Funds ---\n" << std::endl;

		// Checking if there are any accounts to deposit into
		if (accounts.empty()) {
			std::cout << "\nNo accounts available." << std::endl;
			break;
		}

		std::cout << "Enter Account Number to deposit into: ";
		std::cin >> depositId;

		// Search for account within vector
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i].getAccountNumber() == depositId) {


				foundDeposit = true;

				// Input validation for deposit amount
				std::cout << "Enter amount to deposit: ";
				while (!(std::cin >> depositAmount) || depositAmount <= 0) {
					std::cout << "\nInvalid input. Please enter a positive number for the deposit amount: ";
					std::cin.clear();
					std::cin.ignore(1000, '\n');
				}

				accounts[i].deposit(depositAmount);
				std::cout << "\nDeposit successful: $" << depositAmount << " has been added to your account" << std::endl;
				break;
			}

		}

		if (!foundDeposit) {
			std::cout << "\nAccount not found. Check the account number again.\n" << std::endl;
		}

		break;
	}

	case 3: {
		std::string withdrawId;
		double withdrawAmount;
		bool foundWithdraw = false;

		std::cout << "\n--- Withdraw Funds ---\n" << std::endl;

		if (accounts.empty()) {
			std::cout << "\nNo accounts available." << std::endl;
			break;
		}

		std::cout << "Enter Account Number to withdraw from: ";
		std::cin >> withdrawId;

		// Search for account within vector
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i].getAccountNumber() == withdrawId) {
				foundWithdraw = true;

				// Input validation for withdrawal amount
				std::cout << "Enter amount to withdraw: ";
				while (!(std::cin >> withdrawAmount) || withdrawAmount <= 0) {
					std::cout << "\nInvalid input. Please enter a positive number for the withdraw amount: ";
					std::cin.clear();
					std::cin.ignore(1000, '\n');
				}

				accounts[i].withdraw(withdrawAmount);
				std::cout << "\nWithdrawal successful: $" << withdrawAmount << " has been withdrawn from your account" << std::endl;
				break;
			}
		}
		if (!foundWithdraw) {
			std::cout << "\nAccount not found. Check the account number again.\n" << std::endl;
		}

		break;
	}

	case 4: {
		std::cout << "\n--- Displaying All Accounts ---\n" << std::endl;

		if (accounts.empty()) {
			std::cout << "\nNo accounts available." << std::endl;
			break;
		}

		// Loop through accounts and display info
		for (const auto& account : accounts) {
			std::cout << "---------------" << std::endl;
			std::cout << "Account Number: " << account.getAccountNumber() << std::endl;
			std::cout << "Account Holder: " << account.getaccountHolderName() << std::endl;
			std::cout << "Balance: $" << account.getBalance() << std::endl;
		}

		std::cout << "---------------\n" << std::endl;
		break;
	}

	case 5: {
		std::cout << "\nExiting the program. Goodbye.\n" << std::endl;
		break;

	default:
		std::cout << "\nInvalid option. Please try again.\n" << std::endl;
		break;
	}
	}

	} while (option != 5);
	

	return 0;
}