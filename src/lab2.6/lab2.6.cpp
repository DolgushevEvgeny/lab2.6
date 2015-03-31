// lab2.6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "LoadAndSaveDictionary.h"
#include "DialogueWithUser.h"

using namespace std;
//typedef map<string, string> Dictionary;

int main(int argc, char* argv[])
{
	Dictionary engRusDictionary;
	string fileName = "dictionary.txt";
	//string outputFileName = "dictionaryout.txt";
	ReadToDictionary(engRusDictionary, fileName);
	//SaveDictionary(engRusDictionary, fileName);
	Communicate(engRusDictionary, fileName);
	//system("pause");
	return 0;
}

