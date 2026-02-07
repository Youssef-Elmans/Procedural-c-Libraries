#pragma once
#include<iostream>
#include"MyMathLib.h";
#include<string>
#include<cctype>
#include<cstdio>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;
namespace mystringmanipulationlib {
	struct stClientData {
		string AccountNumber;
		string PinCode;
		string Name;
		string PhoneNumber;
		double AccountBalance;
		bool MarkForDelete = false;
	};
	enum enCharType {
		SamallLetter = 1,
		CapitalLetter = 2,
		SpecialCharacter = 3,
		Digit = 4
	};
	char GetRandomCharacter(enCharType CharType)
	{

		switch (CharType)
		{
		case enCharType::SamallLetter:
		{

			return char(mymathlib::RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{

			return char(mymathlib::RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{

			return char(mymathlib::RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{

			return char(mymathlib::RandomNumber(48, 57));
			break;
		}
		}

		return '\0';
	}
	string GenerateWord(enCharType CharType, short Length)
	{
		string Word;


		for (int i = 1; i <= Length; i++)
		{

			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}
	string GenerateKey()
	{
		string Key = "";

		Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
		return Key;
	}
	void GenerateKeys(short NumberOfKeys)
	{

		for (int i = 1; i <= NumberOfKeys; i++)
		{

			cout << "Key [" << i << "] : ";
			cout << GenerateKey() << endl;
		}
	}
	string EncryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	string DecryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}
	bool GuessPassword(string OriginalPassword)
	{
		string word = "";
		int Counter = 0;

		cout << "\n";


		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{

					word = word + char(i);
					word = word + char(j);
					word = word + char(k);

					Counter++;


					cout << "Trial [" << Counter << "] : " << word << endl;


					if (word == OriginalPassword)
					{
						cout << "\nPassword is " << word << "\n";
						cout << "Found after " << Counter << " Trial(s)\n";

						return true;
					}


					word = "";
				}
			}
		}

		return false;
	}
	void PrintLetterPattern(int Number)
	{
		cout << "\n";


		for (int i = 65; i <= 65 + Number - 1; i++)
		{

			for (int j = 1; j <= i - 65 + 1; j++)
			{
				cout << char(i);
			}

			cout << "\n";
		}
	}
	void PrintInvertedLetterPattern(int Number)
	{
		cout << "\n";


		for (int i = 65 + Number - 1; i >= 65; i--)
		{

			for (int j = 1; j <= Number - ((65 + Number - 1) - i); j++)
			{
				cout << char(i);
			}

			cout << "\n";
		}
	}
	void PrintFirstLetterInString(string Txt) {
		bool IsFirstLetter = true;
		cout << "\nFirst Letters Of This String : \n";
		for (short i = 0; i < Txt.length(); i++) {
			if (Txt[i] != ' ' && IsFirstLetter)
				cout << Txt[i] << endl;

			IsFirstLetter = (Txt[i] == ' ' ? true : false);
		}
	}
	string UpperCaseEachWordFirstLetter(string Txt) {
		bool IsFirstLetter = true;
		for (short i = 0; i < Txt.length(); i++) {
			if (Txt[i] != ' ' && IsFirstLetter)
				Txt[i] = toupper(Txt[i]);

			IsFirstLetter = (Txt[i] == ' ' ? true : false);
		}
		return Txt;
	}
	string LowerAllString(string Txt) {
		for (short i = 0; i < Txt.length(); i++) {
			Txt[i] = tolower(Txt[i]);
		}
		return Txt;
	}
	string UpperAllString(string Txt) {
		for (short i = 0; i < Txt.length(); i++) {
			Txt[i] = toupper(Txt[i]);
		}
		return Txt;
	}
	char InvertLetterCase(char Character) {
		return (isupper(Character) ? tolower(Character) : toupper(Character));
	}
	string InvertAllStringLettersCase(string Txt) {
		for (short i = 0; i < Txt.length(); i++) {
			Txt[i] = mystringmanipulationlib::InvertLetterCase(Txt[i]);
		}
		return Txt;
	}
	short CountStringCapitalLetters(string Txt) {
		short CounterCapitalLetters = 0;
		for (short i = 0; i < Txt.length(); i++) {
			if (isupper(Txt[i]))
				CounterCapitalLetters++;
		}
		return CounterCapitalLetters;
	}
	short CountStringSmallLetters(string Txt) {
		short CounterSmallLetters = 0;
		for (short i = 0; i < Txt.length(); i++) {
			if (islower(Txt[i]))
				CounterSmallLetters++;
		}
		return CounterSmallLetters;
	}
	short CountLetterInString(string Txt, char CharacterToCount, bool MatchCase = true) {
		short Counter = 0;
		for (short i = 0; i < Txt.length(); i++) {
			if (MatchCase) {
				if (Txt[i] == CharacterToCount)
					Counter++;
			}
			else {
				if (tolower(Txt[i]) == tolower(CharacterToCount))
					Counter++;
			}
		}
		return Counter;
	}
	bool IsVowelChar(char Character) {
		char UpperCharacter = toupper(Character);
		return ((UpperCharacter == 'A') || (UpperCharacter == 'E') || (UpperCharacter == 'I') || (UpperCharacter == 'O') || (UpperCharacter == 'U'));
	}
	short CountVowelLettersInString(string Txt) {
		short Counter = 0;
		for (short i = 0; i < Txt.length(); i++) {
			if (mystringmanipulationlib::IsVowelChar(Txt[i]))
				Counter++;
		}
		return Counter;
	}
	void PrintVowelsInString(string Txt) {
		cout << "\nVowels In String Are : ";
		for (short i = 0; i < Txt.length(); i++) {
			if (mystringmanipulationlib::IsVowelChar(Txt[i]))
				cout << Txt[i] << "	";
		}
	}
	void PrintEachWordInString(string Txt) {
		string delim = " ";
		short Pos = 0;
		string sWord;
		while ((Pos = Txt.find(delim)) != Txt.npos) {
			sWord = Txt.substr(0, Pos);
			if (sWord != "")
				cout << sWord << endl;

			Txt.erase(0, Pos + delim.length());
		}
		if (Txt != "")
			cout << Txt;
	}
	short CountWordsInString(string Txt) {
		short Counter = 0;
		string delim = " ";
		short Pos = 0;
		string sWord;
		while ((Pos = Txt.find(delim)) != Txt.npos) {
			sWord = Txt.substr(0, Pos);
			if (sWord != "")
				Counter++;

			Txt.erase(0, Pos + delim.length());
		}
		if (Txt != "")
			Counter++;

		return Counter;
	}
	vector<string>SplitString(string Txt, string Delim) {
		short Pos = 0;
		string sWord;
		vector<string>vTxt;
		while ((Pos = Txt.find(Delim)) != Txt.npos) {
			sWord = Txt.substr(0, Pos);
			if (sWord != "")
				vTxt.push_back(sWord);

			Txt.erase(0, Pos + Delim.length());
		}
		if (Txt != "")
			vTxt.push_back(Txt);

		return vTxt;
	}
	string TrimLeft(string Txt) {
		for (short i = 0; i < Txt.length(); i++) {
			if (Txt[i] != ' ')
				return Txt.substr(i, Txt.length() - i);
		}
		return "";
	}
	string TrimRight(string Txt) {
		for (short i = Txt.length() - 1; i >= 0; i--) {
			if (Txt[i] != ' ')
				return Txt.substr(0, i + 1);
		}
		return "";
	}
	string Trim(string Txt) {
		return TrimLeft(TrimRight(Txt));
	}
	string JoinString(vector<string>& vTxt, string Delim) {
		string  Txt = "";
		for (const string& Word : vTxt) {
			Txt += Word + Delim;
		}
		return Txt.substr(0, Txt.length() - Delim.length());
	}
	string JoinString(string arrTxt[], short Length, string Delim) {
		string  Txt = "";
		for (short i = 0; i < Length; i++) {
			Txt += arrTxt[i] + Delim;
		}
		return Txt.substr(0, Txt.length() - Delim.length());
	}
	string ReverseWordsInString(string Txt, string Delim) {
		string  ReversedTxt = "";
		vector <string>vString = SplitString(Txt, Delim);
		vector <string>::iterator iter = vString.end();
		while (iter != vString.begin()) {
			--iter;
			ReversedTxt += *iter + Delim;
		}
		return ReversedTxt.substr(0, ReversedTxt.length() - Delim.length());
	}
	string ReplaceWordsInStringCustom(string Txt, string ReplacedWord, string WordReplaceTo, bool MatchCase = true) {
		vector <string>vString = mystringmanipulationlib::SplitString(Txt, " ");
		for (string& Word : vString) {
			if (MatchCase) {
				if (Word == ReplacedWord)
					Word = WordReplaceTo;

			}
			else {
				if (mystringmanipulationlib::LowerAllString(Word) == mystringmanipulationlib::LowerAllString(ReplacedWord))
					Word = WordReplaceTo;

			}
		}
		return mystringmanipulationlib::JoinString(vString, " ");
	}
	string ReplaceWordInStringUsingBuiltInFunction(string Text, string
		ReplacedWord, string WordReplaceTo)
	{
		short pos = Text.find(ReplacedWord);
		while (pos != std::string::npos)
		{
			Text = Text.replace(pos, ReplacedWord.length(),
				WordReplaceTo);
			pos = Text.find(ReplacedWord);
		}
		return Text;
	}
	string RemovePunctuationsFromString(string Txt) {
		string TxtWithOutPunct = "";
		for (short i = 0; i < Txt.length(); i++) {
			if (!ispunct(Txt[i]))
				TxtWithOutPunct += Txt[i];
		}
		return TxtWithOutPunct;
	}
	stClientData ReadNewClient() {
		stClientData Client;

		cout << "Enter Account Number : ";
		getline(cin >> ws, Client.AccountNumber);
		cout << endl;

		cout << "Enter PinCode : ";
		getline(cin, Client.PinCode);
		cout << endl;

		cout << "Enter Name : ";
		getline(cin, Client.Name);
		cout << endl;

		cout << "Enter Phone Number : ";
		getline(cin, Client.PhoneNumber);
		cout << endl;

		cout << "Enter Account Balance : ";
		cin >> Client.AccountBalance;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl;

		return Client;
	}
	string ConvertRecordToLine(stClientData Client, string Delim = "#//#") {
		string ClientRecord = "";
		ClientRecord += Client.AccountNumber + Delim;
		ClientRecord += Client.PinCode + Delim;
		ClientRecord += Client.Name + Delim;
		ClientRecord += Client.PhoneNumber + Delim;
		ClientRecord += to_string(Client.AccountBalance);
		return ClientRecord;
	}

	void AddClientDataToFile(string FileName, string ClientDataLine) {
		fstream ClientsFile;
		ClientsFile.open(FileName, ios::out | ios::app);
		if (ClientsFile.is_open()) {
			ClientsFile << ClientDataLine << endl;

			ClientsFile.close();
		}
	}

	void AddNewClinet() {
		stClientData Client = ReadNewClient();
		AddClientDataToFile("ClientsFile.txt.txt", ConvertRecordToLine(Client, "#//#"));
	}
	void AddClients() {
		char AddMore = 'Y';
		do {
			system("cls");
			cout << "Adding New Client : \n\n";
			AddNewClinet();
			cout << "\nClient Added Successfully, Do You Want To Add More Clients? ";
			cin >> AddMore;
		} while (toupper(AddMore) == 'Y');
	}
	stClientData ConvertLinetoRecord(string Line, string Delim = "#//#")
	{
		stClientData Client;
		vector<string> vClientData;
		vClientData = SplitString(Line, Delim);
		Client.AccountNumber = vClientData[0];
		Client.PinCode = vClientData[1];
		Client.Name = vClientData[2];
		Client.PhoneNumber = vClientData[3];
		Client.AccountBalance = stod(vClientData[4]);
		return Client;
	}
	vector<stClientData> LoadClientsDataFromFile(string FileName, string Delim = "#//#") {
		vector <stClientData> vClients;
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open()) {
			string Line;
			stClientData Client;
			while (getline(MyFile, Line)) {
				Client = ConvertLinetoRecord(Line, Delim);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	void PrintClientRecord(stClientData& Client) {
		cout << "| " << left << setw(20) << Client.AccountNumber;
		cout << "| " << left << setw(15) << Client.PinCode;
		cout << "| " << left << setw(40) << Client.Name;
		cout << "| " << left << setw(15) << Client.PhoneNumber;
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}
	void PrintAllClientsDataFile(vector<stClientData>& vClients) {
		cout << "\n\t\t\t\t\tClients List (" << vClients.size() << ") Client(s).";
		cout << "\n__________________________________________________________";
		cout << "______________________________________________________________\n\n";
		cout << "| " << left << setw(20) << "Account Number";
		cout << "| " << left << setw(15) << "Pin Code";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n__________________________________________________________";
		cout << "______________________________________________________________\n\n";
		for (stClientData& Client : vClients) {
			PrintClientRecord(Client);
			cout << endl;
		}

		cout << "__________________________________________________________";
		cout << "______________________________________________________________\n";
	}
	bool FindClientByAccountNumber(vector<stClientData>& vClients, string AccountNumberToCheck, stClientData& Client) {
		for (stClientData& C : vClients) {
			if (C.AccountNumber == AccountNumberToCheck) {
				Client = C;
				return true;
			}
		}
		return false;
	}
	void PrintClientCard(stClientData& Client) {
		cout << "\n\nThe Following Are The Client Details : \n\n";
		cout << "Account Number  : " << Client.AccountNumber << endl;
		cout << "Pin Code        : " << Client.PinCode << endl;
		cout << "Name            : " << Client.Name << endl;
		cout << "Phone           : " << Client.PhoneNumber << endl;
		cout << "Account Balance : " << Client.AccountBalance << endl;
	}
	bool MarkClientToDeleteByAccountNumber(vector<stClientData>& vClients, string AccountNumberToCheck) {
		for (stClientData& Client : vClients) {
			if (Client.AccountNumber == AccountNumberToCheck) {
				Client.MarkForDelete = true;
				return true;
			}
		}
		return false;
	}
	vector <stClientData>SaveCleintsDataToFile(string FileName, vector<stClientData>& vClients) {
		fstream MyFile;
		MyFile.open(FileName, ios::out);
		string DataLine;
		if (MyFile.is_open()) {
			for (stClientData& Client : vClients) {
				if (Client.MarkForDelete == false) {
					DataLine = ConvertRecordToLine(Client, "#//#");
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
		return vClients;
	}
	bool DeleteClientFromFileByAccountNumber(vector<stClientData>& vClients, string AccountNumberToCheck) {
		stClientData Client;
		char Answer = 'n';
		if (FindClientByAccountNumber(vClients, AccountNumberToCheck, Client)) {
			PrintClientCard(Client);
			cout << "\n\nAre You Sure You Want To Delete This Client? Y/N ? ";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y') {
				MarkClientToDeleteByAccountNumber(vClients, AccountNumberToCheck);
				SaveCleintsDataToFile("ClientsFile.txt", vClients);
				vClients = LoadClientsDataFromFile("ClientsFile.txt", "#//#");
				cout << "\n\nClient Deleted Successfully.";
				return true;

			}
		}
		else {
			cout << "\nClient With Account Number (" << AccountNumberToCheck << ") Is Not Found!";
			return false;
		}
	}
	stClientData ReadUpdatedClient() {
		stClientData Client;

		cout << "Enter PinCode : ";
		getline(cin >> ws, Client.PinCode);
		cout << endl;

		cout << "Enter Name : ";
		getline(cin, Client.Name);
		cout << endl;

		cout << "Enter Phone Number : ";
		getline(cin, Client.PhoneNumber);
		cout << endl;

		cout << "Enter Account Balance : ";
		cin >> Client.AccountBalance;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl;

		return Client;
	}
	stClientData ChangeClientRecord(string AccountNumber) {
		stClientData Client;
		Client = ReadUpdatedClient();
		Client.AccountNumber = AccountNumber;
		return Client;
	}
	bool UpdateClientDataInFile(vector<stClientData>& vClients, string AccountNumberToCheck) {
		stClientData Client;
		char Answer = 'n';
		if (FindClientByAccountNumber(vClients, AccountNumberToCheck, Client)) {
			PrintClientCard(Client);
			cout << "\n\nAre You Sure You Want To Update This Client? Y/N ? ";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y') {
				for (stClientData& C : vClients) {
					if (C.AccountNumber == AccountNumberToCheck) {
						C = ChangeClientRecord(AccountNumberToCheck);
					}
					break;
				}
				SaveCleintsDataToFile("ClientsFile.txt", vClients);
				cout << "\n\nClient Updated Successfully.";
				return true;

			}
		}
		else {
			cout << "\nClient With Account Number (" << AccountNumberToCheck << ") Is Not Found!";
			return false;
		}
	}

}