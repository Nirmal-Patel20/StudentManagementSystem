#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <sstream>

class Student {
    std::string m_name{"none"};
    int m_age {0};
    int m_student_ID {0};
    float m_GPA {0};

public : 
    Student () = default;
    Student (std::string_view name,int age,int student_ID,float GPA);

    friend std::ostream& operator<< (std::ostream& os,const Student& src);

    friend std::istream& operator>> (std::istream& is,Student& src);

    int get_Student_ID () const;
};

#endif