#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include <iomanip>

class clsDeleteClientScreen : protected clsScreen
{
private:
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

	 static void ShowDeleteClientScreen()
	{
		 if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		 {
			 return;
		 }

		 _DrawScreenHeader("\tDelete Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Client Account Number:";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose anthor one: ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		char Answer = 'n';

		cout << "\nAre you sure you want to delete this client y/n?";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client1.Delete())
			{

				cout << "\nClient Deleted Successfully :-)\n";
				_PrintClient(Client1);
				return;
			}
			else
			{
				cout << "\nError nClient was not Deleted\n";
				return;
			}

		}



	}
};

