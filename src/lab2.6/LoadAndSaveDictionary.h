#pragma once
#include <iostream>
#include <map>
#include <string>

typedef std::map<std::string, std::string> Dictionary;

void ReadToDictionary(Dictionary &temp, const std::string &fileNameInput);
void FindBrekets(const std::string &line, int &start, int &end);
void SaveDictionary(Dictionary &dictionary, const std::string &fileNameInput);