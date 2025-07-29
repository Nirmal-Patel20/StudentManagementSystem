#include <iostream>
#include "Student.h"
#include "StudentManager.h"
#include "inputhandler.h"
#include "login.h"

int main() {

    StudentManager system("DataStore.txt");

    std::cout << "Student Management System : " << std::endl;

    bool loginasAdmin = loginstatus(); //password : admin7720
    bool exits = false;
    while (!exits){
        char choice{0};
        std::cout << std::string(40,'-') << std::endl;
        std::cout << "1. view Students List" << std::endl;
        std::cout << "2. Search StudentByID" << std::endl;
        std::cout << "3. fill extra Student Detailts" << std::endl;
        if(loginasAdmin){
            std::cout << "4. add Student" << std::endl;
            std::cout << "5. remove Student" << std::endl;
            std::cout << "6. view more detail of Specific Student" << std::endl;
        }
        std::cout << "press 'Q' or 'q' to exits" << std::endl;
        std::cout << std::string(40,'-') << std::endl;
        std::cout << std::string(40,'-') << std::endl;

        std::cout << "input : ";
        bool validInput = false;
        while (!validInput){
            if(getvalidinput(choice)){
                if((choice >= '1' && choice <= '6') && loginasAdmin){
                    validInput = true;
                    break;
                }else if(choice == '1' || choice == '3'){
                    validInput = true;
                    break;
                }else if(choice == 'q' || choice == 'Q'){
                    validInput = true;
                    exits = true;
                    break;
                }else{
                    std::cout << "invalid Input. please try again : ";
                    continue;
                }
            }
            std::cout << "invalid Input. please try again : ";
        }

        
        switch (choice)
        {
        case '1':
            system.displayALL();
            break;

        case '2':
            system.searchStudentByID();
            break;
                
        case '3':
            system.finishStudentdetails();
            break;

        case '4':
            system.addStudent();
            break;

        case '5':
            system.removeStudent();
            break;

        case '6':
            system.Student_more_details();
            break;
        }

        
    }

    return 0;
}