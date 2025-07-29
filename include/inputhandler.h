#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <iostream>
#include <string>
#include <algorithm>

bool isOnlynumber (const std::string& src);

bool getvalidGetlineString (std::string& input);

template <typename T> bool getvalidinput (T& input) { //template defination must be in header
    std::cin >> input;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;
}

#endif