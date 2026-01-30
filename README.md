# Objects_Classes_Lab

A Bank management system for holding multiple accounts with deposit and withdrawal methods.

## Data Dictionary

| Attribute | Data Type | Description |
|-----------|-----------|-------------|
| accountNumber | std::string | A numerical identifier for the account |

| accountHolderName | std::string | A name associated with the account |

| balance | double | The amount of money stored within the accountc |

## Methods List 

| Method Signature | Return type | Description |
|------------------|-------------|-------------|
| BankAccount() | Constructor | Initialized the account with default values|
| BankAccount(std::string id, std::string name, double initialBalance) | Constructor | Initalizes a specified account number, account name, and balance to an account. |
| getAccountNumber() | std::string | Returns the account number |
| getAccountHolderName() | std::string | Returns the account holder name |
| getBalance() | double | Returns the balance of the account |
| setAccountHolderName(std::string name) | void | Sets the name of the account holder |
| deposit(double amount) | void | Adds the deposited amount into the account |
| Withdraw(double amount) | void | Takes the amount away from the current balance of the account |
