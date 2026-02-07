#pragma once
#include<iostream>
#include<vector>
using namespace std;
namespace myvectorlib {
	void ReadVectorNumbers(vector <int>& vNumbers) {
		char ReadAgain = 'Y';
		int Number = 1;
		do {
			cout << "Please Enter a Number ? ";
			cin >> Number;
			cout << endl;
			vNumbers.push_back(Number);
			cout << "Do You Want To Read More Numbers? Y/N? ";
			cin >> ReadAgain;
		} while (ReadAgain == 'Y' || ReadAgain == 'y');
	}
	void PrintVectorNumbers(vector <int>& vNumbers) {
		cout << "Vector Numbers :\n\n";
		for (int& Number : vNumbers) {
			cout << Number << endl;
		}
	}
}