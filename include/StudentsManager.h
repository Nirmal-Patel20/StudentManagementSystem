#ifndef STUDENTSMANAGER_H
#define STUDENTSMANAGER_H

#include "Student.h"
#include <vector>
#include <fstream>

class StudentsManager {
    std::vector<Student>Students;
    std::string m_filename;

    void load_file ();
    
    void save_file ();

public : 

    StudentsManager (const std::string& filename) : m_filename(filename) {
        load_file();
    }

    ~StudentsManager (){
        save_file();
    }

    void addStudent (const Student& src);

    void removeStudentById (int Student_ID);

    void displayALL();
};


#endif