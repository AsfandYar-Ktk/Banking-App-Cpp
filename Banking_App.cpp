#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <time.h>
#include <fstream>
#include <cstring>
#include <sstream>
#include <ctime>
#include <format>
#include <chrono>

#undef max;
using namespace std;
const int accountLimit = 50;
const int transactionLimit = 50;
enum  Branches
{
	LAHORE = 0,
	ISLAMABAD,
	KARACHI
};

//-------------DATE CLASS-------------------
class Date
{
private:
	int Day;
	int Month;
	int Year;
public:
	Date(int, int, int);
	void setDate(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay();
	int getMonth();
	int getYear();
	void printDate();
};
Date::Date(int Day = 1, int Month = 1, int Year = 1999)
{
	if (Day < 32 && Month < 13 && Year < 2021)
	{
		this->Day = Day;
		this->Month = Month;
		this->Year = Year;
	}
	else
	{
		//If user gives Invalid Values at Initialization
		this->Day = 1;
		this->Month = 1;
		this->Year = 1999;
		cout << "Invalid Date Format. Default Date Set!" << endl;
	}
}
void Date::setDate(int Day = 1, int Month = 1, int Year = 1999)
{
	if (Day < 32 && Month < 13)
	{
		this->Day = Day;
		this->Month = Month;
		this->Year = Year;
	}
	else
	{
		cout << "Invalid Date Format. Date Not Changed!" << endl;
	}
}
void Date::setDay(int Day)
{
	if (Day < 32)
	{
		this->Day = Day;
	}
}
void Date::setMonth(int Month)
{
	if (Month < 13)
	{
		this->Month = Month;
	}
}
void Date::setYear(int Year)
{
	this->Year = Year;
}
int Date::getDay()
{
	return this->Day;
}
int Date::getMonth()
{
	return this->Month;
}
int Date::getYear()
{
	return this->Year;
}
void Date::printDate()
{
	cout << setw(2) << setfill('0') << this->Day << "/" << setw(2) << setfill('0') << this->Month << "/" << this->Year << endl;
}
//:::::::::::::::::::::::::::::::::::::::

//-----------Person Class--------------
class Person
{
protected:
	string Name;
	string Gender;
	string CNIC;
	Date DOB;
public:
	Person();
	Person(string, string, string, Date);

	void Set_Values(string, string, string, Date);
	void Set_Name(string);
	void Set_Gender(string);
	void Set_CNIC(string);
	void Set_DOB_Day(int);
	void Set_DOB_Month(int);
	void Set_DOB_Year(int);
	void Set_DOB(int, int, int);

	string Get_Name();
	string Get_Gender();
	string Get_CNIC();
	string Get_str_DOB();
	int Get_DOB_Day();
	int Get_DOB_Month();
	int Get_DOB_Year();
	Date Get_DOB();

	void Print_DOB();

	void Display_Person();
};

Person::Person()
{
	this->Name = "";
	this->Gender = ' ';
	this->CNIC = "1234-567890-1";
	this->DOB.setDate(1, 1, 1999);
}
Person::Person(string Name, string Gender, string CNIC, Date DOB)
{
	this->Name = Name;
	this->Gender = Gender;
	this->CNIC = CNIC;
	this->DOB = DOB;
}

void Person::Set_Values(string Name, string Gender, string CNIC, Date DOB)
{
	this->Name = Name;
	this->Gender = Gender;
	this->CNIC = CNIC;
	this->DOB = DOB;
}

void Person::Set_Name(string Name)
{
	this->Name = Name;
}
void Person::Set_Gender(string Gender)
{
	this->Gender = Gender;
}
void Person::Set_CNIC(string CNIC)
{
	this->CNIC = CNIC;
}
void Person::Set_DOB_Day(int Day)
{
	this->DOB.setDay(Day);
}
void Person::Set_DOB_Month(int Month)
{
	this->DOB.setMonth(Month);
}
void Person::Set_DOB_Year(int Year)
{
	this->DOB.setYear(Year);
}
void Person::Set_DOB(int Day, int Month, int Year)
{
	if (Day < 32 && Month < 13)
	{
		this->DOB.setDay(Day);
		this->DOB.setMonth(Month);
		this->DOB.setYear(Year);
	}
	else
	{
		cout << "Invalid DOB Format. Date Not Changed!" << endl;
	}
}


string Person::Get_Name()
{
	return this->Name;
}
string Person::Get_Gender()
{
	return this->Gender;
}
string Person::Get_CNIC()
{
	return this->CNIC;
}
int Person::Get_DOB_Day()
{
	return this->DOB.getDay();
}
int Person::Get_DOB_Month()
{
	return this->DOB.getMonth();
}
int Person::Get_DOB_Year()
{
	return this->DOB.getYear();
}
Date Person::Get_DOB()
{
	return DOB;
}

string Person::Get_str_DOB()
{
	ostringstream oss;
	oss << setw(2) << setfill('0') << DOB.getDay() << "/" << setw(2) << setfill('0') << DOB.getMonth() << "/" << DOB.getYear();
	return oss.str();
}

void Person::Print_DOB()
{
	cout << setw(2) << setfill('0') << DOB.getDay() << "/" << setw(2) << setfill('0') << DOB.getMonth() << "/" << DOB.getYear();
}

void Person::Display_Person()
{
	cout << "Name: " << this->Name << endl;
	cout << "Gender: " << this->Gender << endl;
	cout << "CNIC Number: " << this->CNIC << endl;
	cout << "Date of Birth: "; this->DOB.printDate();
}
//:::::::::::::::::::::::::::::::::::::::


//-----------Customer Class---------------
class Customer :public Person
{
private:
	string customerID;

public:
	Customer();
	Customer(string, string, string, string, Date);

