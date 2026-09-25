#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
class clsDeleteUserScreen : protected clsScreen
{

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Info:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUserName    : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}


public:
	static void ShowDeleteClientScreen()
	{

		_DrawScreenHeader("\tDelete User Screen");

		string UserName = "";

		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUserName is not found, choose anthor one: ";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);

		char Answer = 'n';

		cout << "\nAre you sure you want to delete this User y/n?";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (User1.Delete())
			{

				cout << "\User Deleted Successfully :-)\n";
				_PrintUser(User1);
				return;
			}
			else
			{
				cout << "\nError User was not Deleted\n";
				return;
			}

		}


	}

};

