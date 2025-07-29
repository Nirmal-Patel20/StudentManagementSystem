#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <sstream>

class Student {
    std::string m_name{"none"};
    int m_student_ID {0};
    int m_age {0};
    std::string m_email{"not given"};
    int m_college_year {0};
    float m_GPA {0};

public : 
    Student () = default;
    Student (std::string_view name,int student_ID,int age);

    friend std::ostream& operator<< (std::ostream& os,const Student& src);

    friend std::istream& operator>> (std::istream& is,Student& src);

    bool operator== (const Student& src);

    //getters
    std::string get_name() const;
    int get_Student_ID() const;
    int get_age() const;

    //setters
    void set_extra_info(std::string_view email ,int college_year, float GPA);

    void display () const;

    void display_detaild_info() const;
};

#endif