	void Set_values_To_NULL();
	void Set_Customer_ID(string);

	string Get_Customer_ID();

	void Display_Customer();
};

Customer::Customer()
{
	this->customerID = "";
}
Customer::Customer(string cID, string Name = "", string Gender = "", string CNIC = "", Date DOB = NULL) :Person(Name, Gender, CNIC, DOB)
{
	this->customerID = cID;
}

void Customer::Set_values_To_NULL()
{

	this->customerID = "";
	this->Name = "";
	this->Gender = "";
	this->CNIC = "";
	this->DOB.setDate(1, 1, 1999);

}
void Customer::Set_Customer_ID(string customerID)
{
	this->customerID = customerID;
}



string Customer::Get_Customer_ID()
{
	return customerID;
}



void Customer::Display_Customer()
{
	this->Display_Person();
	cout << "Enrollment Number: " << this->customerID << endl;
}
//:::::::::::::::::::::::::::::::::::::::


//----------Account Class------------
class Account
{
private:
	string AccountNumber;
	Customer customer;
	string Password;
	float Balance;
	Branches Bank_Branch; //ENUMERATION OF Branches CONTAINING ONLY 3 branches
	string Location;

public:
	Account();
	Account(string, Customer, string, float, Branches);

	void Set_Values(string, Customer, string, float, Branches);

	void Set_AccNumber(string);
	void Set_Customer(Customer);
	void Set_Password(string);
	void Set_Balance(float);
	void Set_Branch(Branches);

	string Get_AccNumber();
	Customer& Get_Customer();
	string Get_Password();
	float Get_Balance();
	string Get_Branch();
	string Get_Location();

	void display_Account();
};

Account::Account() {
	this->AccountNumber = "";
	this->customer = Customer();
	this->Password = "";
	this->Balance = 0;
	this->Bank_Branch = LAHORE;
	switch (this->Bank_Branch)
	{
	case 0:
	{
		this->Location = "Civic Centre Block D 2 Phase 1 Johar Town, Lahore.";
		break;
	}
	case 1:
	{
		this->Location = "Shangrilla Rd, E-8/1 ,Islamabad Capital Territory.";
		break;
	}
	case 2:
	{
		this->Location = "13 National Stadium Rd, Karachi.";
		break;
	}
	default:
	{
		cout << "Invalid Branch ADRESS." << endl;
	}
	}
}
Account::Account(string AccountNumber, Customer customer, string Password, float Balance = 0, Branches Bank_Branch = LAHORE) {
	this->AccountNumber = AccountNumber;
	this->customer = customer;
	this->Password = Password;
	this->Balance = Balance;
	this->Bank_Branch = Bank_Branch;
	switch (this->Bank_Branch)
	{
		case 0:
		{
			this->Location = "Civic Centre Block D 2 Phase 1 Johar Town, Lahore.";
			break;
		}
		case 1:
		{
			this->Location = "Shangrilla Rd, E-8/1 ,Islamabad Capital Territory.";
			break;
		}
		case 2:
		{
			this->Location = "13 National Stadium Rd, Karachi.";
			break;
		}
		default:
		{
			cout << "Invalid Branch ADRESS." << endl;
		}
	}
}
void Account::Set_Values(string AccountNumber, Customer customer, string Password, float Balance, Branches Bank_Branch) {
	this->AccountNumber = AccountNumber;
	this->customer = customer;
	this->Password = Password;
	this->Balance = Balance;
	this->Bank_Branch = Bank_Branch;
}

void Account::Set_AccNumber(string AccountNumber) {
	this->AccountNumber = AccountNumber;
}

void Account::Set_Customer(Customer customer) {
	this->customer = customer;
}

void Account::Set_Password(string Password) {
	this->Password = Password;
}

void Account::Set_Balance(float Balance) {
	if (Balance < 0)
	{
		cout << "Balance can not be in negative! Not changed." << endl;
	}
	else
	{
		this->Balance = Balance;
	}
}
void Account::Set_Branch(Branches Bank_Branch)
{
	this->Bank_Branch = Bank_Branch;
	switch (this->Bank_Branch)
	{
	case 0:
	{
		this->Location = "Civic Centre Block D 2 Phase 1 Johar Town, Lahore.";
		break;
	}
	case 1:
	{
		this->Location = "Shangrilla Rd, E-8/1 ,Islamabad Capital Territory.";
		break;
	}
	case 2:
	{
		this->Location = "13 National Stadium Rd, Karachi.";
		break;
	}
	default:
	{
		cout << "Invalid Branch Adress." << endl;
	}
	}
}

string Account::Get_AccNumber() {
	return AccountNumber;
}

Customer& Account::Get_Customer() {
	return customer;
}

string Account::Get_Password() {
	return Password;
}

float Account::Get_Balance() {
	return Balance;
}
string Account::Get_Branch()
{
	switch (this->Bank_Branch)
	{
		case 0:
		{
			return "Lahore";
		}
		case 1:
		{
			return "Islamabad";
		}
		case 2:
		{
			return "Karachi";
		}
		default:
		{
			return "Invalid CASE BRANCH DISPLAY!";
		}
	}
}
string Account::Get_Location()
{
	return this->Location;
}

void Account::display_Account() {
	std::cout << "Account Number: " << AccountNumber << std::endl;
	std::cout << "Customer: " << customer.Get_Name() << std::endl;
	std::cout << "Balance: " << Balance << std::endl;
}
//:::::::::::::::::::::::::::::::::::::::


//----------Bank Class------------
class Admin;
class Bank
{
private:
	string BankName;
	string Website;
	Account allAccounts[accountLimit];
	int accountCount;
	friend Admin;

