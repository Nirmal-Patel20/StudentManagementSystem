#include "Student.h"

Student::Student (std::string_view name,int student_ID,int age,float GPA) : m_name(name), m_student_ID(student_ID),
                    m_age(age), m_GPA(GPA) {

}

std::ostream& operator<< (std::ostream& os,const Student& src){
    os << src.m_name << ","  << src.m_student_ID << ","  << src.m_age << "," << src.m_GPA << ".";
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

        std::getline(iss,stringTo,'.');
        src.m_GPA = std::stof(stringTo);
    }

    return is;

}

std::string Student::get_name() const {
    return m_name;
}

int Student::get_Student_ID () const {
    return m_student_ID;
}

 void Student::display() const {
    std::cout << "Name : " << m_name << ", Student_ID : " << m_student_ID << ", Age : " 
                    << m_age << ", GPA : " << m_GPA << std::endl;
 }