#pragma once
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFinCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{

private:

	enum enCurrencyExchangeOption{eShowListCurrencies = 1, eFindCurrency = 2, 
		eUpdateRate = 3, eCurrencyCalculator = 4, eExit = 5};



    static short ReadCurrenciesMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _ShowListCurrenciesScreen()
    {
        //cout << "\n List Currencies Screen will be here..";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
       // cout << "\n Find Currency Screen will be here..";
        clsFinCurrencyScreen::ShowFindCurrencyScreen();

    }
    static void _ShowUpdateRateScreen()
    {
       // cout << "\n Update Rate Screen will be here..";
        clsUpdateCurrencyScreen::ShowUpdateCurrncyScreen();
    }
    static void _ShowCurrencyCalculatorScreen()
    {
      //  cout << "\n Currency Calculator Screen will be here..";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _GoBackToCurrencyExchangeMenue()
    {
        cout << "\n\nPress any key to go back to Currencies Menue...";
        system("pause>0");
        ShowCurrenciesMenue();

    }

    static  void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeOption CurrencyExchangeOption)
    {


        switch (CurrencyExchangeOption)
        {

        case enCurrencyExchangeOption::eShowListCurrencies:

            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMenue();
            break;


        case enCurrencyExchangeOption::eFindCurrency:

            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;


        case enCurrencyExchangeOption::eUpdateRate:

            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenue();
            break;

        case enCurrencyExchangeOption::eCurrencyCalculator:

            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenue();
            break;

        case enCurrencyExchangeOption::eExit:

            break;

        }

    }

public:

   static void ShowCurrenciesMenue()
    {

       //if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
       //{
       //    return;
       //}

       system("cls");
       _DrawScreenHeader(" Currency Exchange Main Screen");

       cout << setw(37) << left << "" << "===========================================\n";
       cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
       cout << setw(37) << left << "" << "===========================================\n";
       cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
       cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
       cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
       cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
       cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
       cout << setw(37) << left << "" << "===========================================\n";

       _PerformCurrencyExchangeMenueOption((enCurrencyExchangeOption)ReadCurrenciesMenueOption());
    }

};

