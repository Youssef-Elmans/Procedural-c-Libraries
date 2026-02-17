#pragma once
#include<iostream>
using namespace std;
class clsInputValidation
{
public:

	static int ReadIntNumber(string Message,string ErrorMessage="Invalid Number , Enter a Valid One : \n")
	{
		int Number;
		cout << Message << endl;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}

	static int ReadPositiveIntNumber(string Message)
	{
		int Number = 0;
		do
		{
			Number = ReadIntNumber(Message);
		} while (Number <= 0);

		return Number;
	}


	static short ReadShortNumber(string Message, string ErrorMessage = "Invalid Number , Enter a Valid One : \n")
	{
		short Number;
		cout << Message << endl;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	static short ReadPositiveShortNumber(string Message)
	{
		short Number = 0;
		do
		{
			Number = ReadShortNumber(Message);
		} while (Number <= 0);
		return Number;
	}
	static float ReadFloatNumber(string Message, string ErrorMessage = "Invalid Number , Enter a Valid One : \n")
	{
		float Number;
		cout << Message << endl;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	static float ReadPositiveFloatNumber(string Message)
	{
		float Number = 0;
		do
		{
			Number = ReadFloatNumber(Message);
		} while (Number <= 0);

		return Number;
	}
	static double ReadDoubleNumber(string Message, string ErrorMessage = "Invalid Number , Enter a Valid One : \n")
	{
		double Number;
		cout << Message << endl;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	static double ReadPositiveDoubleNumber(string Message)
	{
		double Number = 0;
		do
		{
			Number = ReadDoubleNumber(Message);
		} while (Number <= 0);

		return Number;
	}
	static long ReadLongNumber(string Message, string ErrorMessage = "Invalid Number , Enter a Valid One : \n") {
		long Number;
		cout << Message << endl;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	static long ReadPositiveLongNumber(string Message)
	{
		long Number = 0;
		do
		{
			Number = ReadLongNumber(Message);
		} while (Number <= 0);

		return Number;
	}
	static bool ReadBoolNumber(string Message, string ErrorMessage = "Invalid Number , Enter a Valid One : \n") {
		bool Number = false;
		do {
			cout << Message << endl;
			cin >> Number;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << ErrorMessage;
				cin >> Number;
			}
		} while (Number > 1 || Number < 0);
		return Number;
	}

	static bool IsNumberBetween(int From, int To, int ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	static bool IsNumberBetween(short From, short To, short ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	static bool IsNumberBetween(float From, float To, float ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	static bool IsNumberBetween(double From, double To, double ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	static bool IsNumberBetween(long From, long To, long ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	static bool IsNumberBetween(long long From, long long To, long long ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	static int ReadIntNumberBetween(int From, int To, string NotValidNumberMessage) {
		int Number;
		Number = ReadIntNumber("");
		while (!IsNumberBetween(From, To, Number)) {
			cout << NotValidNumberMessage << endl;
			Number = ReadIntNumber("");
		}
		return Number;
	}
	static double ReadDoubleNumberBetween(double From, double To, string NotValidNumberMessage) {
		double Number;
		Number = ReadDoubleNumber("");
		while (!IsNumberBetween(From, To, Number)) {
			cout << NotValidNumberMessage << endl;
			Number = ReadDoubleNumber("");
		}
		return Number;
	}
	static char ReadChar(string Message) {
		char Character;
		cout << Message;
		cin >> Character;
		return Character;
	}

};