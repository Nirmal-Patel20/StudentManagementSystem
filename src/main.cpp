#include <iostream>
#include <Student.h>
#include <StudentManager.h>

int main() {

    StudentManager system("DataStore.txt");

    /*
    system.addStudent(Student("Nirmal",2012,19,3.9));
    system.addStudent(Student("Shruti",7778,22,3));
    system.addStudent(Student("Janvi",2312,20,3.8));
    */

    system.removeStudentById(7778);

    system.displayALL();
    
    return 0;
}