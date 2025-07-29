#include "login.h"


bool loginstatus (){
    std::string password;
    char input;
    std::cout << "would like you login as admin[y,n] ? ";
    bool valid_input = false;

    while(!valid_input){
        if(getvalidinput(input)){
            if(input == 'y' || input == 'Y'){
                bool Authentication = false;
                std::string password;
                int attempts{};
                std::cout << "please enter password :";
                while(!Authentication){
                    if(getvalidGetlineString(password)){
                        if(password == "admin7720"){
                            Authentication = true;
                            valid_input = true;
                            std::cout << std::string(40,'-') << std::endl;
                            return true;
                        }else{
                            ++attempts;
                            if(attempts == 3) {
                                std::cerr << "program terminated due to invalid attempts." << std::endl;
                                std::exit(EXIT_FAILURE);
                            }
                            std::cout << "invalid input or password. remaining attempts : " << (3 - attempts) << std::endl;
                            std::cout << "please enter password :";
                        }
                    }
                }
            }else if (input == 'n' || input == 'N'){
                std::cout << "loggged in with standard privileges." << std::endl;
                valid_input = true;
                std::cout << std::string(40,'-') << std::endl;
                return false;
                break;
            }else{
                std::cout << "invalid input. try again :";
            }
        }
    }

}