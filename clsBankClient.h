#pragma once
#include <iostream>
#include "clsPerson.h"
#include"clsString.h"
#include <fstream>
#include <vector>
#include <string>
#include"clsMainScreen.h"
#include"Global.h"
#include "clsUser.h"
using namespace std;


class clsBankClient : public clsPerson
{
private:


	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2};
	enMode _Mode;


	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;


	static clsBankClient _CounvertLineToClientObject(string DataLine,string Separetor = "#//#")
	{
		vector <string> vClients = clsString::Split(DataLine, Separetor);

		return clsBankClient(UpdateMode, vClients[0], vClients[1], vClients[2], vClients[3], vClients[4], vClients[5], stof(vClients[6]));
	}

	static string _CounvertClientObjectToLine(clsBankClient Client, string Separetor = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Separetor;
		stClientRecord += Client.LastName + Separetor;
		stClientRecord += Client.Email + Separetor;
		stClientRecord += Client.Phone + Separetor;
		stClientRecord += Client.AccountNumber() + Separetor;
		stClientRecord += Client.PinCode + Separetor;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}

	static vector <clsBankClient> _LoadClientDataFromFile()
	{
		vector <clsBankClient> vClients;
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line = "";

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _CounvertLineToClientObject(Line);

				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine = "";
			for (clsBankClient& C : vClients)
			{
				if (C.MarkedForDelete() == false)
				{
					DataLine = _CounvertClientObjectToLine(C);
					MyFile << DataLine << endl;
			    }
			  
			}
			MyFile.close();
			
		}
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
		}

		MyFile.close();
	}

	void _UpDate()
	{
		vector <clsBankClient> _vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C._AccountNumber ==_AccountNumber)
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_CounvertClientObjectToLine(*this));
	}

	string _PrepareTransferLogRecord(double Amount, clsBankClient DestinationClient,string UserName, string Separetor = "#//#")
	{
		string TransferLogRecord;

		TransferLogRecord += clsDate::GetSystemDateTimeString() + Separetor;
		TransferLogRecord += AccountNumber() + Separetor;
		TransferLogRecord += DestinationClient. AccountNumber() + Separetor;
		TransferLogRecord += to_string(Amount) + Separetor;
		TransferLogRecord += to_string(AccountBalance) + Separetor;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Separetor;
		TransferLogRecord += UserName;

		return TransferLogRecord;
	}

	void _RegisterTransferLog(double Amount, clsBankClient DestinationClient, string UserName)
	{

		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;
		}

		MyFile.close();
	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord TrnsferLogRecord;

		vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
		TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
		TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
		TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
		TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
		TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

		return TrnsferLogRecord;

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(EmptyMode, "", "", "", "", "", "", 0);
	}

