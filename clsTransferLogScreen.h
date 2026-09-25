#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{
private:


	static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
		cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.srcBalanceAfter;
		cout << "| " << setw(10) << left << TransferLogRecord.destBalanceAfter;
		cout << "| " << setw(8) << left << TransferLogRecord.UserName;


	}


public:

	static void ShowTransferLogScreen()
	{

	     	vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

			string Title = "\t Transfer Log List Screen";
			string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

			_DrawScreenHeader(Title, SubTitle);


			cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
			cout << "_________________________________________________\n" << endl;

			cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
			cout << "| " << left << setw(12) << "s.Acct";
			cout << "| " << left << setw(12) << "d.Acct";
			cout << "| " << left << setw(12) << "Amount";
			cout << "| " << left << setw(12) << "s.Balance";
			cout << "| " << left << setw(12) << "d.Balance";
			cout << "| " << left << setw(12) << "User";
			cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
			cout << "_________________________________________________\n" << endl;

			if (vTransferLogRecord.size() == 0)
				cout << "\t\t\t\tNo Transfer Log Record Available In the System!";
			else

				for (clsBankClient::stTransferLogRecord& Record : vTransferLogRecord)
				{

					PrintTransferLogRecordLine(Record);
					cout << endl;
				}

			cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
			cout << "_________________________________________________\n" << endl;

	}
};

