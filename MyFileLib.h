#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
namespace myfilelib {
	void PrintFileContent(string FileName) {
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				cout << Line << endl;
			}

		}

	}
	void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent) {
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				vFileContent.push_back(Line);
			}
			MyFile.close();
		}
	}
	void SaveVectorToFile(string FileName, vector<string>& vFileContent) {
		fstream MyFile;
		MyFile.open(FileName, ios::out);
		if (MyFile.is_open()) {
			for (const string& Line : vFileContent) {
				if (Line != "") {
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}
	void DeleteRecordFromFile(string FileName, string Record) {
		vector <string>vFileContent;
		myfilelib::LoadDataFromFileToVector(FileName, vFileContent);
		for (string& Line : vFileContent) {
			if (Line == Record) {
				Line = "";
			}
		}
		myfilelib::SaveVectorToFile(FileName, vFileContent);
	}
	void UpdateRecordInFile(string FileName, string Record, string UpdateTo) {
		vector <string>vFileContent;
		myfilelib::LoadDataFromFileToVector(FileName, vFileContent);
		for (string& Line : vFileContent) {
			if (Line == Record) {
				Line = UpdateTo;
			}
		}
		myfilelib::SaveVectorToFile(FileName, vFileContent);
	}
}