	void generateBankReport();
	bool isValidCredential(string, string);
public:

	Bank(string, string);

	void Set_Values(string, string);

	void Set_BankName(string);
	void Set_Website(string);

	string Get_BankName();
	string Get_Website();

	void setFileData();
	void getFileData();

	bool debitAccount(string, float);
	bool creditAccount(string, float);
	bool cashTransfer(string, string, float);

	void deleteAccount(string);
	void addAccount(Account);
	void changePassword(string,string);
	string getBalanceByUserId(string);
	int getIndexByUserId(string);

	void getAccountDetails(string);
	bool isUniqueID(string);
	void display_Bank();
};

Bank::Bank(string BankName = "", string Website = "")
{
	this->BankName = BankName;
	this->accountCount = 0;
	this->Website = Website;

}

void Bank::Set_Values(string BankName, string Website)
{
	this->BankName = BankName;
	this->Website = Website;
}

void Bank::Set_BankName(string BankName)
{
	this->BankName = BankName;
}

void Bank::Set_Website(string Website)
{
	this->Website = Website;
}

string Bank::Get_BankName()
{
	return BankName;
}


string Bank::Get_Website()
{
	return Website;
}

void Bank::setFileData()
{
	string fileName = "accounts_data.txt";
	ofstream OutFile(fileName, ios::out);
	OutFile << this->accountCount << "\n";
	for (int index = 0; index < accountCount; index++)
	{
		Customer c = allAccounts[index].Get_Customer();
		OutFile << allAccounts[index].Get_AccNumber() << "\t" << c.Get_Customer_ID() << "\t" << allAccounts[index].Get_Password() << "\t" << allAccounts[index].Get_Balance() << "\t";
		OutFile << allAccounts[index].Get_Branch() << "\t" << c.Get_Name() << "\t" << c.Get_Gender() << "\t" << c.Get_CNIC() << "\t" << c.Get_str_DOB() << "\t" << this->BankName << "\t" << allAccounts[index].Get_Location();
		OutFile << "\n";
	}
	OutFile.close();
}
void Bank::getFileData()
{
	string fileName = "accounts_data.txt";
	ifstream My_File(fileName);
	if (!My_File.is_open())
	{
		cout << "Account File not Found!" << endl;
	}
	else
	{
		string temp;
		getline(My_File, temp, '\n');
		this->accountCount = stoi(temp);

		for (int index = 0; index < accountCount; index++)
		{
			for (int col = 0; col <= 9; col++)
			{
				getline(My_File, temp, '\t');
				//cout << "Test ." << temp<<"." << endl;
				//_getch();

				if (col == 0)
				{
					if (index != 0)
					{
						if (temp[0] == 'S' || temp[0] == 'C')
						{
							temp.erase(0, 51);
						}
						else
						{
							temp.erase(0, 33);
						}
					}
					this->allAccounts[index].Set_AccNumber(temp);
				}
				else if (col == 1)
				{
					this->allAccounts[index].Get_Customer().Set_Customer_ID(temp);
				}
				else if (col == 2)
				{
					this->allAccounts[index].Set_Password(temp);
				}
				else if (col == 3)
				{
					this->allAccounts[index].Set_Balance(stof(temp));
				}
				else if (col == 4)
				{
					if (temp == "Lahore")
					{
						this->allAccounts[index].Set_Branch(LAHORE);
					}
					else if (temp == "Islamabad")
					{
						this->allAccounts[index].Set_Branch(ISLAMABAD);
					}
					else
					{
						this->allAccounts[index].Set_Branch(KARACHI);
					}
				}
				else if (col == 5)
				{
					this->allAccounts[index].Get_Customer().Set_Name(temp);
				}
				else if (col == 6)
				{
					this->allAccounts[index].Get_Customer().Set_Gender(temp);
				}
				else if (col == 7)
				{
					this->allAccounts[index].Get_Customer().Set_CNIC(temp);
				}
				else if (col == 8)
				{
					int Start_Index = 0;
					int count = 0;
					string D_M_Y;
					int day = 1, month = 1, year = 1233;
					for (int index = 0; index <= temp.length(); index++)
					{
						if (temp[index] == '/' || index == temp.length())
						{
							count++;
							D_M_Y = temp.substr(Start_Index, (index - Start_Index));
							Start_Index = index + 1;
							if (count == 1)
							{
								day = stoi(D_M_Y);
							}
							else if (count == 2)
							{
								month = stoi(D_M_Y);
							}
							else if (count == 3)
							{
								year = stoi(D_M_Y);
							}
						}
					}

					this->allAccounts[index].Get_Customer().Set_DOB(day, month, year);
				}
				else if (col == 9)
				{
					//no need to save bank name everytime
				}
			}
			if (My_File.eof())
			{
				break;
			}
		}
	}
}


void Bank::addAccount(Account acc)
{
	if (this->accountCount >= accountLimit) {
		cout << "Account Limit Exceeded! Can't create another account." << endl;
	}
	else
	{
		this->allAccounts[this->accountCount] = acc;
		this->accountCount++;
		cout << "Account added!" << endl;
	}
}
void Bank::changePassword(string uId, string pass)
{
	int index = this->getIndexByUserId(uId);
	this->allAccounts[index].Set_Password(pass);
}

bool Bank::isUniqueID(string id) {
	for (int index = 0; index < accountLimit; index++)
	{
		if (this->allAccounts[index].Get_Customer().Get_Customer_ID() == id)
		{
			return false;
		}
	}
	return true;
}
bool Bank::isValidCredential(string uId, string pass)
{
	for (int index = 0; index < accountLimit; index++)
	{
		if (this->allAccounts[index].Get_Customer().Get_Customer_ID() == uId && this->allAccounts[index].Get_Password() == pass)
		{
			return true;
		}
	}
	return false;
}
string Bank::getBalanceByUserId(string uID)
{
	for (int index = 0; index < accountLimit; index++)
	{
		if (this->allAccounts[index].Get_Customer().Get_Customer_ID() == uID)
		{
			return to_string(this->allAccounts[index].Get_Balance());
		}
	}
	return "";
}
int Bank::getIndexByUserId(string uID)
{
	for (int index = 0; index < accountLimit; index++)
	{
		if (this->allAccounts[index].Get_Customer().Get_Customer_ID() == uID)
		{
			return index;
		}
	}
	return -1;
}
void Bank::deleteAccount(string uId)
{
	int index = this->getIndexByUserId(uId);
	for (int i = index; i < accountLimit - 1; i++)
	{
		this->allAccounts[i] = this->allAccounts[i + 1];
	}
	this->accountCount--;
	this->setFileData();
}






bool Bank::creditAccount(string uID, float val)
{
	int ind = 0;
	for (int index = 0; index < accountLimit; index++)
	{
		if (this->allAccounts[index].Get_Customer().Get_Customer_ID() == uID)
		{
			ind = index;
		}
	}
	if (val > 0)
	{
		this->allAccounts[ind].Set_Balance(this->allAccounts[ind].Get_Balance() + val);
		return true;
	}
	else
	{
		cout << "\'Negative amount can not be credited!" << endl;

		return false;
	}
}
bool Bank::debitAccount(string uID, float val)
{
	int ind = 0;
	for (int index = 0; index < accountLimit; index++)
	{
		if (this->allAccounts[index].Get_Customer().Get_Customer_ID() == uID)
		{
			ind = index;
		}
	}
	if (val > 0 && (this->allAccounts[ind].Get_Balance() - val) >= 0)
	{
		this->allAccounts[ind].Set_Balance(this->allAccounts[ind].Get_Balance() - val);
		return true;
	}
	else if(val < 0)
	{
		cout << "\'Negative amount can not be debited!" << endl;
		return false;
	}
	else
	{
		cout << "\'Not enough balance to deposit this amount!" << endl;
		return false;
	}
}
bool Bank::cashTransfer(string uId1, string uId2, float amount)
{
	int index1 = this->getIndexByUserId(uId1);
	int index2 = this->getIndexByUserId(uId2);

	if (this->debitAccount(uId1, amount))
	{
		if (this->creditAccount(uId2, amount))
		{
			return true;
		}
	}
	cout << "Cash Transfer Failed!" << endl;
	return false;
}


void Bank::getAccountDetails(string uId)
{
	int index = this->getIndexByUserId(uId);
	Customer c = allAccounts[index].Get_Customer();
	cout << "\n" << allAccounts[index].Get_AccNumber() << "\t" << c.Get_Customer_ID() << "\t" << allAccounts[index].Get_Password() << "\t" << allAccounts[index].Get_Balance() << "\t";
	cout << allAccounts[index].Get_Branch() << "\t" << c.Get_Name() << "\t" << c.Get_Gender() << "\t" << c.Get_CNIC() << "\t" << c.Get_str_DOB() << "\t" << this->BankName << "\t" << allAccounts[index].Get_Location();
	cout << "\t\n";
}
void Bank::generateBankReport()
{
	if (accountCount == 0)
	{
		cout << "No Accounts Available To Display!" << endl;
	}
	for (int index = 0; index < accountCount; index++)
	{
		Customer c = allAccounts[index].Get_Customer();
		cout <<"\n" << allAccounts[index].Get_AccNumber() << "\t" << c.Get_Customer_ID() << "\t" << allAccounts[index].Get_Password() << "\t" << allAccounts[index].Get_Balance() << "\t";
		cout << allAccounts[index].Get_Branch() << "\t" << c.Get_Name() << "\t" << c.Get_Gender() << "\t" << c.Get_CNIC() << "\t" << c.Get_str_DOB() << "\t" << this->BankName << "\t" << allAccounts[index].Get_Location();
		cout << "\t\n";
	}
}
void Bank::display_Bank()
{
	cout << "Bank Name: " << this->BankName << endl;
	cout << "Bank Website: " << this->Website << endl;

}
//:::::::::::::::::::::::::::::::::::::::

//:::::::::::::::::::::::::::::::::::::::

//----------Transaction Class------------

class Transaction {
private:
	string transactionId;
	string Type;
	string From;
	string To;
	float Amount;


public:

