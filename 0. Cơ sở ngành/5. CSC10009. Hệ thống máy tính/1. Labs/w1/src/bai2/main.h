#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>
#include <string>
#include <regex>
#include <format>

using std::cin, std::cout, std::string, std::regex;

string enterValue();
bool check8bitStr(const string& str);
int convertToNumber(const string& str);
string convertToBinary(const int& num);
string addition(const string& str1, const string& str2);
string subtraction(const string& str1, const string& str2);
string multiplication(const string& str1, const string& str2);
std::pair<string, string> division(const string& str1, const string& str2);

#endif