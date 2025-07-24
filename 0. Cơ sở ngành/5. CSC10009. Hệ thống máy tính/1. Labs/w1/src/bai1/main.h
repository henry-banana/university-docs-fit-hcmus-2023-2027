#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>
#include <string>
#include <regex>
#include <format>

using std::cin, std::cout, std::string, std::regex;

bool checkInt32bit(const string& x);
bool checkBinaryArray(const string& a);
string convertInt32bitToBinaryBitArray(const string& x);
int32_t convertBinaryArrayToInt32bit(const string& a);
string enterValue(const bool& commandLine);
bool isEnterInt32bit();

#endif