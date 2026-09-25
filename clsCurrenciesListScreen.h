#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsCurrency.h"

class clsCurrenciesListScreen : protected clsScreen
{

private:

	static void _PrintCurrencyRecordLine(clsCurrency Currencies)
	{
		cout << setw(8) << left << "" << "| " << left << setw(30) << Currencies.Country();
		cout << "| " << left << setw(10) << Currencies.CurrencyCode();
		cout << "| " << left << setw(40) << Currencies.CurrencyName();
		cout << "| " << left << setw(10) << Currencies.Rate();
	}



public:

	static void ShowCurrenciesListScreen()
	{

		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrnciseList();

		string Title = "\t Currencies List Screen";
		string SubTitle = "\t (" + to_string(vCurrencies.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(2) << left << "" << "\n\t_________________________________________";
		cout << "________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(30) << "Currency";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(2) << left << "" << "\n\t_________________________________________";
		cout << "________________________________________________________\n" << endl;


		if (vCurrencies.size() == 0)
	
			cout << "\t\t\t\t No Currencies Available In the system";
	
		else

			for (clsCurrency& Currency : vCurrencies)
			{
				_PrintCurrencyRecordLine(Currency);
				cout << endl;
			}

		cout << setw(2) << left << "" << "\n\t__________________________________________";
		cout << "________________________________________________________\n" << endl;


	}


};