public:

	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
		string UserName;

	};

	clsBankClient(enMode Mode ,string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
	{

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	 bool IsEmpty()
	{
		 return (_Mode == enMode::EmptyMode);
	}

	 bool MarkedForDelete()
	 {
		 return _MarkedForDelete;
	 }

	 string AccountNumber()
	 {
		 return _AccountNumber;
	 }

	 void SetPinCode(string PinCode)
	 {
		 _PinCode = PinCode;
	 }

	 string GetPinCode()
	 {
		 return _PinCode;
	 }

	 __declspec(property(get = GetPinCode, put = SetPinCode))  string PinCode;

	 void SetAccontBalance(float AccountBalance)
	 {
		 _AccountBalance = AccountBalance;
	 }

	 float GetAccountBalance()
	 {
		 return _AccountBalance;
	 }

	 __declspec(property(get = GetAccountBalance, put = SetAccontBalance))  float AccountBalance;

	 static clsBankClient Find(string AccountNumber)
	 {
		 vector <clsBankClient> vClients;

		 fstream MyFile;

		 MyFile.open("Clients.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;
			 while (getline(MyFile, Line))
			 {
				 clsBankClient Client = _CounvertLineToClientObject(Line);

				 if (Client.AccountNumber() == AccountNumber)
				 {
					 MyFile.close();
					 return Client;
				 }
				 vClients.push_back(Client);
			 }
			 
		 }
		 MyFile.close();

		 return _GetEmptyClientObject();
	 }

	 static clsBankClient Find(string AccountNumber, string PinCode)
	 {
		 vector <clsBankClient> vClients;

		 fstream MyFile;

		 MyFile.open("Clients.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;
			 while (getline(MyFile, Line))
			 {
				 if (Line != "")
				 {
					 clsBankClient Client = _CounvertLineToClientObject(Line);

					 if (Client.AccountNumber() == AccountNumber && Client._PinCode == PinCode)
					 {
						 MyFile.close();
						 return Client;
					 }
					 vClients.push_back(Client);
				}
			 }
			 
		 }
		 MyFile.close();
		 return _GetEmptyClientObject();
	 }

	 static bool IsClientExist(string AccountNumber)
	 {
		 clsBankClient Client = clsBankClient::Find(AccountNumber);
		 return (!Client.IsEmpty());
	 }

	 enum enSaveResults{svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExist = 2};

	 void Deposit(double Amount)
	 {
		 _AccountBalance += Amount;
		 Save();
	 }

	 bool Witdraw(double Amount)
	 {
		 if (Amount > _AccountBalance)
		 {
			 return false;
		 }
		 else
		 {
			 _AccountBalance -= Amount;
			 Save();
		 }
	 }

	 bool Transfer(double Amount, clsBankClient& DestinationClient ,string UserName)
	 {
		 if (Amount > AccountBalance)
		 {
			 return false;
		 }

		 Witdraw(Amount);
		 DestinationClient.Deposit(Amount);
		 _RegisterTransferLog(Amount, DestinationClient,UserName);
		 return true;
	 }

	 enSaveResults Save()
	 {

		 switch (_Mode)
		 {
		 case enMode::EmptyMode:

			 return enSaveResults::svFaildEmptyObject;

		 case enMode::UpdateMode:

			 _UpDate();

			 return enSaveResults::svSucceeded;
			 break;

			 case enMode::AddNewMode:

			 if (clsBankClient::IsClientExist(_AccountNumber))
			 {
				 return enSaveResults::svFaildEmptyObject;
			 }
			 else
			 {
				 _AddNew();

				 _Mode = enMode::UpdateMode;
				 return enSaveResults::svSucceeded;

			 }
		 }
	 }

	 static clsBankClient GetAddNewClientObject(string AccountNumber)
	 {
		 return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	 }

	 bool Delete()
	 {
		 if (!clsBankClient::IsClientExist(_AccountNumber))
		 {
			 return false;
		 }
		 vector <clsBankClient> _vClients = _LoadClientDataFromFile();

		 for (clsBankClient& C : _vClients)
		 {
			 if (C.AccountNumber() == _AccountNumber)
			 {
				 C._MarkedForDelete = true;
				 break;
			 }

		 }

		 _SaveClientsDataToFile(_vClients);

		 *this = _GetEmptyClientObject();
		 return true;
	 }

	static vector <clsBankClient> GetClientsList()
	 {
		 return _LoadClientDataFromFile();
	 }

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient& Client : vClients)
		{
			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;
	}

	static vector <stTransferLogRecord> GetTransferLogList()
	{
		vector <stTransferLogRecord> vTransferLogRecord;
		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line = "";

			stTransferLogRecord TransferLogRecord;

			while (getline(MyFile, Line))
			{
				TransferLogRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferLogRecord);
			}

			MyFile.close();

		}
		return vTransferLogRecord;
	}

//void Print()
	 //{
		// cout << "\nClient Card:";
		// cout << "\n___________________";
		// cout << "\nFirstName   : " << FirstName;
		// cout << "\nLastName    : " << LastName;
		// cout << "\nFull Name   : " << FullName();
		// cout << "\nEmail       : " << Email;
		// cout << "\nPhone       : " << Phone;
		// cout << "\nAcc. Number : " << _AccountNumber;
		// cout << "\nPassword    : " << _PinCode;
		// cout << "\nBalance     : " << _AccountBalance;
		// cout << "\n___________________\n";
	 //}
};

