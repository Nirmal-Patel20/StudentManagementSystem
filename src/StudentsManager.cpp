#include "StudentsManager.h"

void StudentsManager::load_file (){

    Student S1;
    std::ifstream infile(m_filename);

    if(infile.is_open()){
        while(infile >> S1){
        Students.push_back(S1);
        }
    }else{
        std::cout << "fail to open file : " << m_filename << std::endl;
    }
}

void StudentsManager::save_file(){

    std::ofstream outfile(m_filename);

    if(outfile.is_open()){
        for(const Student src : Students){
            outfile << src << std::endl;
        }
    }else{
        std::cout << "fail to open file : " << m_filename << std::endl;
    }
}

void StudentsManager::addStudent(const Student& src){
    Students.push_back(src);
}

void StudentsManager::removeStudentById(int Student_ID){
    for(auto it = Students.begin(); it != Students.end();++it){
        if(it->get_Student_ID() == Student_ID){
            Students.erase(it);
            break;
        }
    }
}

void StudentsManager::displayALL() {
    for(const Student& src : Students){
        std::cout << src << std::endl;
    }
}