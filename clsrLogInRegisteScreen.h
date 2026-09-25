#pragma once
#pragma once
#include <iostream>
#include"clsMainScreen.h"
#include "clsScreen.h"
#include"clsUser.h"
#include"Global.h"

class clsrLogInRegisteScreen : protected clsScreen
{
private:
    static void _PrintLogInRegisteRecordLine(clsUser::stLoginRegisterRecord LoginRegisteRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(40) << left << LoginRegisteRecord.DateTime;
        cout << "| " << setw(25) << left << LoginRegisteRecord.UserName;
        cout << "| " << setw(15) << left << LoginRegisteRecord.Password;
        cout << "| " << setw(12) << left << LoginRegisteRecord.Permissions;

    }

public:

    static void ShowLoginRegisterScreen()
    {

        if (!clsScreen::CheckAccessRights(clsUser::pShowLoginRegister))
        {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> vLogInRegisteRecord = clsUser::GetLoginRegisterList();

        string Title = "\t   Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vLogInRegisteRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(40) << "Date/Time";
        cout << "| " << left << setw(25) << "UserName";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vLogInRegisteRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord &Record : vLogInRegisteRecord)
            {

                _PrintLogInRegisteRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

