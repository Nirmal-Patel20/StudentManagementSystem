#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"
#include "inputhandler.h"
#include <vector>
#include <fstream>
#include <filesystem>

class StudentManager {
    std::vector<Student>Students;
    std::string m_filename;

    void load_file ();
    
    void save_file ();

    void checkFileExits ();
 
    Student gatherStudentData();

public : 

    StudentManager (const std::string& filename) : m_filename(filename) {
        checkFileExits();
        load_file();
    }

    ~StudentManager (){
        save_file();
    }

    void addStudent ();

    void removeStudent ();

    void displayALL();

    void displayAll_more_details();
};


#endif