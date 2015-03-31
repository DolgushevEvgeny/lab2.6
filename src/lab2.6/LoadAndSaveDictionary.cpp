#include "stdafx.h"
#include <fstream>
#include "LoadAndSaveDictionary.h"
#include <windows.h>

using namespace std;

void FindBrekets(const string &line, int &start, int &end)
{
	for (unsigned int i = start; i < line.size(); ++i)
	{
		if (line[i] == '[')
		{
			start = i + 1;
		}
		if (line[i] == ']')
		{
			end = i - 1;
			break;
		}
	}
}

void ReadToDictionary(Dictionary &dictionary, const string &fileNameInput)
{
	SetConsoleOutputCP(1251);
	ifstream dictionaryFile(fileNameInput, ifstream::in);

	if (!dictionaryFile.is_open())
	{
		printf("Error: cannot load input file\n");
		system("pause");
		exit(1);
	}
	string line, key;
	Dictionary::iterator position;
	int startLine, endLine;
	while (dictionaryFile.good())
	{
		getline(dictionaryFile, line);
		startLine = 0;
		endLine = line.size();
		FindBrekets(line, startLine, endLine);
		key = line.substr(startLine, endLine);
		line.erase(0, endLine + 3);
		position = dictionary.find(key);
		if (position == dictionary.end())
		{
			dictionary[key] = line;
		}
	}
	dictionaryFile.close();
}

void SaveDictionary(Dictionary &dictionary, const string &fileNameInput)
{
	ofstream dictionaryFile(fileNameInput, ios::out);

	if (!dictionaryFile.is_open())
	{
		printf("Error: cannot create output file\n");
		system("pause");
		exit(1);
	}
	Dictionary::iterator position;
	for (position = dictionary.begin(); position != dictionary.end(); ++position)
	{
		dictionaryFile << "[" << position->first << "]" << " ";
		dictionaryFile << position->second << "\n";
	}
	dictionaryFile.close();
}