#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"
#include <vector>
#include <fstream>
#include <filesystem>

class StudentManager {
    std::vector<Student>Students;
    std::string m_filename;

    void load_file ();
    
    void save_file ();

    void checkFileExits ();

public : 

    StudentManager (const std::string& filename) : m_filename(filename) {
        checkFileExits();
        load_file();
    }

    ~StudentManager (){
        save_file();
    }

    void addStudent (const Student& src);

    void removeStudentById (int Student_ID);

    void displayALL();
};


#endif