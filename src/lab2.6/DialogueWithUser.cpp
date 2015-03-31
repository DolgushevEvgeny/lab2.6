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
			cout << "Неизвестное слово " << answer << ". Введите перевод или пустую строку для отказа.\n";
			string translation;
			getline(cin, translation);
			if (!translation.empty())             //translation != breakAnswer
			{
				dictionary[answer] = translation;
				cout << "Слово " << answer << " сохранено в словаре как " << translation << ".\n";
				areChangesInDictionary = true;
			}
			else
			{
				cout << "Слово " << answer << " проигнорировано.\n";
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
		cout << "Введите Y или y чтобы сохранить изменения в словаре.\n";
		cin >> answer;
		if (answer == "y" || answer == "Y")
		{
			SaveDictionary(dictionary, fileNameOutput);
		}
		cout << "Изменения сохранены.До свидания.\n";
	}
}