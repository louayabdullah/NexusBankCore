#include <iostream>
#include "clsLoginScreen.h"
using namespace std;


template <typename T> T MyMax(T Number1, T Number2)
{
	return (Number1 > Number2) ? Number1 : Number2;

}


template <class T>
class Calculator
{
private:

    T Number1, Number2;

public:

    Calculator(T n1, T n2)
    {
        Number1 = n1;
        Number2 = n2;
    }

    void PrintResults()
    {
        cout << "Numbers: " << Number1 << " and " << Number2 << "." << endl;

        cout << Number1 << " + " << Number2 << " = " << Add() << endl;

        cout << Number1 << " - " << Number2 << " = " << Subtract() << endl;

        cout << Number1 << " * " << Number2 << " = " << Multiply() << endl;

        cout << Number1 << " / " << Number2 << " = " << Divide() << endl;
    }

    T Add()
    {
        return Number1 + Number2;
    }

    T Subtract()
    {
        return Number1 - Number2;
    }

    T Multiply()
    {
        return Number1 * Number2;
    }

    T Divide()
    {
        return Number1 / Number2;
    }
};

int main()
{

	//while (true)
	//{
	//	if (!clsLoginScreen::ShowLoginScreen())
	//	{
	//		break;
	//	}
	//}




    Calculator<int> intCalc(2, 1);
    Calculator<float> floatCalc(2.4, 1.2);

    cout << "int Results:" << endl;
    intCalc.PrintResults();

    cout << endl;

    cout << "float Results:" << endl;
    floatCalc.PrintResults();


	//cout << MyMax <int>(3, 7) << endl;
	//cout << MyMax <float>(8.5, 7.9) << endl;
	//cout << MyMax <double>(2.999, 1.9999) << endl;
	//cout << MyMax <char>('a','b') << endl;


	return 0;
}

