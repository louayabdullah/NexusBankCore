#pragma once
#include <iostream>
#include <string>
#include "clsInputValidate.h";
#include"clsBankClient.h"
#include"clsPerson.h"
#include<fstream>
#include "clsDate.h"
#include "clsUtil.h"


using namespace std;

class clsUser : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };


	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	string _RegisterLogIn;
	bool _MarkedForDelete = false;
	

	static clsUser _CounvertLineToUserObject(string DataLine, string Separetor = "#//#")
	{
		vector <string> vUser;

		vUser = clsString::Split(DataLine, Separetor);

		return clsUser(UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], clsUtil::DecryptText(vUser[5]), stoi(vUser[6]));


	}

	static string _CounvertUserObjectToLine(clsUser User, string Separetor = "#//#")
	{
		string stUserToLine = "";
		stUserToLine += User.FirstName + Separetor;
		stUserToLine += User.LastName + Separetor;
		stUserToLine += User.Email + Separetor;
		stUserToLine += User.Phone + Separetor;
		stUserToLine += User.UserName + Separetor;
		stUserToLine += clsUtil::EncryptText(User.Password) + Separetor;
		stUserToLine += to_string(User.Permissions);
		return stUserToLine;
	}

	 string _PrepaerLogInRecord(string Separetor = "#//#")
	{
		string stLoginRecord = "";
		stLoginRecord += clsDate::GetSystemDateTimeString()+ Separetor;
		stLoginRecord += UserName + Separetor;
		stLoginRecord += clsUtil::EncryptText(Password)  + Separetor;
		stLoginRecord += to_string(Permissions);
		return stLoginRecord;
	}

	 struct stLoginRegisterRecord;
	 static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string DataLine, string Separetor = "#//#")
	 {

		 stLoginRegisterRecord LoginRegisterRecord;

		 vector <string> LoginRegisterDataLine = clsString::Split(DataLine, Separetor);
		 LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		 LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		 LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
		 LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

		 return LoginRegisterRecord;
	 }

    static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> _vUsers;
		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{
				clsUser Users = _CounvertLineToUserObject(Line);
				_vUsers.push_back(Users);
			}
			MyFile.close();
		}

		return _vUsers;
	} 

	static void _SaveUserDataLineToFile(vector <clsUser> vUsers)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{

			string DataLine = "";
			for (clsUser& U : vUsers)
			{
				if (U._MarkedForDelete == false)
				{
					DataLine = _CounvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}

			}
			MyFile.close();
		}
	}

     void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;

		MyFile.open("Users.txt",ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
		}
		MyFile.close();

	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(EmptyMode, "", "", "", "", "", "", 0);
	}

	void _Update()
	{

		vector <clsUser> _vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U._UserName == _UserName)
			{
				U = *this;
				break;
			}


		}

		_SaveUserDataLineToFile(_vUsers);

	}

	void _AddNewUser()
	{
		_AddDataLineToFile(_CounvertUserObjectToLine(*this));
	}

public:


	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pShowLoginRegister = 128
	};


    struct stLoginRegisterRecord
    {
		string DateTime;
		string UserName;
		string Password;
        int Permissions;
	};

    bool CheckAccessPermissions(enPermissions Permission)
    {
		if (this->Permissions == enPermissions::eAll)

			return true;

		if ((Permission & this->Permissions) == Permission)

			return true;
		else
			return false;

	}

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}
	
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


	static clsUser Find(string UserName)
	{
		vector <clsUser> vUsers;
		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsUser User = _CounvertLineToUserObject(Line);

				if (User._UserName == UserName)
				{
					MyFile.close();
					return User;
					
				}

				vUsers.push_back(User);
			}
		}
		MyFile.close();
		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName,string Password)
	{
		vector <clsUser> vUsers;
		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsUser User = _CounvertLineToUserObject(Line);

				//string EncreyptPassword = clsUtil::EncryptText(Password, 10);

				if (User._UserName == UserName && User._Password == Password)
				{
					MyFile.close();
					return User;

				}

				vUsers.push_back(User);
			}
		}
		MyFile.close();
		return _GetEmptyUserObject();

	}

	static bool IsUserExist(string UserName)
	{
		clsUser User1 = clsUser::Find(UserName);

		return (!User1.IsEmpty());
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	enum SaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExist = 2 };

	bool Delete()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				U._MarkedForDelete = true;
				break;
			}
		}

		_SaveUserDataLineToFile(vUsers);

		*this = _GetEmptyUserObject();
		return true;
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	SaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:

			if (IsEmpty())
			{
				return SaveResults::svFaildEmptyObject;
				break;
			}

		case enMode::UpdateMode:

			_Update();
			return SaveResults::svSucceeded;
			break;

		case enMode::AddNewMode:

			if (IsUserExist(UserName))
			{
				return SaveResults::svFaildAccountNumberExist;
			}
			else
			{
				_AddNewUser();

				_Mode = enMode::UpdateMode;
				return SaveResults::svSucceeded;
				break;
			}
		}

	}

    void RegisterLogIn()
	{
		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			string DataLine = "";
			DataLine = _PrepaerLogInRecord();

			if (DataLine != "")
			{
				MyFile << DataLine << endl;
			}

			MyFile.close();
		}
	}

	static vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vLoginRegisterRecord;
		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line;
			stLoginRegisterRecord LoginRegisterRecord;

			while (getline(MyFile, Line))
			{
				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

				vLoginRegisterRecord.push_back(LoginRegisterRecord);
			}
			MyFile.close();
		}

		return vLoginRegisterRecord;
	}

	void Print()
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nUserName    : " << UserName;
		cout << "\nPassword    : " << Password;
		cout << "\nPermissions : " << Permissions;
		cout << "\n___________________\n";

	}


};
