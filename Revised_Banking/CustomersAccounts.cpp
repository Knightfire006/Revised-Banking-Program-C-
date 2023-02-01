#include "CustomersAccounts.h"
#include <iostream>

//default accounts



CustomersAccounts::CustomersAccounts()
{

}


CustomersAccounts::CustomersAccounts(std::string fname, std::string lname, double balance, int acc)
{
	this->updateFirstName(fname);
	this->updateLastName(lname);
	this->updateBalance(balance);
	this->updateAccNum(acc);
	//SAVINGS
	//PIN
}





void CustomersAccounts::getInformation()
{
	printf("\n\n*****\n");
	printf("ACCOUNT # %d\n", _accountNum);
	printf("First Name: %s\n", _firstName.c_str());
	printf("Last Name: %s\n", _lastName.c_str());
	printf("Checking Balance: $%f\n", _checkingBalance);
	//printf("Savings Balance: %d\n", _savingsBalance);
	//printf("PIN: &d", _PIN);
	printf("*****\n\n");
}
