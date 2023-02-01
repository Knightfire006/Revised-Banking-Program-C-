#pragma once
#include <string>
#include <list>


class CustomersAccounts
{


public:

	CustomersAccounts();

	//default list
	CustomersAccounts(std::string fname, std::string lname, double balance, int acc);


	//CustomersAccounts();
	void getInformation();

	//setters
	void updateFirstName(std::string name) { _firstName = name; }
	void updateLastName(std::string name) { _lastName = name; }
	void updateBalance(double num) { _checkingBalance += num; }
	void updateAccNum(int num) { _accountNum = num; };

	//not implemented yet
	void updateSavings(double num) { _savingsBalance = num; }
	double getSavingsBal() { return _savingsBalance; }
	void createPIN();
	int getPIN();

	

	//getters
	double getBalance() { return _checkingBalance; }
	std::string getFirstName() { return _firstName; }
	std::string getLastName() { return _lastName; }
	int getAccNum() { return _accountNum; }


private:


	std::string _firstName;
	std::string _lastName;
	double _checkingBalance = 0;
	int _accountNum = 0;
	
	//not implemented yet
	double _savingsBalance = 0;
	int _PIN;

};

