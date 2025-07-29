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
            std::cout << m_filename << " created successfuly." << std::endl;
            std::cout << std::string(40,'-') << std::endl;
        }else{
            std::cerr << "[ERROR] : " << std::filesystem::current_path() <<
                        " : file missing! : " << m_filename << std::endl;
            std::cerr << "Program terminated due to Fatal Error" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
}

Student StudentManager::gatherStudentData(){
    std::cout << "Enter Student Name : ";
    std::string name;
    while(!getvalidGetlineString(name)){
        std::cout << "invalid input. please try again : ";
    }

    std::cout << "Enter Student_ID : ";
    int Student_ID;
    while(!getvalidinput(Student_ID)){
        std::cout << "invalid input. please try again : ";
    }

    std::cout << "Enter Student Age : ";
    int age;
    bool isValidAge = false;
    while(!isValidAge){
        if(getvalidinput(age)){
            if(age >= 18 && age <= 30 ){
            isValidAge = true;
            break;
        }else{
            std::cout << "age must betweet 18 and 30." << std::endl;
        }
        }
        std::cout << "invalid input. please try again : ";
    }

    return Student(name,Student_ID,age);
}

Student* StudentManager::searchStudentByID(){
    std::cout << "search Student By ID" << std::endl;
    int StudentID;
    std::cout << "Enter Student ID : ";
    while(!getvalidinput(StudentID)){
        std::cout << "invalid input. please try again : ";
    }
    auto it = std::find_if(Students.begin(), Students.end(), [&]
                (const Student& s){return s.get_Student_ID() == StudentID;});

    if(it != Students.end()){
        it->display();
        std::cout << std::endl;
        return &(*it);
    }else{
        std::cout << "Student with ID " << StudentID << " does not exits." << std::endl;
        return nullptr;
    }

}

void StudentManager::finishStudentdetails(){

    auto Student_ptr = searchStudentByID();
    
    if(Student_ptr){
        std::cout << "Enter Gmail ID of Student : ";
        std::string gmail;
        std::string Userpart;
        std::string domain;
        bool isvalidGmail = false;
        while(!isvalidGmail){
            if(getvalidGetlineString(gmail)){
                auto isGmail = gmail.find('@');
                if(isGmail == std::string::npos){
                    std::cout << "missing '@' symbol. please enter a valid Gmail : ";
                    continue;
                }
                std::istringstream iss(gmail);
                std::getline(iss,Userpart,'@');
                std::getline(iss,domain);
                if(domain == "gmail.com"){
                    isvalidGmail = true;
                    break;
                }else{
                    std::cout << "the given ID is not Gmail or mail ID.  please enter a valid Gmail : ";
                    continue;
                }
            }
            std::cout << "invalid input. please try again : ";
        }

        std::cout << "Enter Student college year : ";
        bool isvalidYear = false;
        int college_year;
        while(!isvalidYear){
            if(getvalidinput(college_year)){
                if(college_year >= 1 && college_year <= 3){
                    isvalidYear = true;
                    break;
                }else{
                    std::cout << "college year must between 1 and 3. please try again : ";
                    continue;
                }
            }
            std::cout << "invalid input. please try again : ";
        }

        std::cout << "Enter Student GPA : ";
        float GPA;
        bool isValidGPA = false;
        while(!isValidGPA){
            if(getvalidinput(GPA)){
                if(college_year >= 0 && college_year <= 4){
                    isvalidYear = true;
                    break;
                }else{
                    std::cout << "GPA must between 0 and 4. please try again : ";
                    continue;
                }
            }
            std::cout << "invalid input. please try again : ";
        }
        Student_ptr->set_extra_info(gmail,college_year,GPA);
        std::cout << "detail filled ssuccessfuly." << std::endl;
    }

}

void StudentManager::addStudent(){
    std::cout << "To add Student follow below stpes : " << std::endl;
    Student src = gatherStudentData();

    auto it = std::find_if(Students.begin(), Students.end(), [&]
                (const Student& s){return s == src;});

    if(it != Students.end()){
        std::cout << "Student : " << it->get_name() << " with ID : " << src.get_Student_ID() << 
                " Already exits."<< std::endl;
        std::cout << std::endl;
    }else{
        std::cout << "Student : " << src.get_name() << " with ID : " << src.get_Student_ID() << 
                " added successfuly."<< std::endl;
        Students.push_back(src);
        std::cout << std::endl;
    }
}

void StudentManager::removeStudent (){

    std::cout << "To remove Student you must Enter their exact Name and Student ID otherwise Student wont remove." << std::endl;
    std::cout << "here Age is irrelevant as long as first two thing are match student will removed." << std::endl;

    auto originalsize = Students.size();
    
    Student src = gatherStudentData();

    Students.erase(std::remove_if(Students.begin(), Students.end(),[&] 
                    (const Student& s){return s == src;}),Students.end());

    if(Students.size() < originalsize){
        std::cout << "removed following Student : " << src.get_name() << ", Student_ID : " << src.get_Student_ID() << std::endl;
    }else{
        std::cout << "Student does not exits with name : " << src.get_name() << "and  Student_ID : " << src.get_Student_ID() << std::endl;
    }
}

void StudentManager::displayALL() {
    for(const Student& src : Students){
        src.display();
        std::cout << std::endl;
    }
}

void StudentManager::Student_more_details() {
    auto Student_ptr = searchStudentByID();

    if(Student_ptr){
        Student_ptr->display_detaild_info();
    }
}