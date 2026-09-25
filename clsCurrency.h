#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsString.h"

using namespace std;


class clsCurrency
{
private:

    enum enMode{EmptyMode = 0, UpdateMode = 1};

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	


	static clsCurrency _ConvertLineToCurrencyObject(string DataLine, string Separetor = "#//#")
	{
		vector <string> vCurrencys = clsString::Split(DataLine, Separetor);

		return clsCurrency(UpdateMode, vCurrencys[0], vCurrencys[1], vCurrencys[2], stof(vCurrencys[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separetor = "#//#")
	{
		string stCurrencyRecord;

		stCurrencyRecord += Currency.Country() + Separetor;
		stCurrencyRecord += Currency.CurrencyCode() + Separetor;
		stCurrencyRecord += Currency.CurrencyName() + Separetor;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;
	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector <clsCurrency> vCurrencies;
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				vCurrencies.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrencies;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies)
	{

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine = "";
			for (clsCurrency& C : vCurrencies)
			{
					DataLine = _ConvertCurrencyObjectToLine(C);
				    MyFile << DataLine << endl;
			}
			MyFile.close();

		}

	}

	static clsCurrency _GetEmptyObject()
	{
		return clsCurrency(EmptyMode, "", "", "", 0);
	}

	void _Update()
	{
		vector <clsCurrency> vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency& Record : vCurrencies)
		{
			if (Record.CurrencyName() == CurrencyName())
			{
				Record = *this;
				break;
			}

		}
		_SaveCurrencyDataToFile(vCurrencies);
	}

public:

	clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}

			}
		}
	
		return _GetEmptyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if ((clsString::UpperAllString(Currency.Country()) == clsString::UpperAllString(Country)))
				{
					MyFile.close();
					return Currency;
				}

			}
		}

		return _GetEmptyObject();
	}

	static vector <clsCurrency> GetCurrnciseList()
	{
		return _LoadCurrencyDataFromFile();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);
		
		return (!Currency.IsEmpty());
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.Rate());
	}
};

