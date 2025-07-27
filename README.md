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

---

## 📁 Project Structure

````Project/
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
├── README.md```

    