	Transaction(string type = "", string From = "", string To = "", float Amount = NULL) : Type(type), From(From), To(To), Amount(Amount) {
		this->transactionId = "";
	}
	string getTransactionId()
	{
		return this->transactionId;
	}
	void setTransactionId(string transactionId)
	{
		this->transactionId = transactionId;
	}

	string getFrom()
	{
		return this->From;
	}
	void setFrom(string from)
	{
		this->From = from;
	}

	string getTo()
	{
		return this->To;
	}
	void setTo(string to)
	{
		this->To = to;
	}

	float getAmount()
	{
		return this->Amount;
	}
	void setAmount(float amount)
	{
		this->Amount = amount;
	}

	string getType()
	{
		return this->Type;
	}
	void setType(string type)
	{
		this->Type = type;
	}
};
//:::::::::::::::::::::::::::::::::::::::



//----------Transaction_list Class------------
class Transaction_list {
private:
	Transaction allTransactions[transactionLimit];
	int transactionCount;

public:

	Transaction_list() {
		this->transactionCount = 0;
	}

	void setTransactionData()
	{
		string fileName = "transactions_data.txt";
		ofstream OutFile(fileName, ios::out);
		OutFile << this->transactionCount << "\n";
		for (int index = 0; index < transactionLimit; index++)
		{
			OutFile << this->allTransactions[index].getTransactionId() << "\t" << this->allTransactions[index].getFrom() << "\t" << this->allTransactions[index].getTo() << "\t" << this->allTransactions[index].getAmount() << "\t" << this->allTransactions[index].getType() << "\t";
			OutFile << "\n";
		}
		OutFile.close();
	}
	void getTransactionData()
	{
		string fileName = "transactions_data.txt";
		ifstream My_File(fileName);
		if (!My_File.is_open())
		{
			cout << "Transaction File not Found!" << endl;
		}
		else
		{
			string temp;
			getline(My_File, temp, '\n');
			this->transactionCount = stoi(temp);

			for (int index = 0; index < transactionLimit; index++)
			{
				for (int col = 0; col <= 4; col++)
				{
					getline(My_File, temp, '\t');

					if (col == 0)
					{
						if (index != 0)
						{
							temp.erase(0, 1);
						}
						this->allTransactions[index].setTransactionId(temp);
					}
					else if (col == 1)
					{
						this->allTransactions[index].setFrom(temp);
					}
					else if (col == 2)
					{
						this->allTransactions[index].setTo(temp);
					}
					else if (col == 3)
					{
						this->allTransactions[index].setAmount(stof(temp));
					}
					else if (col == 4)
					{
						this->allTransactions[index].setType(temp);
					}
				}
				if (My_File.eof())
				{
					break;
				}
			}
		}
	}

