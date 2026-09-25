#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsCurrency.h"
#include "clsInputValidate.h"
class clsFinCurrencyScreen : protected clsScreen
{

private:

	enum enCurrencyOperatorOption{eByCode = 1, eByCountryName = 2};

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

	static void _ShowResults(clsCurrency Currency)
	{

		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n\a";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency is Not Found :-(\n";
		}

	}

	static enCurrencyOperatorOption _ReadCurrencyOperatorOption()
	{
		short Choice = 0;

		cout << "Find By: [1] Code or [2] Country ?";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number between 1 to 2? ");

		return (enCurrencyOperatorOption)Choice;
	}

	static void _FindCurrencyByCurrencyCode()
	{

		string CurrencyCode;

		cout << "\nPlease Enter CurrencyCode: ";
		 CurrencyCode = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_ShowResults(Currency);
	}

	static void _FindCurrencyByCountryName()
	{

		string CountryName;

		cout << "\nPlease Enter CountryName: ";
		CountryName = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
		_ShowResults(Currency);

	}

public:

	static void ShowFindCurrencyScreen()
	{

		_DrawScreenHeader("\t Find Currency Screen");

		enCurrencyOperatorOption CurrencyOperatorOption = _ReadCurrencyOperatorOption();

		switch (CurrencyOperatorOption)
		{
		case enCurrencyOperatorOption::eByCode:
			_FindCurrencyByCurrencyCode();
			break;

		case enCurrencyOperatorOption::eByCountryName:
			_FindCurrencyByCountryName();
			break;
		}
	}
};

//#pragma once
//#include <iostream>
//#include "clsScreen.h"
//#include "clsCurrency.h"
//#include "clsInputValidate.h"
//
//class clsFindCurrencyScreen :protected clsScreen
//{
//
//private:
//	static void _PrintCurrency(clsCurrency Currency)
//	{
//		cout << "\nCurrency Card:\n";
//		cout << "_____________________________\n";
//		cout << "\nCountry    : " << Currency.Country();
//		cout << "\nCode       : " << Currency.CurrencyCode();
//		cout << "\nName       : " << Currency.CurrencyName();
//		cout << "\nRate(1$) = : " << Currency.Rate();
//
//		cout << "\n_____________________________\n";
//
//	}
//
//	static void _ShowResults(clsCurrency Currency)
//	{
//		if (!Currency.IsEmpty())
//		{
//			cout << "\nCurrency Found :-)\n";
//			_PrintCurrency(Currency);
//		}
//		else
//		{
//			cout << "\nCurrency Was not Found :-(\n";
//		}
//	}
//
//public:
//
//	static void ShowFindCurrencyScreen()
//	{
//
//		_DrawScreenHeader("\t  Find Currency Screen");
//
//		cout << "\nFind By: [1] Code or [2] Country ? ";
//		short Answer = 1;
//
//		cin >> Answer;
//
//		if (Answer == 1)
//		{
//			string CurrencyCode;
//			cout << "\nPlease Enter CurrencyCode: ";
//			CurrencyCode = clsInputValidate::ReadString();
//			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
//			_ShowResults(Currency);
//		}
//		else
//		{
//			string Country;
//			cout << "\nPlease Enter Country Name: ";
//			Country = clsInputValidate::ReadString();
//			clsCurrency Currency = clsCurrency::FindByCountry(Country);
//			_ShowResults(Currency);
//		}
//
//
//
//
//
//
//	}
//
//};
