#pragma once
#include <iostream>
#include "clsUtil.h"
#include"Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t  " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t  " << SubTitle;
		}
		cout << "\n\t\t\t\t\t______________________________________\n\n";
		_DrawScreenDateUser();
	
    }

	static bool CheckAccessRights(clsUser::enPermissions Permissions)
	{
		if (!CurrentUser.CheckAccessPermissions(Permissions))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Conact Your Admin.\n";
			cout << "\t\t\t\t\t______________________________________\n";
			return false;
		}
		else
		{
			return true;
		}

	}

	static void _DrawScreenDateUser()
	{
		cout << "\t\t\t\t\t"  << "User: " << CurrentUser.UserName << endl;
		cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << endl;
	}

};