	void shiftRows()
	{
		for (int i = transactionLimit - 2; i >= 0; i--) {
			// Move the current element to the next position
			this->allTransactions[i + 1] = this->allTransactions[i];
		}
	}
	//Function Overloading (1 for credit/debit and the other for transaction)
	void addTransaction(string type, string From, string To, float Amount)
	{
		this->shiftRows();
		Transaction temp(type, From, To, Amount);
		temp.setTransactionId(to_string(this->transactionCount));
		this->allTransactions[0] = temp;
		this->transactionCount++;
	}
	void addTransaction(string type, string userID, float Amount)
	{
		this->shiftRows();
		Transaction temp(type, userID, userID, Amount);
		temp.setTransactionId(to_string(this->transactionCount));
		this->allTransactions[0] = temp;
		this->transactionCount++;
	}
	
	void generateTransactionHistory()
	{
		cout << "tID\tFrom\tTo\tAmount\tType" << endl;
		for (int index = 0; index < transactionLimit; index++)
		{
			cout << this->allTransactions[index].getTransactionId() << "\t" << this->allTransactions[index].getFrom() << "\t" << this->allTransactions[index].getTo() << "\t" << this->allTransactions[index].getAmount() << "\t" << this->allTransactions[index].getType() << "\n";
			
		}
	}
};


//:::::::::::::::::::::::::::::::::::::::


//----------Admin Class------------

class Admin {
private:
	string username;
	string password;

public:

	Admin(string username = "admin", string password = "1234") : username(username), password(password) {}

