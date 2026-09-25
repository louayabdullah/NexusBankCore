#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsUpdateUserScreen.h"
#include"clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{

private:

	static short ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	enum enManageUsersMenueOptions{eListUsers = 1, eAddUser = 2,
		eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eExit = 6};


	static void _ShowListUsersScreen()
	{
		//cout << "\n List Users Screen will be here..";
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "\n Add New User Screen will be here..";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "\n Delete User Screen will be here..";
		clsDeleteUserScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "\n Update User Screen will be here..";
		clsUpdateUserScreen::ShowUpdateUserScreen();

	}

	static void _ShowFindUserScreen()
	{
		//cout << "\n Find User Screen will be here..";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToManageUserMenue()
	{
		cout << "\n\nPress any key to go back to Manage Menue...";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
	{

		switch (ManageUsersMenueOption)
		{
		case enManageUsersMenueOptions::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUserMenue();
			break;

		case enManageUsersMenueOptions::eAddUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUserMenue();
			break;

		case enManageUsersMenueOptions::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUserMenue();
			break;

		case enManageUsersMenueOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUserMenue();
			break;

		case enManageUsersMenueOptions::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUserMenue();
			break;

		case enManageUsersMenueOptions::eExit:
			break;


		}

	}

public:


	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
	}

};

