#pragma once
#include<iostream>
#include<string>
using namespace std;
namespace mycollectionprojectsfunctions {
	enum enQuestionLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };
	enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };
	enQuestionLevel ReadQuestionLevel() {
		short QuestionsLevel = 0;
		do {
			cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
			cin >> QuestionsLevel;
		} while (QuestionsLevel < 1 || QuestionsLevel>4);
		return (enQuestionLevel)QuestionsLevel;
	}
	enOperationType ReadOperationsType() {
		short OperationsType = 0;
		do {
			cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
			cin >> OperationsType;
		} while (OperationsType < 1 || OperationsType>5);
		return (enOperationType)OperationsType;
	}
	string ReadText(string Message)
	{
		string Text;

		cout << Message;
		getline(cin >> ws, Text);

		return Text;
	}
	
}
