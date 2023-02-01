#include "control.h"
#include <string>
#include <fstream>


using namespace std;


///////////////////
//input handlers//
////////////////
double Control::enterNum()
{
	double num;
	bool x = false;
	cin >> num;
	while (cin.fail())
	{
		printf("\nInvalid entry! Please Enter a number!\n");
		std::cin.clear();
		std::cin.ignore(64, '\n');
		cin >> num;
	}
	return num;

}

std::string Control::enterString()
{
	string name;
	cin >> name;
	std::cin.ignore(64, '\n');
	std::cin.clear();

	return name;
}


////////////////////
//Controller startup
////////////////////
bool Control::updateRunning(int num)
{
	switch (num)
	{
	case 0:
		_isRunning = false;
		break;
	case 1:
		_isRunning = true;
		break;
	}
	return _isRunning;
}


void Control::init()
{
	this->_isRunning = true;
	printf("Program is running!\n");	
	this->generateAccounts();

}

void Control::login()
{
	string username;
	int pword;
	bool turnON = false;

	while (!turnON)
	{

		if (_kbhit())
		{
			switch (_getch())
			{
			case 'q':
				turnON = true;
				break;
			}
		}
		//printf("USERNAME: ");
		//username = enterString();
		//printf("\n");
		//pword = enterNum();


		//if (username == getADMIN() && pword == getADMINPIN())
		//{
		//	turnON = true;
		//}
	}
	this->init();
}

//default accounts

void Control::generateAccounts()
{
	int x = getAccNum() + 1;
	this->updateTotalAccs(1);
	customerList.push_back(CustomersAccounts("Philip", "Smith", 117, x));
	this->updateTotalAccs(1);
	x = getAccNum();
	customerList.push_back(CustomersAccounts("Cathy", "Smith", 100.00, x));
	this->updateTotalAccs(1);
	x = getAccNum();
	customerList.push_back(CustomersAccounts("Amber", "Price", 11700.00, x));
	this->updateTotalAccs(1);
	x = getAccNum();
	customerList.push_back(CustomersAccounts("Glenda", "Price", 1.17, x));
	this->updateTotalAccs(1);
	x = getAccNum();
	customerList.push_back(CustomersAccounts("Tyler", "Price", 1.00, x));
	this->updateTotalAccs(1);
}




///////////
//menus////
///////////
void Control::printMainMenu()
{
	printf("\n\nMain Menu:\n");
	printf("1. Create a New Account\n");
	printf("2. View All Accounts\n");
	printf("3. Search For an Accounts\n");
	printf("4. Close Program\n");

}

void Control::mainMenu()
{
	printMainMenu();
	//userPick = this->enterNum();
	while (checkRunning()) {
		if (_kbhit())
		{
			switch (_getch())
				//switch (userPick)
			{
			case '1':
				printf("\n\n\nCreating a new Acount!\n");
				this->newAccount();
				printMainMenu();
				break;
			case '2':
				printf("Listing all accounts:\n\n\n");
				this->displayInfor("DEFAULT", 0, 0);
				printMainMenu();
				break;
			case '3':
				//printMenu
				this->searchMenu();
				break;
			case '4':
				this->updateRunning(0);
				break;
			default:
				printf("Invalid entry!\n\n\n");
				this->printMainMenu();
				break;
			}
		}
	}
}

void Control::printSearchMenu()

{
	printf("Searching All Acounts:\n");
	printf("1. Search By First Name\n");
	printf("2. Search By Last Name\n");
	printf("3. Search By Account Number\n");
	printf("4. Return to Main Menu\n");

}
void Control::searchMenu()
{
	int searchType = -1;
	this->printSearchMenu();
	userPick = this->enterNum();

	switch (userPick)
	{
	case 1:
		printf("\nSearching by First Name\n");
		printf("Enter First Name: ");
		searchType = 1;
		break;
	case 2:
		printf("\nSearching By Last Name\n");
		printf("Enter Last Name: ");
		searchType = 2;
		break;
	case 3:
		printf("\nSearching By Account Number\n");
		printf("Enter Account Number: ");
		searchType = 3;
		userPick = this->enterNum();
		//name, case number, account number to search
		this->displayInfor("NULL", searchType, userPick);
		break;
	case 4:
		this->mainMenu();
		break;
	default:
		printf("Invalid entry!\n\n\n");
		this->searchMenu();
		break;
	}

	if (searchType != 3 && searchType != -1)
	{
		//printf("\nsearching with strings\n");
		userPicks = this->enterString();
		this->displayInfor(userPicks, searchType, 0);
	}

	printf("\nWould you like to modify an account?\n");
	printf("Y/N\n");
	userPicks = this->enterString();
	if (userPicks == "Y") { editAcountMenu(); }
	this->mainMenu();
}