	bool validateAdminPass(string, string);
	bool isValidCredentials(Bank& bank, string uId, string pass)
	{
		return bank.isValidCredential(uId, pass);
	}
	void generateBankReport(Bank&);
	void generateAccountReport(Bank&, string);
	void deleteAccount(Bank&, string);


};

void Admin::generateBankReport(Bank& bank) {
	bank.generateBankReport();
}
void Admin::generateAccountReport(Bank& bank, string uId)
{
	bank.getAccountDetails(uId);
}
void Admin::deleteAccount(Bank& bank, string uId)
{
	bank.deleteAccount(uId);
}


bool Admin::validateAdminPass(string username, string pass)
{
	return (this->username == username && this->password == pass) ? true : false;
}


//:::::::::::::::::::::::::::::::::::::::


string GetPassword() {
	string password;
	char ch;
	while ((ch = _getch()) != '\r') { // '\r' is the Enter key
		if (ch == '\b') { // '\b' is the Backspace key
			if (!password.empty()) {
				cout << "\b \b"; // Move cursor back, print space, move cursor back again
				password.pop_back();
			}
		}
		else {
			password += ch;
			cout << '*';
		}
	}
	cout << endl;
	return password;
}
const int rows = 6;
const int cols = 8;

void printMatrix(int matrix[rows][cols]) {
	for (int i = 0; i < rows; ++i) {
		cout << "\t\t\t\t";
		for (int j = 0; j < cols; ++j) {
			if (matrix[i][j] == 1) {
				// Print 1 in white
				cout << "\033[37m1\033[0m ";
			}
			else {
				// Print 0 in green
				cout << "\033[32m0\033[0m ";
			}
		}
		cout << endl;
	}
}
int main()
{
	cout << "\n\n\n\n";
	int matrix[rows][cols] = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1, 1, 0, 1},
		{1, 1, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};

	printMatrix(matrix);

	cout << "\t\t\t\t\t\t\t Patterns in Every Byte...";
	_getch();
	srand(time(0));
	//This bank can handle 50 accounts (for stability)
	//For increasing account limit change Account Limit global variable
	Bank AlfalahBank("Alfalah Bank", "www.alfalah.com");
	AlfalahBank.getFileData();

START:
	system("CLS");
	Admin myAdmin;
	int Login_Choice = 0;

	Transaction_list myTransactions;
	myTransactions.getTransactionData();


