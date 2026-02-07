#pragma once
#include<iostream>
#include"MyMathLib.h";
#include"MyInputLib.h";
#include"MyStringManipulationLib.h";
#include<iomanip>
#include<cstdio>
#include<cmath>
using namespace std;
namespace myarrayutilslib {
	void FillArrayWithRandomElements(int ArrOfNumbers[], int ArrSize)
	{



		for (int i = 0; i < ArrSize; i++)
			ArrOfNumbers[i] = mymathlib::RandomNumber(0, 100);
	}
	void PrintArrayElements(int ArrOfString[], int ArrSize)
	{


		for (int i = 0; i < ArrSize; i++) {

			cout << ArrOfString[i] << " ";

		}
		cout << "\n";
	}
	void AddArrElement(int Number, int ArrOfNumbers[], int& ArrLegth) {
		ArrOfNumbers[ArrLegth] = Number;
		ArrLegth++;
	}
	void InputNumbersToArrUsingAddArrElement(int ArrOfNumbers[], int& ArrLength) {

		bool AddOrNot = true;
		do {
			AddArrElement(myinputlib::ReadIntNumber("please enter a number ? "), ArrOfNumbers, ArrLength);
			cout << "Do You Want To Add More Numbers? [0]:No,[1]:Yes ? ";
			cin >> AddOrNot;
		} while (AddOrNot);

	}
	void CopyArrUsingAddArrElemen(int ArrSource[], int ArrDestination[], int Arr1Length, int& Arr2Length) {
		for (int i = 0; i < Arr1Length; i++) {
			AddArrElement(ArrSource[Arr2Length], ArrDestination, Arr2Length);
		}
	}
	void CopyOnlyOddNumbersToArr(int ArrSource[], int ArrDestination[], int Arr1Length, int& Arr2Length) {
		for (int i = 0; i < Arr1Length; i++) {
			if (mymathlib::DetermineOddOrEven(ArrSource[i]) == mymathlib::enOddOrEven::Odd) {
				AddArrElement(ArrSource[i], ArrDestination, Arr2Length);
			}
		}
	}
	void CopyOnlyEvenNumbersToArr(int ArrSource[], int ArrDestination[], int Arr1Length, int& Arr2Length) {
		for (int i = 0; i < Arr1Length; i++) {
			if (mymathlib::DetermineOddOrEven(ArrSource[i]) == mymathlib::enOddOrEven::Even) {
				AddArrElement(ArrSource[i], ArrDestination, Arr2Length);
			}
		}
	}
	void CopyOnlyPrimeNumbersToArr(int ArrSource[], int ArrDestination[], int Arr1Length, int& Arr2Length) {
		for (int i = 0; i < Arr1Length; i++) {
			if (mymathlib::CheckPrime(ArrSource[i]) == mymathlib::enPrimNotPrime::Prime) {
				AddArrElement(ArrSource[i], ArrDestination, Arr2Length);
			}
		}
	}
	short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == Number)
				return i;
		}

		return -1;
	}
	bool IsNumberInArray(int Number, int arr[100], int arrLength)
	{

		return FindNumberPositionInArray(Number, arr, arrLength) != -1;
	}
	void FillArrHardCoded(int ArrOfNumbers[], int& ArrSize) {
		ArrSize = 10;
		ArrOfNumbers[0] = { 10 };
		ArrOfNumbers[1] = { 10 };
		ArrOfNumbers[2] = { 10 };
		ArrOfNumbers[3] = { 50 };
		ArrOfNumbers[4] = { 50 };
		ArrOfNumbers[5] = { 70 };
		ArrOfNumbers[6] = { 70 };
		ArrOfNumbers[7] = { 70 };
		ArrOfNumbers[8] = { 70 };
		ArrOfNumbers[9] = { 90 };

	}
	void CopyDistinctUniqueElementsToArr(int ArrSource[], int ArrDestination[], int Arr1Length, int& Arr2Length) {

		for (int i = 0; i < Arr1Length; i++) {
			if (!IsNumberInArray(ArrSource[i], ArrDestination, Arr2Length)) {
				AddArrElement(ArrSource[i], ArrDestination, Arr2Length);
			}
		}
	}
	void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)

			arrDestination[i] = arrSource[arrLength - 1 - i];
	}
	bool IsPalindromeArray(int ArrOfNumbers[], int ArrLength) {
		for (int i = 0; i < (ArrLength / 2); i++) {
			if (ArrOfNumbers[i] != ArrOfNumbers[ArrLength - i - 1]) {
				return false;
			}
		}
		return true;
	}
	int CountOddNumbersInArr(int ArrOfNumbers[], int ArrLength) {
		int CountOddNumbers = 0;
		for (int i = 0; i < ArrLength; i++) {
			if (mymathlib::DetermineOddOrEven(ArrOfNumbers[i]) == mymathlib::enOddOrEven::Odd) {
				CountOddNumbers++;
			}
		}
		return CountOddNumbers;
	}
	int CountEvenNumbersInArr(int ArrOfNumbers[], int ArrLength) {
		int CountEvenNumbers = 0;
		for (int i = 0; i < ArrLength; i++) {
			if (mymathlib::DetermineOddOrEven(ArrOfNumbers[i]) == mymathlib::enOddOrEven::Even) {
				CountEvenNumbers++;
			}
		}
		return CountEvenNumbers;
	}
	int CountPositiveNumbersInArr(int ArrOfNumbers[], int ArrLength) {
		int CountPositiveNumbers = 0;
		for (int i = 0; i < ArrLength; i++) {
			if (ArrOfNumbers[i] > 0) {
				CountPositiveNumbers++;
			}
		}
		return CountPositiveNumbers;
	}
	int CountNegativeNumbersInArr(int ArrOfNumbers[], int ArrLength) {
		int CountNegativeNumbers = 0;
		for (int i = 0; i < ArrLength; i++) {
			if (ArrOfNumbers[i] < 0) {
				CountNegativeNumbers++;
			}
		}
		return CountNegativeNumbers;
	}
	void PrintStringArray(string arr[100], int arrLength)
	{
		cout << "\nArray elements:\n\n";

		for (int i = 0; i < arrLength; i++)
		{
			cout << "Array[" << i << "] : ";
			cout << arr[i] << "\n";
		}
		cout << "\n";
	}
	void FillArrayWithKeys(string arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
			arr[i] = mystringmanipulationlib::GenerateKey();
	}
	void FillArrayWith1toN(int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
			arr[i] = i + 1;
	}
	void ShuffleArray(int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{

			int index1 = mymathlib::RandomNumber(1, arrLength) - 1;
			int index2 = mymathlib::RandomNumber(1, arrLength) - 1;

			mymathlib::Swap(arr[index1], arr[index2]);
		}
	}
	void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			arrSum[i] = arr1[i] + arr2[i];
		}
	}
	int SumArray(int arr[100], int arrLength)
	{
		int Sum = 0;


		for (int i = 0; i < arrLength; i++)
		{
			Sum += arr[i];
		}

		return Sum;
	}
	float ArrayAverage(int arr[100], int arrLength)
	{

		return (float)SumArray(arr, arrLength) / arrLength;
	}
	int MinNumberInArray(int arr[100], int arrLength)
	{
		int Min = arr[0];


		for (int i = 0; i < arrLength; i++)
		{

			if (arr[i] < Min)
			{
				Min = arr[i];
			}
		}
		return Min;
	}
	int MaxNumberInArray(int arr[100], int arrLength)
	{
		int Max = 0;


		for (int i = 0; i < arrLength; i++)
		{

			if (arr[i] > Max)
			{
				Max = arr[i];
			}
		}
		return Max;
	}
	int TimesRepeatedInArr(int Number, int arr[100], int arrLength)
	{
		int count = 0;

		for (int i = 0; i <= arrLength - 1; i++)
		{
			if (Number == arr[i])
			{
				count++;
			}
		}
		return count;
	}
	namespace MyMatrixArrayUtils {
		void FillMatrixWithRandomNumbers(int Matrix[3][3], short NumOfRows, short NumOfColumns, int RandomNumFrom, int RandomNumTo) {
			for (short i = 0; i < NumOfRows; i++) {
				for (short j = 0; j < NumOfColumns; j++) {
					Matrix[i][j] = mymathlib::RandomNumber(RandomNumFrom, RandomNumTo);
				}
			}
		}
		void FillMatrixWithOrderdNumbers(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
			short Number = 1;
			for (short i = 0; i < NumOfRows; i++) {
				for (short j = 0; j < NumOfColumns; j++) {
					Matrix[i][j] = Number;
					Number++;
				}
			}
		}
		void PrintMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
			for (int i = 0; i < NumOfRows; i++) {
				for (int j = 0; j < NumOfColumns; j++) {
					printf("%0*d	", 2, Matrix[i][j]);
				}
				cout << endl;
			}
		}
		int RowSumInMatrix(int Matrix[3][3], short RowIndex, short NumOfColumns) {
			int Sum = 0;
			for (short i = 0; i < NumOfColumns; i++) {
				Sum += Matrix[RowIndex][i];
			}
			return Sum;
		}
		int ColumnSumInMatrix(int Matrix[3][3], short NumOfRows, short ColumnIndex) {
			int Sum = 0;
			for (short i = 0; i < NumOfRows; i++) {
				Sum += Matrix[i][ColumnIndex];
			}
			return Sum;
		}
		void TransposeMatrix(int Matrix[3][3], int TransposedMatrix[3][3], short NumOfRows, short NumOfColumns) {
			for (short i = 0; i < NumOfRows; i++) {
				for (short j = 0; j < NumOfColumns; j++) {
					TransposedMatrix[i][j] = Matrix[j][i];
				}
			}

		}
		int SumMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
			int Sum = 0;
			for (short i = 0; i < NumOfRows; i++) {
				for (short j = 0; j < NumOfColumns; j++) {
					Sum += Matrix[i][j];
				}
			}
			return Sum;
		}
		bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short NumOfRows, short NumOfColumns) {
			for (short i = 0; i < NumOfRows; i++) {
				for (short j = 0; j < NumOfColumns; j++) {
					if (Matrix1[i][j] != Matrix2[i][j]) {
						return false;
					}
				}
			}
			return true;
		}
		bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short NumOfRows, short NumOfColumns) {
			return (myarrayutilslib::MyMatrixArrayUtils::SumMatrix(Matrix1, 3, 3)) == (myarrayutilslib::MyMatrixArrayUtils::SumMatrix(Matrix2, 3, 3));
		}
		bool IsIdentityMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
			for (short i = 0; i < NumOfRows; i++) {
				for (short j = 0; j < NumOfColumns; j++) {
					if (i == j && Matrix[i][j] != 1)
						return false;

					else if (i != j && Matrix[i][j] != 0)
						return false;
				}
			}
			return true;

		}
		bool IsIScalarMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
			int FirstDiagElement = Matrix[0][0];
			for (short i = 0; i < NumOfRows; i++) {
				for (short j = 0; j < NumOfColumns; j++) {
					if (i == j && Matrix[i][j] != FirstDiagElement)
						return false;

					else if (i != j && Matrix[i][j] != 0)
						return false;
				}
			}
			return true;

		}
		short CountNumberFrequencyInMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns, int NumberToCheck) {
			short NumFreq = 0;
			for (short i = 0; i < NumOfRows; i++) {
				for (short j = 0; j < NumOfColumns; j++) {
					if (Matrix[i][j] == NumberToCheck)
						NumFreq++;
				}
			}
			return NumFreq;
		}
		bool IsSparseMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
			short ZeroFreq = myarrayutilslib::MyMatrixArrayUtils::CountNumberFrequencyInMatrix(Matrix, 3, 3, 0);
			short MatrixSize = NumOfRows * NumOfColumns;
			return (ZeroFreq >= ceil((float)MatrixSize / 2));
		}
		bool IsNumberInMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns, int NumberToCheck) {
			for (short i = 0; i < NumOfRows; i++) {
				for (short j = 0; j < NumOfColumns; j++) {
					if (Matrix[i][j] == NumberToCheck)
						return true;
				}
			}
			return false;
		}
		void PrintIntersectedNumbersInTwoMatrices(int Matrix1[3][3], int Matrix2[3][3], short NumOfRowsMatrix1, short NumOfColumnsMatrix1, short NumOfRowsMatrix2, short NumOfColumnsMatrix2) {
			cout << "\nIntersected Numbers Are : \n";
			for (short i = 0; i < NumOfRowsMatrix1; i++) {
				for (short j = 0; j < NumOfColumnsMatrix1; j++) {
					if (myarrayutilslib::MyMatrixArrayUtils::IsNumberInMatrix(Matrix2, NumOfRowsMatrix2, NumOfColumnsMatrix2, Matrix1[i][j]))
						cout << Matrix1[i][j] << "	";
				}
			}
		}
		int MinimumNumberInMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
			int Min = Matrix[0][0];
			for (short i = 0; i < NumOfRows; i++) {
				for (short j = 0; j < NumOfColumns; j++) {
					Min = (Matrix[i][j] < Min) ? Matrix[i][j] : Min;
				}
			}
			return Min;
		}
		int MaximumNumberInMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
			int Max = Matrix[0][0];
			for (short i = 0; i < NumOfRows; i++) {
				for (short j = 0; j < NumOfColumns; j++) {
					Max = (Matrix[i][j] > Max) ? Matrix[i][j] : Max;
				}
			}
			return Max;
		}
		bool IsPalindromeMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
			for (short i = 0; i < NumOfRows; i++) {
				for (short j = 0; j < (NumOfColumns / 2); j++) {
					if (Matrix[i][j] != Matrix[i][NumOfColumns - j - 1])
						return false;
				}
			}
			return true;
		}
	}
}