////////////////////////
//creating a new account
///////////////////////
void Control::newAccount()
{
	int x = 1;
	string fName;
	string lName;
	double dep;
	string pool;
	bool create = false;

	//creation loop
	while (x != -1)
	{
		switch (x)
		{
		case 1://First Name
			printf("\nType Back to go back to Main Menu\n");
			printf("\nPlease Enter the First Name: ");
			fName = this->enterString();
			if (fName == "Back") { x = -1; break; }
			x = 2;
			break;
		case 2://Last Name
			printf("\nType Back to re-enter First Name\n");
			printf("\nPlease Enter the Last Name: ");
			lName = this->enterString();
			if (lName == "Back") { x = 1;  break; }
			x = 3;
			break;
		case 3://Account Balance
			printf("\nType -2 to re-enter Last Name\n");
			printf("\nHow much would you like to deposit: $");
			dep = this->enterNum();
			if (dep == -2) { x = 2; break; }
			x = 4;
			break;
		case 4:
			printf("\nDo You want to create this account?\n");
			printf("\nType Y to fininalize. N to cancell\n");
			pool = this->enterString();
			x = -1;
			if (pool == "Y") { create = true; }
			break;
		}
	}
	if (create)
	{
		CustomersAccounts* n1;
		n1 = new CustomersAccounts;
		this->createAccount(fName, lName, dep, n1);
		this->displayInfor(fName, 1, 0);
	}
}

void Control::createAccount(std::string fName, std::string lName, double num, CustomersAccounts* n1)
{
	n1->updateFirstName(fName);
	n1->updateLastName(lName);
	n1->updateBalance(num);
	n1->updateAccNum(this->getAccNum());
	updateTotalAccs(1);
	customerList.push_back(*n1);
	//customerList.push_back(CustomersAccounts());
}

void Control::displayInfor(std::string name, int searchType, int num)
{
	int numbResults = 0;
	for (it = customerList.begin(); it != customerList.end(); ++it)
	{
		switch (searchType)
		{
		case -1:
			printf("error");
			break;

			//print all accounts
		case 0:
			it->getInformation();
			numbResults += 1;
			break;
			//search accounts first name
		case 1:
			printf("\Searching by First Name!\n");
			if ((it->getFirstName()) == name) { it->getInformation(); numbResults += 1; }
			break;
			//search accounts last name;
		case 2:
			printf("\nSearching by Last Name!\n");
			if ((it->getLastName()) == name) {
				it->getInformation(); numbResults += 1;
			}
			break;
			//search accounts account number
		case 3:
			printf("\nSearching by Account Number!\n");
			if ((it->getAccNum()) == num) { it->getInformation(); numbResults += 1; }
			break;
		}
	}
	if (numbResults == 0) { printf("\nNO MATCHES FOUND!\n"); }

}

void Control::editAcountMenu()
{
	printf("\nPlease enter the Account Number: ");
	int num;
	string name;
	bool valid = false;
	num = this->enterNum();

	for (it = customerList.begin(); it != customerList.end(); ++it)
	{
		if ((it->getAccNum()) == num)
		{
			it->getInformation();
			while (!valid)
			{
				printf("\nWhat would you like to edit?\n");
				printf("1. First Name\n");
				printf("2. Last Name\n");
				printf("3. Back to Main Menu\n");
				num = this->enterNum();

				switch (num)
				{
				case 1:
					printf("\nEnter new First Name: ");
					name = this->enterString();
					it->updateFirstName(name);
					valid = true;
					break;
				case 2:
					printf("\nEnter new Last Name: ");
					name = this->enterString();
					it->updateLastName(name);
					valid = true;
					break;
				case 3:
					valid = true;
					break;
				}
				if (!valid) { printf("Invalid entry!"); }
			}

		}
	}



}









