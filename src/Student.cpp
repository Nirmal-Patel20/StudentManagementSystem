#include "Student.h"

Student::Student (std::string_view name,int student_ID,int age) : m_name(name), m_student_ID(student_ID),
                    m_age(age) {

}

std::ostream& operator<< (std::ostream& os,const Student& src){
    os << src.m_name << ","  << src.m_student_ID << ","  << src.m_age << "," << src.m_email << "," 
            << src.m_college_year << "," << src.m_GPA << ".";
    return os;
}

std::istream& operator>> (std::istream& is,Student& src){
    std::string line;

    if(std::getline(is,line)){
        std::istringstream iss (line);
        std::getline(iss,src.m_name,',');

        std::string stringTo;

        std::getline(iss,stringTo,',');
        src.m_student_ID = std::stoi(stringTo);

        std::getline(iss,stringTo,',');
        src.m_age = std::stoi(stringTo);

        std::getline(iss,src.m_email,',');

        std::getline(iss,stringTo,',');
        src.m_college_year = std::stoi(stringTo);

        std::getline(iss,stringTo,'.');
        src.m_GPA = std::stof(stringTo);
    }

    return is;

}

bool Student::operator== (const Student& src){
    if(m_name == src.m_name && m_student_ID == src.m_student_ID){
        return true;
    }else{
        return false;
    }
}

std::string Student::get_name() const {
    return m_name;
}

int Student::get_Student_ID () const {
    return m_student_ID;
}

int Student::get_age () const {
    return m_age;
}

void Student::set_extra_info(std::string_view email ,int college_year, float GPA){
    m_email = email;
    m_college_year = college_year;
    m_GPA = GPA;
}

void Student::display() const {
    std::cout << "Name : " << m_name << ", Student_ID : " << m_student_ID << ", Age : " 
                    << m_age << std::endl;
}

void Student::display_detaild_info () const {
    display();
    std::cout << "email_ID : " << m_email << ", College year : " << m_college_year << ", GPA : " << m_GPA << std::endl;
}