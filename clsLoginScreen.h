#pragma once
#include <iostream>
#include"clsMainScreen.h"
#include "clsScreen.h"
#include"clsUser.h"
#include"Global.h"
#include "clsUtil.h"

class clsLoginScreen : protected clsScreen
{
private:
	
	static bool _Login()
	{
		
		string UserName, Password;

		bool LoginFailed = false;

		short FailedLoginCount = 0;
		
		do
		{
			if (LoginFailed)
			{
				FailedLoginCount++;


				cout << "\nInVlaid UserName/Password\n";

				cout << "You have " << (3 - FailedLoginCount) << " Trial(s) to login.\n";
				
			}

			if (FailedLoginCount == 3)
			{
				cout << "\nYou are locked after 3 faild trails\n";

				return false;
			}


			cout << "\nEnter UserName? ";
			cin >> UserName;

			cout << "\nEnter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);
		
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();

		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();

	}
};