	cout << "\t\t\t\t WELCOME TO " << AlfalahBank.Get_BankName() << " !!";
	cout << "\n\n\nDo you want to Login/Signup:\n~~>.:: 1. Login\n~~>.:: 2. Signup\n~~>.:: 3. Exit\n" << endl;
	while (Login_Choice != 1 && Login_Choice != 2 && Login_Choice != 3)
	{
		cout << "Choice: ";
		cin >> Login_Choice;
		if (!cin)
		{
			cout << "Wrong Choice! Please Enter Again:  " << endl;
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		if (Login_Choice == 1)
		{
			//Login
			Login_Choice = 0;
			cout << "\n\nDo you want to Login as:\n~~>.:: 1. Customer\n~~>.:: 2. Admin\n" << endl;
			while (Login_Choice != 1 && Login_Choice != 2)
			{
				cout << "Choice: ";
				cin >> Login_Choice;
				if (!cin)
				{
					cout << "Wrong Choice! Please Enter Again:  " << endl;
					cin.clear();

					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}

				if (Login_Choice == 1)
				{
					//Customer
					string userID;
					string pass;
					int count = 3;
					do
					{
						cout << "Enter your CustomerID: ";
						cin >> userID;
						if (AlfalahBank.isUniqueID(userID))
						{
							cout << "CustomerID not found in records!" << endl;
							count--;
						}
					} while (AlfalahBank.isUniqueID(userID) && count > 0);
					if(!(count > 0))
					{
						cout << "Log In failed! Press any key to go back to Main menu." << endl;
						_getch();
						goto START;
					}
					count = 3;
					do
					{
						cout << "Enter your Password: ";
						pass = GetPassword();
						if (!myAdmin.isValidCredentials(AlfalahBank, userID, pass))
						{
							cout << "Wrong Password!" << endl;
							count--;
						}
					} while (!myAdmin.isValidCredentials(AlfalahBank, userID, pass) && count > 0);
					
					
					if (count > 0)
					{
						// LOGGED IN SUCCESSFULLY
						cout << "Successfully Logged In!" << endl;
						char c = 'n';
						do
						{
							cout << "\nCurrent account balance: " << fixed << setprecision(2) << AlfalahBank.getBalanceByUserId(userID);
							cout << "\n\nChose Operation to perform: \n~~> .::Press 0 for Debit\n~~> .::Press 1 for Credit\n~~> .::Press 2 for Cash Transfer To Another Account\n~~> .::Press 3 for Balance Inquiry\n~~> .::Press 4 for Password Change\n~~> .::Press 5 for Account Delete\n~~> .::Press 6 for Account Details\n~~> .::Press 7 to Sign Out!" << endl;
							int Choice_Input = 0;
							float amount = 0;
							do
							{
								if (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2 && Choice_Input != 3 && Choice_Input != 4 && Choice_Input != 5 && Choice_Input != 6 && Choice_Input != 7)
								{
									cout << "Invalid Input! Try Again: ";
								}
								else
								{
									cout << "Your Choice:";
								}
								cin >> Choice_Input;

							} while (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2 && Choice_Input != 3 && Choice_Input != 4 && Choice_Input != 5 && Choice_Input != 6 && Choice_Input != 7);
							if (Choice_Input == 0)
							{
								//DEBIT
								cout << "Enter Amount to debit: ";
								cin >> amount;
							
								if (AlfalahBank.debitAccount(userID, amount))
								{
									myTransactions.addTransaction("DEBIT", userID, amount);
									myTransactions.setTransactionData();
									cout << "Debit successful! New balance: " << fixed << setprecision(2) << AlfalahBank.getBalanceByUserId(userID) << endl;
								}
								else
								{
									cout << "Debit failed! Balance: " << fixed << setprecision(2) << AlfalahBank.getBalanceByUserId(userID) << endl;
								}

							}
							else if (Choice_Input == 1)
							{
								//CREDIT
								cout << "Enter Amount to credit: ";
								cin >> amount;

								if (AlfalahBank.creditAccount(userID, amount))
								{
									myTransactions.addTransaction("CREDIT", userID, amount);
									myTransactions.setTransactionData();
									cout << "Credit successful! New balance: " << fixed << setprecision(2) << AlfalahBank.getBalanceByUserId(userID) << endl;
								}
								else
								{
									cout << "Credit failed! Balance: " << fixed << setprecision(2) << AlfalahBank.getBalanceByUserId(userID) << endl;
								}
							}
							else if (Choice_Input == 2)
							{
								//Transfer To Another Account
								string userID_2;
								count = 3;
								do
								{
									cout << "Enter the CustomerID of receiver: ";
									cin >> userID_2;
									if (AlfalahBank.isUniqueID(userID_2))
									{
										cout << "CustomerID not found in records!" << endl;
										count--;
									}
								} while (AlfalahBank.isUniqueID(userID_2) && count > 0);
								if (!(count > 0))
								{
									cout << "Cash Transfer failed! Press any key to go back to Main menu." << endl;
									_getch();
									goto START;
								}
								else
								{
									cout << "Enter Amount to send:"; cin >> amount;
									if (AlfalahBank.cashTransfer(userID, userID_2, amount))
									{
										myTransactions.addTransaction("TRANSFER", userID, userID_2, amount);
										myTransactions.setTransactionData();
										cout << "cash Transfer successful! New balance: " << fixed << setprecision(2) << AlfalahBank.getBalanceByUserId(userID) << endl;
									}
									else
									{
										cout << "cash Transfer failed! Balance: " << fixed << setprecision(2) << AlfalahBank.getBalanceByUserId(userID) << endl;
									}
								}


							}
							else if (Choice_Input == 3)
							{
								//BALANCE INQUIRY
								cout << "Account Balance: " << AlfalahBank.getBalanceByUserId(userID) << endl;
							}
							else if (Choice_Input == 4)
							{
								//Password Change
								cout << "Enter new Password:"; cin >> pass;
								AlfalahBank.changePassword(userID,pass);
								cout << "Password Changed!" << endl;
							}
							else if (Choice_Input == 5)
							{
								//Account Delete
								AlfalahBank.deleteAccount(userID);
								goto START;
							}
							else if (Choice_Input == 6)
							{
								//ACCOUNT DETAILS
								AlfalahBank.getAccountDetails(userID);
							}
							else if (Choice_Input == 7)
							{
								//MAIN MENU
								goto START;
							}
							
							cout << "\n\n~~> .:: (Want to perform Another Transaction? (y) - yes (any other key) - no) ::. <~~" << endl;
							c = _getch();
							if (c != 'y') { goto START; }
						} while (c == 'y');
						
					}
					else
					{
						cout << "Log In failed! Press any key to go back to Main menu." << endl;
						_getch();
						goto START;
					}
				}
				else if (Login_Choice == 2)
				{
					//Admin
					string userID;
					string pass;
					int count = 3;
					do
					{
						cout << "Enter a your Admin ID: ";
						cin >> userID;
						cout << "Enter your Password: ";
						pass = GetPassword();
						if (!myAdmin.validateAdminPass(userID,pass))
						{
							cout << "Credentials do not match!" << endl;
							count--;
						}
					} while (!myAdmin.validateAdminPass(userID, pass) && count > 0);
					if (!(count > 0))
					{
						cout << "Log In failed! Press any key to go back to Main menu." << endl;
						_getch();
						goto START;
					}
					else
					{
						cout << "Log In Successful!" << endl;
						char c = 'n';
						do
						{
							cout << "\n\nChose Operation to perform: \n~~> .::Press 0 to Generate All Account Details\n~~> .::Press 1 to Generate one Account's Detail\n~~> .::Press 2 to Delete an Account\n~~> .::Press 3 to Generate all Bank Transaction History\n~~> .::Press 4 to Sign Out!" << endl;
							int Choice_Input = 0;
							float amount = 0;
							do
							{
								if (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2 && Choice_Input != 3 && Choice_Input != 4 && Choice_Input != 5 && Choice_Input != 6 && Choice_Input != 7)
								{
									cout << "Invalid Input! Try Again: ";
								}
								else
								{
									cout << "Your Choice:";
								}
								cin >> Choice_Input;

							} while (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2 && Choice_Input != 3 && Choice_Input != 4 && Choice_Input != 5 && Choice_Input != 6 && Choice_Input != 7);
							if (Choice_Input == 0)
							{
								//Generate All Account Details
								myAdmin.generateBankReport(AlfalahBank);

							}
							else if (Choice_Input == 1)
							{
								//Generate one Account's Detail
								string userID_2;
								int counter = 3;
								do
								{
									cout << "Enter a CustomerID: ";
									cin >> userID_2;
									if (AlfalahBank.isUniqueID(userID_2))
									{
										cout << "CustomerID not found in records!" << endl;
										counter--;
									}
								} while (AlfalahBank.isUniqueID(userID_2) && counter > 0);
								if (!(counter > 0))
								{
									cout << "Account Detail Failed! Press any key to go back to Main menu." << endl;
									_getch();
									goto START;
								}
								else
								{
									myAdmin.generateAccountReport(AlfalahBank, userID_2);
								}
							}
							else if (Choice_Input == 2)
							{
								//Delete an Account
								string userID_2;
								int counter = 3;
								do
								{
									cout << "Enter a CustomerID: ";
									cin >> userID_2;
									if (AlfalahBank.isUniqueID(userID_2))
									{
										cout << "CustomerID not found in records!" << endl;
										counter--;
									}
								} while (AlfalahBank.isUniqueID(userID_2) && counter > 0);
								if (!(counter > 0))
								{
									cout << "Account Deletion Failed! Press any key to go back to Main menu." << endl;
									_getch();
									goto START;
								}
								else
								{
									myAdmin.deleteAccount(AlfalahBank, userID_2);
									cout << "Account Successfully Deleted!" << endl;
								}
							}
							else if (Choice_Input == 3)
							{
								//Generate all Bank Transaction History
								myTransactions.generateTransactionHistory();
							}
							else if (Choice_Input == 4)
							{
								//MAIN MENU
								goto START;
							}


							cout << "\n\n~~> .:: (Want to perform Another Operation? (y) - yes (any other key) - no) ::. <~~" << endl;
							c = _getch();
							if (c != 'y') { goto START; }
						} while (c == 'y');

					}
					

				}
			}
		}
		else if (Login_Choice == 2)
		{
			//Signup
			Account tempAccount = Account();
			string userInput;
			float balanceInput;

			do
			{
				cout << "Enter a unique CustomerID:";
				cin >> userInput;
				if (!AlfalahBank.isUniqueID(userInput))
				{
					cout << "CustomerID already Taken!" << endl;
				}
			} while (!AlfalahBank.isUniqueID(userInput));

			tempAccount.Get_Customer().Set_Customer_ID(userInput);
			cout << "Enter a strong password:";
			cin >> userInput;
			tempAccount.Set_Password(userInput);
			cout << "Enter your Name:";
			cin >> userInput;
			tempAccount.Get_Customer().Set_Name(userInput);

			cout << "Enter Initial Deposit:";
			cin >> balanceInput;
			tempAccount.Set_Balance(balanceInput);
			
			//Randomized Account number
			userInput = "";
			for (int loop = 0; loop < 8; loop++)
			{
				int gen = 0 + rand() % 10;
				userInput += to_string(gen);
			}

			cout << "\nChose your Branch: \n~~> .::Press 0 for Lahore\n~~> .::Press 1 for Islamabad\n~~> .::Press 2 for Karachi" << endl;
			int Choice_Input = 0;
			cout << "Choice: ";
			do
			{
				if (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2)
				{
					cout << "Invalid Choice! Please select 1/2/3: ";
				}
				cin >> Choice_Input;
			} while (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2);


			if (Choice_Input == 0)
			{
				tempAccount.Set_Branch(LAHORE);
				tempAccount.Set_AccNumber("LHR-" + userInput);
			}
			if (Choice_Input == 1)
			{
				tempAccount.Set_Branch(ISLAMABAD);
				tempAccount.Set_AccNumber("ISB-" + userInput);
			}
			if (Choice_Input == 2)
			{
				tempAccount.Set_Branch(KARACHI);
				tempAccount.Set_AccNumber("KHI-" + userInput);
			}

			//gender
			cout << "\nChose your Gender: \n~~> .::Press 0 for Male\n~~> .::Press 1 for Female\n~~> .::Press 2 for Other" << endl;
			Choice_Input = 0;
			cout << "Choice: ";
			do
			{
				if (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2)
				{
					cout << "Invalid Choice! Please select 1/2/3: ";
				}
				cin >> Choice_Input;
			} while (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2);


			if (Choice_Input == 0)
			{
				tempAccount.Get_Customer().Set_Gender("Male");
			}
			if (Choice_Input == 1)
			{
				tempAccount.Get_Customer().Set_Gender("Female");
			}
			if (Choice_Input == 2)
			{
				tempAccount.Get_Customer().Set_Gender("Other");
			}
			cout << "\nEnter your CNIC number:";
			cin >> userInput;
			tempAccount.Get_Customer().Set_CNIC(userInput);
			int d, m, y;
			cout << "\n~~> .;(Enter your DATE OF BIRTH);. <~~\nEnter the Day:" ;
			cin >> d;
			cout << "\nEnter the Month:";
			cin >> m;
			cout << "\nEnter the Year:";
			cin >> y;

			tempAccount.Get_Customer().Set_DOB(d,m,y);
			AlfalahBank.addAccount(tempAccount);
			AlfalahBank.setFileData();

			cout << "\n\n\n\nPress 1 to go back to Main menu\n press 2 to Exit " << endl;
			Choice_Input = 1;
			do
			{
				if (Choice_Input != 1 && Choice_Input != 2)
				{
					cout << "Please Enter a valid Value: " << endl;
				}
				cin >> Choice_Input;
			} while (Choice_Input != 1 && Choice_Input != 2);
			if (Choice_Input == 1)
			{
				goto START;
			}
			else
			{
				cout << "Bank app Exited Successfully! " << endl;
				exit(0);
			}

			
		}
		else if (Login_Choice == 3)
		{
			AlfalahBank.setFileData();
			myTransactions.setTransactionData();
			cout << "Bank app Exited Successfully! " << endl;
			exit(0);

		}
	}
}

