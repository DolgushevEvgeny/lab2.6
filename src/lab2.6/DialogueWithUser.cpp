#include "stdafx.h"
#include "DialogueWithUser.h"
#include <fstream>
#include <windows.h>

using namespace std;

void Communicate(Dictionary &dictionary, const string &fileNameOutput)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string answer;
	string breakString = "...";
	//string breakAnswer = "";
	Dictionary::iterator position;
	bool areChangesInDictionary = false;
	bool isRightAnswer = false;
	getline(cin, answer);
	if (answer != breakString)
	{
		isRightAnswer = true;
	}
	while (isRightAnswer)
	{
		position = dictionary.find(answer);
		if (position == dictionary.end())
		{
			cout << "����������� ����� " << answer << ". ������� ������� ��� ������ ������ ��� ������.\n";
			string translation;
			getline(cin, translation);
			if (!translation.empty())             //translation != breakAnswer
			{
				dictionary[answer] = translation;
				cout << "����� " << answer << " ��������� � ������� ��� " << translation << ".\n";
				areChangesInDictionary = true;
			}
			else
			{
				cout << "����� " << answer << " ���������������.\n";
			}
		}
		else
		{
			cout << position->second << "\n";
		}
		isRightAnswer = false;
		getline(cin, answer);
		if (answer != breakString)
		{
			isRightAnswer = true;
		}
	}
	if (areChangesInDictionary)
	{
		cout << "������� Y ��� y ����� ��������� ��������� � �������.\n";
		cin >> answer;
		if (answer == "y" || answer == "Y")
		{
			SaveDictionary(dictionary, fileNameOutput);
		}
		cout << "��������� ���������.�� ��������.\n";
	}
}