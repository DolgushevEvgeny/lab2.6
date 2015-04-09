// lab2.6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "LoadAndSaveDictionary.h"
#include "DialogueWithUser.h"

using namespace std;

int main(int argc, char* argv[])
{
	Dictionary engRusDictionary;
	string fileName = "dictionary1.txt";
	ReadToDictionary(engRusDictionary, fileName);
	Communicate(engRusDictionary, fileName);
	return 0;
}

