#include "stdafx.h"
#include <fstream>
#include "LoadAndSaveDictionary.h"
#include <windows.h>

using namespace std;

void DivideStringForOriginalAndTranslation(string &translation, string &original)
{
	int startLine = 0, endLine = translation.size();
	for (unsigned int i = startLine; i < translation.size(); ++i)
	{
		if (translation[i] == '[')
		{
			startLine = i + 1;
		}
		if (translation[i] == ']')
		{
			endLine = i - 1;
			break;
		}
	}
	original = translation.substr(startLine, endLine);
	translation.erase(0, endLine + 3);
}

void ReadToDictionary(Dictionary &dictionary, const string &fileNameInput)
{
	ifstream dictionaryFile;
	dictionaryFile.open(fileNameInput, ifstream::in);
	if (!dictionaryFile.is_open())
	{
		bool isFileOpen = false;
		while (!isFileOpen)
		{
			cout << "Error: cannot load input file. Try again to enter new file name.\n";
			string fileName;
			getline(cin, fileName);
			dictionaryFile.open(fileName, ifstream::in);
			if (dictionaryFile.is_open())
			{
				isFileOpen = true;
			}
		}
	}
	while (dictionaryFile.good())
	{
		string translation, original;
		getline(dictionaryFile, translation);
		DivideStringForOriginalAndTranslation(translation, original);
		Dictionary::iterator position;
		position = dictionary.find(original);
		if (position == dictionary.end())
		{
			dictionary[original] = translation;
		}
	}
	dictionaryFile.close();
}

void SaveDictionary(Dictionary &dictionary, const string &fileNameInput)
{
	ofstream dictionaryFile;
	dictionaryFile.open(fileNameInput, ios::out);

	if (!dictionaryFile.is_open())
	{
		bool isFileOpen = false;
		while (!isFileOpen)
		{
			cout << "Error: cannot create output file. Try again to enter new file name.\n";
			string fileName;
			getline(cin, fileName);
			dictionaryFile.open(fileName, ios::out);
			if (dictionaryFile.is_open())
			{
				isFileOpen = true;
			}
		}
	}
	for (auto exemplar : dictionary)
	{
		dictionaryFile << "[" << exemplar.first << "]" << " " << exemplar.second << "\n";
	}
	dictionaryFile.close();
}