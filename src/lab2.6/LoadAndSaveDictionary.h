#pragma once
#include <iostream>
#include <map>
#include <string>

typedef std::map<std::string, std::string> Dictionary;

void ReadToDictionary(Dictionary &dictionary, const std::string &fileNameInput);
void DivideStringForOriginalAndTranslation(std::string &translation, std::string &original);
void SaveDictionary(Dictionary &dictionary, const std::string &fileNameInput);