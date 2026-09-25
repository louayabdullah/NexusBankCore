#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyScreen : protected clsScreen
{
private:

	static float _ReadRate()
	{
		float NewRate = 0;
		cout << "\nEnter New Rate: ";
		NewRate = clsInputValidate::ReadFloatNumber<float>();
		return NewRate;
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________\n";

	}


public:

	static void ShowUpdateCurrncyScreen()
	{

		_DrawScreenHeader("\t Update Currency Screen");

		string CurrencyCode;
		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code not found, enter another one.";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);
		

		cout << "\nAre you sure you want to Update the rate of this Currency y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\nUpdate Currency Rate:";
			cout << "\n____________________";

			Currency.UpdateRate(_ReadRate());
			cout << "\nCurrency Rate Updated Sccessfully :-)\n\a";
	
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

	}

};

