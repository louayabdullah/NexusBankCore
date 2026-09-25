#pragma once
#include <string>
#include"clsDate.h";


class clsUtil
{

public:

    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };


    enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static  string Tabs(int NumberOfTabs)
    {
        string t = "";

        for (char i = 1; i <= NumberOfTabs; i++)
        {
            t += "\t";

        }

        return t;
    }

    static int ReadPositiveNumber(string Message)
    {
        int Number = 0;
        do
        {
            cout << Message << endl;
            cin >> Number;

        } while (Number <= 0);

        return Number;

    }

    static enPrimeNotPrime CheckPrime(int Number)
    {

        int M = round(Number / 2);

        for (int Counter = 2; Counter <= M; Counter++)
        {

            if (Number % Counter == 0)
            {
                return enPrimeNotPrime::NotPrime;

            }

        }

        return enPrimeNotPrime::Prime;
    }

    static void PrintPrimeNumberFrom1ToN(int Number)
    {

        for (int i = 1; i <= Number; i++)
        {

            if (CheckPrime(i) == enPrimeNotPrime::NotPrime)
            {
                cout << i << endl;
            }

        }

    }

    static bool isPerfectNumber(int Number)
    {
        int Sum = 0;



        for (int Counter = 1; Counter < Number; Counter++)
        {

            if (Number % Counter == 0)
            {
                Sum += Counter;

            }


        }

        return Number == Sum;
    }

    static void PrintPerfeNumbersFrom1ToN(int Number)
    {
        for (int i = 1; i <= Number; i++)
        {
            if (isPerfectNumber(i))
            {
                cout << i << endl;

            }


        }



    }

    static int ReveresNumber(int Number)
    {
        int Remainder = 0, Number2 = 0;

        while (Number > 0)
        {

            Remainder = Number % 10;
            Number = Number / 10;

            Number2 = Number2 * 10 + Remainder;



        }
        return Number2;

    }

    static int SumOfDigites(int Number)
    {
        int Sum = 0;
        int Remainder = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;

            Sum += Remainder;
        }
        return Sum;
    }

    static int CountDigitFrequency(short DigitToCheck, int Number)
    {
        int Remainder = 0, FreqCount = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;

            if (DigitToCheck == Remainder)
            {
                FreqCount++;
            }



        }

        return FreqCount;


    }

    static void PrintAallDigitFrequency(int Number)
    {

        for (int i = 1; i <= 9; i++)
        {


            int DigitFrequency = 0;
            DigitFrequency = CountDigitFrequency(i, Number);

            if (DigitFrequency)
            {

                cout << "Digit " << i << " Frequency is " << DigitFrequency << " Time(s)" << endl;

            }

        }


    }

    static void PrintDigits(int Number)
    {

        int Remainder = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;

            Number = Number / 10;

            cout << Remainder << endl;
        }



    }

    static bool IsPalindromeNumber(int Number)
    {
        return Number == (ReveresNumber(Number));
    }

    static void PrintInvertedNumberPattren(int Number)
    {
        cout << "\n";
        for (int i = Number; i >= 1; i--)
        {

            for (int j = 1; j <= i; j++)
            {

                cout << i;

            }
            cout << "\n";
        }






    }

    static void PrintLetterPattren(int Number)
    {
        cout << "\n";
        for (int i = 65; i <= 65 + Number - 1; i++)
        {
            for (int j = 1; j <= i - 65 + 1; j++)
            {

                cout << char(i);
            }

            cout << "\n";

        }

    }

    static void Print_AllWords_From_AAA_To_ZZZ()
    {

        cout << "\n";

        string Word = "";

        for (int i = 65; i <= 90; i++)
        {

            for (int j = 65; j <= 90; j++)
            {

                for (int k = 65; k <= 90; k++)
                {
                    Word += char(i);
                    Word += char(j);
                    Word += char(k);

                    cout << Word << endl;

                    Word = "";


                }


            }

        }

    }

    static string ReadPassword()
    {
        string Password = "";

        cout << "Please enter a 3_Letter  Password (all capital) ?\n" << endl;
        cin >> Password;

        return Password;
    }

    static bool GuessPassword(string OriginalPassword)
    {
        string Word = "";
        int Counter = 0;
        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {

                for (int k = 65; k <= 90; k++)
                {
                    Counter++;

                    Word += char(i);
                    Word += char(j);
                    Word += char(k);
                    cout << "Trial [ " << Counter << " ] : " << Word << endl;
                    if (Word == OriginalPassword)
                    {
                        cout << "\n";
                        cout << "\nPassword is " << Word << endl;
                        cout << "\nFound after [" << Counter << " ] trial(s)\n";
                        return true;

                    }
                    Word = "";
                }

            }
        }
        return false;

    }

    static string ReadText()
    {
        string Text = "";

        cout << "Please enter Text ?" << endl;
        getline(cin, Text);

        return Text;
    }

    static string EncryptText(string Text, const short  EncrptionKey = 10)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncrptionKey);
        }
        return Text;
    }

    static string DecryptText(string Text, const short EncrptionKey = 10 )
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncrptionKey);
        }
        return Text;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        //updated this method to accept mixchars
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {

        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word = "";

        for (int i = 1; i <= Length; i++)
        {
            Word += GetRandomCharacter(CharType);

        }
        return Word;
    }

    static  string GenerateKey(enCharType CharType = CapitalLetter)
    {

        string Key = "";
        Key += GenerateWord(CharType, 4) + "-" +
            GenerateWord(CharType, 4) + "-" +
            GenerateWord(CharType, 4) + "-" +
            GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(int NumberOfKeys, enCharType CharType)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {

            cout << "Key [" << i << "] : " << GenerateKey(CharType) << endl;

        }


    }

    static void ReadArray(int arr[100], int& arrLength)
    {
        cout << "Enter Number of element ?" << endl;
        cin >> arrLength;
        cout << "Enter Array Elementes:?" << endl;
        for (int i = 0; i < arrLength; i++)
        {

            cout << "Element [ " << i << " ] : " << endl;
            cin >> arr[i];
        }


    }

    static  void PrintArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {

            cout << arr[i] << " ";
        }


    }

    static int TimesRepeated(int Number, int arr[100], int arrLength)
    {
        int Count = 0;
        for (int i = 0; i < arrLength; i++)
        {

            if (Number == arr[i])
            {
                Count++;
            }


        }
        return Count;
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, int Wordlength)
    {


        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);
    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {


        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = 0;

        {
            for (int i = 0; i < arrLength; i++)


                if (arr[i] > Max)
                {
                    Max = arr[i];

                }

        }
        return Max;

    }

    static int MinNumberInArray(int arr[100], int arrLength)
    {

        int Min = 0;
        Min = arr[0];
        {
            for (int i = 0; i < arrLength; i++)


                if (arr[i] < Min)
                {
                    Min = arr[i];

                }

        }

        return Min;


    }

    static int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;

        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];

        }
        return Sum;

    }

    static float AverageArray(int arr[100], int arrLength)
    {
        return (float)SumArray(arr, arrLength) / arrLength;
    }

    static void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            arrDestination[i] = arrSource[i];
        }

    }

    static void CopyOnlyPrimeNumberArray(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
            {
                arrDestination[Counter] = arrSource[i];
                Counter++;
            }
        }

        arr2Length = --Counter;
    }

    static void Swap(int& A, int& B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(double& A, double& B)
    {
        double Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string& A, string& B)
    {
        string Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);

    }

    static void ShuffleArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);

        }


    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);

        }


    }

    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }


};
