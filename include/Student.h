#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student {
    std::string m_name{"none"};
    int m_age {0};
    int m_student_ID {0};
    float m_GPA {0};

public : 

    Student (std::string_view name,int age,int student_ID,float GPA);

    friend std::ostream& operator<< (std::ostream& os,const Student& src);

    friend std::istream& operator>> (std::istream& is,const Student& src);
};

#endif