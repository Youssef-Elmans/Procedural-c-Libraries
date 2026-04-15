#pragma once
#include<iostream>
using namespace std;
class clsInputValidation
{
public:

	template<typename T>static T ReadNumber(string Message,string ErrorMessage="Invalid Number , Enter a Valid One : \n")
	{
		T Number;
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

	template<typename T>static T ReadPositiveNumber(string Message)
	{
		T Number = 0;
		do
		{
			Number = ReadNumber(Message);
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

	  template <typename T>static bool IsNumberBetween(T From, T To, T ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	
	template <typename T>static T ReadNumberBetween(T From, T To, string NotValidNumberMessage) {
		int Number;
		Number = ReadNumber("");
		while (!IsNumberBetween<T>(From, To, Number)) {
			cout << NotValidNumberMessage << endl;
			Number = ReadNumber("");
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
