#pragma once
#include<iostream>
using namespace std;
namespace myprintandscreenlib {
	void PrintTableHeader()
	{

		cout << "\n\n\t\t\t Multiplication Table From 1 to 10\n\n";


		cout << "\t";


		for (int i = 1; i <= 10; i++)
		{

			cout << i << "\t";
		}


		cout << "\n___________________________________________________________________________________\n";
	}



	string ColumSperator(int i)
	{

		if (i < 10)
			return "   |";
		else

			return "  |";
	}


	void PrintMultiplicationTable()
	{

		PrintTableHeader();


		for (int i = 1; i <= 10; i++)
		{

			cout << " " << i << ColumSperator(i) << "\t";


			for (int j = 1; j <= 10; j++)
			{

				cout << i * j << "\t";
			}

			cout << endl;
		}
	}
	void ResetScreen() {
		system("cls");
		system("color 07");
	}
	string Tabs(short NumberOfTabs) {
		string t = "";
		for (short i = 1; i <= NumberOfTabs; i++) {
			t = t + "\t";
		}
		return t;
	}
	void ShowGameOverScreen() {
		cout << Tabs(4) << "_________________________________________________________\n\n";
		cout << Tabs(4) << "                 +++ G a m e O v e r +++\n";
		cout << Tabs(4) << "_________________________________________________________\n\n";
	}
	void PrintAllFromAAAtoZZZ()
	{
		cout << "\n";
		string word = "";


		for (int i = 65; i <= 90; i++)
		{

			for (int j = 65; j <= 90; j++)
			{

				for (int k = 65; k <= 90; k++)
				{

					word.append(1, char(i));

					word.append(1, char(j));

					word.append(1, char(k));


					cout << word << endl;

					word = "";
				}
			}

			cout << "\n____________________________\n";
		}
	}

}