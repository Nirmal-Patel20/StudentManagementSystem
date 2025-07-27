#include "StudentManager.h"

void StudentManager::load_file (){

    Student S1;
    std::ifstream infile(m_filename);

    if(infile.is_open()){
        while(infile >> S1){
        Students.push_back(S1);
        }
    }else{
        std::cerr << "fail to open file : " << m_filename << std::endl;
        std::cerr << "[ERROR] : Program terminated due to Fatal Error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void StudentManager::save_file(){

    std::ofstream outfile(m_filename);

    if(outfile.is_open()){
        for(const Student src : Students){
            outfile << src << std::endl;
        }
    }else{
        std::cerr << "fail to open file : " << m_filename << std::endl;
        std::cerr << "Program terminated due to Fatal Error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void StudentManager::checkFileExits(){
    if(!std::filesystem::exists(m_filename)){
        std::cerr << "[ERROR] : " << std::filesystem::current_path() <<
                        " : file missing! : " << m_filename << std::endl;
        std::cerr << "Program terminated due to Fatal Error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void StudentManager::addStudent(const Student& src){
    Students.push_back(src);
}

void StudentManager::removeStudentById(int Student_ID){
    for(auto it = Students.begin(); it != Students.end();++it){
        if(it->get_Student_ID() == Student_ID){
            Students.erase(it);
            break;
        }
    }
}

void StudentManager::displayALL() {
    for(const Student& src : Students){
        src.display();
    }
}