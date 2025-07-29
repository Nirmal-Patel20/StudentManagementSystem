#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <iostream>
#include <string>
#include <algorithm>

bool isOnlynumber (const std::string& src);

template <typename T> bool getvalidinput (T& input);

bool getvalidGetlineString (std::string& input);

#endif