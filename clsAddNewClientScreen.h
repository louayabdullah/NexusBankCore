#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include <iomanip>

class clsAddNewClientScreen : protected clsScreen
{

private:

	static void ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber<double>();

	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:

	static void AddNewClient()
	{


		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}


		string AccountNumber = "";

		_DrawScreenHeader("\tAdd New Client Screen");

		cout << "\nPlease Enter Account Number:";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already Used, enter choose anthor one: ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


		ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:

			cout << "\nAccount Addeded Successfully :-)\n";
			_PrintClient(NewClient);
			//NewClient.Print()
			break;

		case clsBankClient::enSaveResults::svFaildEmptyObject:

			cout << "\nError account was not saved because it's Empty";
			break;

		case clsBankClient::enSaveResults::svFaildAccountNumberExist:

			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
	}

};

