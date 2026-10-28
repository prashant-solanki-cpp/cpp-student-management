# Student Management System in C++

A console-based Student Management System developed using C++. This project allows users to manage student records through a simple menu-driven interface, with file handling for data persistence.

## Features

- **Add Student:** Add student details including ID, name, and age.
- **Search Student:** Find a student using their ID.
- **Update Student:** Modify a student's ID, name, or age.
- **Delete Student:** Remove a student record.
- **Display Students:** View all stored student records.
- **Input Validation:** Prevent duplicate IDs and validate student ages (1–90).
- **File Handling:** Load student records from a text file at startup and save them on exit.

## Technologies Used

- C++
- STL (`vector`, `algorithm`, `sstream`)
- File Handling (`ifstream`, `ofstream`)
- Basic Input Validation

## How to Run

1. Clone or download this repository.
2. Open a terminal in the project folder.
3. Compile the program:

   ```bash
   g++ main.cpp -o student_management
   ```

4. Run the program:

   **Windows:**
   ```bash
   student_management.exe
   ```

   **Linux/macOS:**
   ```bash
   ./student_management
   ```

## Data Storage

Student records are stored in `student_management_data.txt` in the following format:

```text
101|Prashant Solanki|21
102|Rahul Sharma|20
```

The program loads records when it starts and saves the current records when the user exits.

## Learning Outcomes

- Practiced structures and vectors in C++.
- Implemented CRUD operations (Create, Read, Update, Delete).
- Worked with input validation and file handling.
- Practiced organizing a program using functions.

## Future Improvements

- Handle corrupted or invalid file records safely.
- Improve error handling for file operations.
- Simplify ID management and improve code organization.

---

**Project:** Student Management System  
**Language:** C++
