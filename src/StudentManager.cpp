#include "StudentManager.h"

void StudentManager::load_file (){

    Student S1;
    std::ifstream infile(m_filename);

    if(infile.is_open()){
        while(infile >> S1){
        Students.emplace_back(S1);
        }
    }else{
        std::cerr << "fail to open file : " << m_filename << std::endl;
        std::cerr << "[ERROR] : Program terminated due to Fatal Error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void StudentManager::save_file(){

    std::ofstream outfile(m_filename);

    if(outfile.is_open()){
        for(const Student src : Students){
            outfile << src << std::endl;
        }
    }else{
        std::cerr << "fail to open file : " << m_filename << std::endl;
        std::cerr << "Program terminated due to Fatal Error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void StudentManager::checkFileExits(){
    if(!std::filesystem::exists(m_filename)){
        std::cerr << "[ERROR] : " << std::filesystem::current_path() <<
                        " : file missing! : " << m_filename << std::endl;
        std::cout << std::endl;
        std::cout << "would you like to create one[Y,N] : ";
        char input;
        std::cin >> input;
        if(input == 'y' || input == 'Y'){
            std::ofstream createdfile (m_filename);
            if(!createdfile){
                std::cerr << "fail to open file : " << m_filename << std::endl;
                std::cerr << "Program terminated due to Fatal Error" << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }else{
            std::cerr << "[ERROR] : " << std::filesystem::current_path() <<
                        " : file missing! : " << m_filename << std::endl;
            std::cerr << "Program terminated due to Fatal Error" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
}

void StudentManager::addStudent(const Student& src){
    auto it = std::find_if(Students.begin(), Students.end(), [&]
                (const Student& s){return s.get_Student_ID() == src.get_Student_ID();});

    if(it != Students.end()){
        std::cout << "Student : " << it->get_name() << " with ID : " << src.get_Student_ID() << 
                " Already exits."<< std::endl;
    }else{
        std::cout << "Student : " << src.get_name() << " with ID : " << src.get_Student_ID() << 
                " added successfuly."<< std::endl;
        Students.push_back(src);
    }
}

void StudentManager::removeStudentById (int Student_ID){
    auto originalsize = Students.size();

    Students.erase(std::remove_if(Students.begin(), Students.end(),[Student_ID] 
                    (const Student& s){return s.get_Student_ID() == Student_ID;}),Students.end());

    if(Students.size() < originalsize){
        std::cout << "Student remove successful. ID : " << Student_ID << std::endl;
    }else{
        std::cout << "Student don't exits with ID : " << Student_ID << std::endl;
    }
}

void StudentManager::displayALL() {
    for(const Student& src : Students){
        src.display();
    }
}