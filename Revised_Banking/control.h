#pragma once
#include "CustomersAccounts.h"
#include <fstream>
#include <iostream>
#include <list>
#include <conio.h>


class Control
{


public:

	//input handlers
	double enterNum();
	std::string enterString();


	//starts program
	void init();
	void login();
	void generateAccounts();
	bool checkRunning() { return _isRunning; }

	//creates new accounts
	void newAccount();
	void createAccount(std::string fName, std::string lName, double num, CustomersAccounts* n1);


	//setters
	bool updateRunning(int num);
	void updateTotalAccs(int num) { _totalAcc += num; }

	//getters
	void displayInfor(std::string name, int searchType, int num);
	int getAccNum() { return _totalAcc; }
	std::string getADMIN() { return _ADMIN; }
	int getADMINPIN() { return _adminPIN; }


	//menus
	void mainMenu();
	void searchMenu();
	void editAcountMenu();

	//print functions
	void printMainMenu();
	void printSearchMenu();


private:
	bool _isRunning = false;
	int _totalAcc = 0;


	std::string _ADMIN = "ADMIN117";
	int _adminPIN = 150391;


	int userPick;
	std::string userPicks;

	std::list<CustomersAccounts> customerList;
	std::list<CustomersAccounts>::iterator it;
	

};
