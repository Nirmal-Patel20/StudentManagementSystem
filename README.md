# 🎓 Student Management System (C++)

A simple console-based Student Management System built in C++ using Object-Oriented Programming (OOP) principles and file handling. It allows adding, saving, loading, and removing student data using persistent storage (text files). Designed for practicing class structure, file I/O, and STL containers.

---

## ✅ Features

- Add student (name, ID, age, GPA)
- Store students in a `std::vector`
- Save students to a `DataStore.txt` file
- Load students from a `DataStore.txt` file
- Remove students from memory and file
- Auto-load/save using constructors/destructors
- Overloaded `<<` operator for flexible output (`std::cout`, `std::ofstream`)
- Organized modular code structure
- Minimal/no console interaction required — values are directly passed
- Before running, the program checks whether a required file exists. if the file is missing, the program will terminate

---

## 📁 Project Structure

```StudentManagementSystem/
├── include/
│   ├── Student.h
│   └── StudentManager.h
│
├── src/
│   ├── main.cpp
│   ├── Student.cpp
│   └── StudentManager.cpp
│
├── DataStore.txt
├── .gitignore
├── CMakeLists.txt
├── README.md
```

---

## 🛠 How to Build & Run

### Using g++ (Linux/macOS/WSL):

```bash
g++ src/*.cpp -o StudentApp
./StudentApp
```
> [!caution]
> Make sure your terminal path is inside the project root.

### using g++(window)
```bash
g++ src/*.cpp -o StudentApp.exe
StudentApp.exe
```
> [!caution]
> Make sure your terminal path is inside the project root.

### using Cmake(Linux/macOS/Window)

```bash
cmake --preset ninja-release
cmake --build build/ninja-release
.\build\ninja-release\StudentManagementSystem.exe 
```
> [!Note]
> Executable will be inside `build\ninja-release` named `StudentManagementSystem.exe`.

---

## 📚 How to Use the Program
 ### Program Behavior
 - The app automatically loads existing student data from a file (`DataStore.txt`) on startup.

 - It internally manages students using a class and a vector.

 - it is totaly console base now and you can just run program

 - Display current students to the console or write them to a file
 - When it exits, it saves all student data back to the file. 

 > [!warning]
 > if file name `DataStore.txt` does not exits in current directory, the program will ask if you want
 > to create automaticlly if permission decline program will terminate.

    
---

## 🧠 Concepts Practiced
- Object-Oriented Programming
- File I/O (fstream)
- Operator Overloading
- RAII (automatic loading and saving)
- std::vector, std::string
- Separation of concerns (header/source split)
- git & GitHub version control

---

## 🔐 GitHub Setup
- Git tracked .txt files store student data (data/students.txt)
- `.gitignore` used to exclude build files
- Modular layout for clean version control

## 📢 Status
Project is completed ✅
- Currently functional : 
  - add and remove Student
  - automatic loading and saving

- future features may include:
  - [x] Edit student details (except Name,Student ID,Age)
  - [x] More details of Students
  - [x] find more details of specific Student if uploaded

## 🧑‍💻 Author
- Nirmal Patel — Aspiring C++ developer working on real-world practice projects before university.