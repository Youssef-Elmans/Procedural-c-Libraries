#pragma once
#include<iostream>
#include<cmath>
using namespace std;
namespace mymathlib {
	enum enPrimNotPrime
	{
		Prime = 1,
		NotPrime = 2
	};
	enum enOddOrEven { Odd, Even };
	enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };
	float MyAbs(float Number) {
		if (Number < 0) {
			return (Number / -1);
		}
		return Number;
	}
	float GetFractionPart(float Number) {
		return Number - int(Number);
	}

	int MyRound(float Number) {
		int IntPart = int(Number);
		float FractionPart = GetFractionPart(Number);
		if (MyAbs(FractionPart) >= 0.5) {
			if (IntPart > 0)
				return ++IntPart;
			else
				return	--IntPart;

		}
		return IntPart;
	}
	int MyFloor(float Number) {
		int IntPart = int(Number);
		float FractionPart = GetFractionPart(Number);
		if (Number >= 0)
			return IntPart;
		else {
			if (FractionPart == 0)
				return IntPart;

			else
				return --IntPart;


		}

	}
	int MyCeil(float Number) {
		int IntPart = int(Number);
		float FractionPart = GetFractionPart(Number);
		if (FractionPart == 0)
			return IntPart;
		else {
			if (Number > 0)
				return ++IntPart;

			else
				return IntPart;

		}

	}
	float MyPow(float Number, short Power) {
		float NumberToPowerN = 1;
		if (Number == 0) {
			return Number;
		}
		if (Power >= 0) {
			for (short i = 1; i <= Power; i++) {
				NumberToPowerN *= Number;
			}
			return NumberToPowerN;
		}
		else {
			for (short i = 0; i > Power; i--) {
				NumberToPowerN *= (1 / Number);
			}
			return NumberToPowerN;
		}
	}
	float MySqrt(float Number) {
		return pow(Number, 0.5);
	}
	short SimpleCalculater(short Number1, short Number2, enOperationType OperationType) {
		switch (OperationType) {
		case enOperationType::Add:
			return Number1 + Number2;
		case enOperationType::Sub:
			return Number1 - Number2;
		case enOperationType::Mul:
			return Number1 * Number2;
		case enOperationType::Div:
			return Number1 / Number2;
		}

	}
	int RandomNumber(int From, int To)
	{
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	enPrimNotPrime CheckPrime(int Number)
	{
		int M = round(Number / 2);
		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return enPrimNotPrime::NotPrime;
		}
		return enPrimNotPrime::Prime;
	}
	bool isPerfectNumber(int Number)
	{
		int Sum = 0;


		for (int i = 1; i < Number; i++)
		{

			if (Number % i == 0)
				Sum += i;
		}

		return Number == Sum;
	}
	void PrintDigits(int Number)
	{
		int Sum = 0, Remainder = 0;


		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			cout << Remainder << endl;
		}
	}
	int SumOfDigits(int Number)
	{
		int Sum = 0;
		int Remainder = 0;


		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Sum = Sum + Remainder;
		}

		return Sum;
	}
	int ReverseNumber(int Number)
	{
		int Remainder = 0;
		int Number2 = 0;


		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;
		}

		return Number2;
	}
	int CountDigitFrequency(short DigitToCheck, int Number)
	{
		int FreqCount = 0;
		int Remainder = 0;


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
	void PrintAllDigitsFrequencey(int Number)
	{
		cout << endl;


		for (int i = 0; i < 10; i++)
		{
			short DigitFrequency = 0;
			DigitFrequency = CountDigitFrequency(i, Number);


			if (DigitFrequency > 0)
			{
				cout << "Digit " << i << " Frequencey is "
					<< DigitFrequency << " Time(s).\n";
			}
		}
	}
	bool IsPalindromeNumber(int Number)
	{

		return Number == ReverseNumber(Number);
	}
	enOddOrEven DetermineOddOrEven(int Number) {
		int Remainder = Number % 2;
		if (Remainder == 0) {
			return enOddOrEven::Even;
		}
		else {
			return enOddOrEven::Odd;
		}
	}
	void Swap(int& A, int& B)
	{
		int Temp;    
		Temp = A;    
		A = B;       
		B = Temp;    
	}
	void PrintNumberPattern(int Number)
	{
		cout << "\n";  

	
		for (int i = 1; i <= Number; i++)
		{
			
			for (int j = 1; j <= i; j++)
			{
				cout << i; 
			}
			cout << "\n";  
		}
	}
	void PrintInvertedNumberPattern(int Number)
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
	void PrintPrimeNumbersFrom1ToN(int Number)
	{
		cout << "\n";  
		
		cout << "Prime Numbers from " << 1 << " To " << Number;
		cout << " are : " << endl;

	
		for (int i = 1; i <= Number; i++)
		{
			
			if (CheckPrime(i) == enPrimNotPrime::Prime)
			{
			
				cout << i << endl;
			}
		}
	}
	void FibonacciSeriusUsingLoop(short NumOfElements) {
		short FebNumber = 0;
		short Prev2 = 0, Prev1 = 1;
		cout << "1	";
		for (short i = 2; i <= NumOfElements; i++) {
			FebNumber = Prev1 + Prev2;
			cout << FebNumber << "	";
			Prev2 = Prev1;
			Prev1 = FebNumber;
		}
	}
	string NumberToText(long long int Number) {
		if (Number == 0) {
			return "";
		}
		if (Number >= 1 && Number <= 19) {
			string arr[] = { "","One","Two","Three","Four","Five","Six","Seven",
				"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
				"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99) {
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy",
				"Eighty","Ninety" };
			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199) {
			return "One Hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999) {
			return NumberToText(Number / 100) + "Hundreds" + " " + NumberToText(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999) {
			return "One Thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999) {
			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999) {
			return "One Million " + NumberToText(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999) {
			return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999) {
			return "One Billion " + NumberToText(Number % 1000000000);
		}
		else {
			return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}
	

}