#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:



	static float _ReadAmount()
	{
		float Amount = 0;
		cout << "\nEnter Amount to Exchange: ";
		Amount = clsInputValidate::ReadFloatNumber<float>();
		return Amount;
	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{
		cout <<  "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________\n";

	}



	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD " << endl;

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrencyCard(Currency2,"To:");
		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);
		cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << Currency2.CurrencyCode() << endl;
	}



	static clsCurrency _GetCurrency(string Massage)
	{
		string CurrencyCode;
		cout << Massage;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code not found, enter another one.";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'Y';

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");

			_DrawScreenHeader("\t Calculator Currency Screen");


			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");

			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

				cout << "\nDo you want to perform another calculation? y/n?";
				cin >> Continue;
		}

	}
};
