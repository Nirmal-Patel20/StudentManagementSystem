#include "InputHandler.h"

bool isOnlynumber (const std::string& src){
    return !src.empty() && std::all_of(src.begin(),src.end(), ::isdigit);
}

bool getvalidGetlineString (std::string& input){
    std::getline(std::cin,input);
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }else if(isOnlynumber(input)){
        std::cout << "This input is only numeric" << std::endl;
        return false;
    }
    return true;
}
