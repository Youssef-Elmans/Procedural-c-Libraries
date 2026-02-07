#pragma once
#include<iostream>
#include<string>
using namespace std;
namespace myinputlib {
	
	int ReadValidatedNumber(string Message) {
		int Number;
		cout << Message<< endl;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number , Enter a Valid One : " << endl;
			cin >> Number;
		}
		return Number;
	}
	int ReadPositiveIntNumber(string Message)
	{
		int Number = 0;
		do
		{
			cout << Message << endl;
			cin >> Number;
		} while (Number <= 0);

		return Number;
	}
	short ReadShortNumber(string Message)
	{
		short Number = 0;
		/*do
		{
			cout << Message << endl;
			cin >> Number;
		} while (Number <= 0);*/
		cout << Message << endl;
		cin >> Number;
		return Number;
	}
	int ReadPositiveFloatNumber(string Message)
	{
		float Number = 0;
		do
		{
			cout << Message << endl;
			cin >> Number;
		} while (Number <= 0);

		return Number;
	}
	int ReadIntNumber(string Message)
	{
		int Number = 0;
		cout << Message << endl;
		cin >> Number;
		return Number;
	}
	long ReadLongLongNumber(string Message) {
		long long Number = 0;
		cout << Message << endl;
		cin >> Number;
		return Number;
	}
	float ReadFloatNumber(string Message)
	{
		float Number = 0;
		cout << Message << endl;
		cin >> Number;
		return Number;
	}
	bool ReadBoolNumber(string Message) {
		bool Number = false;
		do {
			cout << Message << endl;
			cin >> Number;
		} while (Number > 1 || Number < 0);
		return Number;
	}
	char ReadChar(string Message) {
		char Character;
		cout << Message;
		cin >> Character;
		return Character;
	}
}