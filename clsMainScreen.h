#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientsListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"clsrLogInRegisteScreen.h"
#include"clsCurrencyExchangeScreen.h"
#include"clsLoginScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrencyExchangeMenue = 9, eExit = 10
	};


	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]?";
		short Choice = clsInputValidate::ReadFloatNumberBetween(1, 10, "Invalid Number, Enter again\n");

		return Choice;
	}

	static void _ShowAddNewClientsScreen()
	{
		//cout << "\nAdd New Clients Screen Will be here...\n";

		clsAddNewClientScreen::AddNewClient();
	}

	static void _ShowAllClientsScreen()
	{
		//cout << "\nAll Clients Screen Will be here...\n";

		clsClientsListScreen::ShowClientsList();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "\nDelete Client Screen Will be here...\n";

		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screen Will be here...\n";

		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen Will be here...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}  

	static void _ShowTransactionsMenue()
	{
		//cout << "\nTransactions Menue Screen Will be here...\n";

		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowManageUsersMenue()
	{
		//cout << "\nManage Users Menue Screen Will be here...\n";
		clsManageUsersScreen::ShowManageUsersMenue();

	}

	static void _ShowLoginRegisterScreen()
	{
		//cout << "\nRegister LogIn Screen Screen Will be here...\n";

		clsrLogInRegisteScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeMenue()
	{
		clsCurrencyExchangeScreen::ShowCurrenciesMenue();
	}

	//static void _ShowEndScreen()
	//{
	//	//cout << "\nEnd Screen Will be here...\n";
	//
	//}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowMainMenue();
	}

	static void _PerformMainMenueOptions(enMainMenueOptions MainMenueOption)
	{

		switch (MainMenueOption)
		{
		case enMainMenueOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eShowTransactionsMenue:
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();

			break;

		case enMainMenueOptions::eManageUsers:
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eCurrencyExchangeMenue:
			system("cls");
			_ShowCurrencyExchangeMenue();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eExit:
			system("cls");
			_Logout();
			//_ShowEndScreen();
			

			break;
		}
	}
public:
	static void ShowMainMenue()
	{

		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Register LogIn.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformMainMenueOptions((enMainMenueOptions)_ReadMainMenueOption());



	}

};




