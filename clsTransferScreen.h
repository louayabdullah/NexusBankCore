#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"

class clsTransferScreen : protected clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadSourceClientAccountNumber()
    {
        string SourceClientAccountNumber;
        cout << "\nPlease Enter Account Number to transfer From:";
        SourceClientAccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(SourceClientAccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            SourceClientAccountNumber = clsInputValidate::ReadString();
        }

        return SourceClientAccountNumber;
    }

    static string _ReadDestinationClientAccountNumber()
    {
        string DestinationClientAccountNumber;
        cout << "\nPlease Enter Account Number to transfer Tow:";
        DestinationClientAccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(DestinationClientAccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            DestinationClientAccountNumber = clsInputValidate::ReadString();
        }

        return DestinationClientAccountNumber;
    }

    static double _ReadAmount(clsBankClient SourceClient)
    {
        double Amount = 0;

        cout << "\nEnter Transfer Amount? ";
        Amount = clsInputValidate::ReadDblNumber<double>();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter anthor Amount?";
            Amount = clsInputValidate::ReadDblNumber<double>();
        }

        return Amount;
    }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t Transfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadSourceClientAccountNumber());

        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadDestinationClientAccountNumber());

        _PrintClient(DestinationClient);

        double Amount = 0;

        Amount = _ReadAmount(SourceClient);

        char Answer = 'n';

        cout << "\nAre you sure you want to Perform this Oparetion y/n?";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
            {
                cout << "\nTransfer done successfully.\n";
            }
            else
            {
                cout << "\nTransfer Faild\n";
                return;
            }
        }
        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);

    }
};

//
//public:
//	static void ShowTransferScreen()
//	{
//		string AcountNumber1;
//
//        _DrawScreenHeader("\t Transfer Screen");
//
//        cout << "\nPlease Enter Account Number to transfer From: ";
//        AcountNumber1 = clsInputValidate::ReadString();
//
//        while (!clsBankClient::IsClientExist(AcountNumber1))
//        {
//            cout << "\nAccount number is not found, choose another one: ";
//            AcountNumber1 = clsInputValidate::ReadString();
//        }
//
//        clsBankClient Client1 = clsBankClient::Find(AcountNumber1);
//        _PrintClient(Client1);
//
//
//        string AcountNumber2;
//        cout << "\nPlease Enter Account Number to transfer To: ";
//        AcountNumber2 = clsInputValidate::ReadString();
//
//        while (!clsBankClient::IsClientExist(AcountNumber2))
//        {
//            cout << "\nAccount number is not found, choose another one: ";
//            AcountNumber2 = clsInputValidate::ReadString();
//        }
//
//        clsBankClient Client2 = clsBankClient::Find(AcountNumber2);
//        _PrintClient(Client2);
//
//        double Amount = 0;
//
//        cout << "\nEnter Transfer Amount? ";
//        Amount = clsInputValidate::ReadDblNumber();
//
//        while (Amount > Client1.AccountBalance)
//        {
//            cout << "\nAmount Exceeds the available Balance, Enter anthor Amount?";
//            Amount = clsInputValidate::ReadDblNumber();
//        }
//
//
//        char Answer = 'n';
//
//        cout << "\nAre you sure you want to Perform this Oparetion y/n?";
//        cin >> Answer;
//
//        if (Answer == 'Y' || Answer == 'y')
//        {
//            Client1.Witdraw(Amount);
//            Client2.Deposit(Amount);
//            cout << "\nTransfer done successfully.";
//        }
//        else
//        {
//            cout << "\nOperation was cancelled.\n";
//            return;
//        }
//        _PrintClient(Client1);
//        _PrintClient(Client2);
//	}
//
//};

