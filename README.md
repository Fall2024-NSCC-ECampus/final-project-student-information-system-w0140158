# Student Information System

A C++ based Student Information System that allows users to manage a list of students, including adding, removing, viewing, and sorting student information. The system also calculates letter grades for students based on their scores in midterms and final exams.

## Features

- **Add Student**: Add a new student with last name, first name, student number, and grades for two midterms and the final exam.
- **Remove Student**: Remove a student by their student number.
- **View All Students**: Print a list of all students.
- **Sort Students**: Print students sorted by last name and first name if last names are identical.
- **View Specific Student**: View information for a specific student by their student number.
- **Delete All Students**: Delete all students from the list.
- **Set Grade Weights**: Set the percentage weights for midterm 1, midterm 2, and final exam grades (default is 25% for midterms and 50% for the final).
- **Grade Calculation**: The system calculates and assigns letter grades based on the average score:
  - **A**: Average > 90%
  - **B**: 80% <= Average <= 90%
  - **C**: 70% <= Average < 80%
  - **D**: 60% <= Average < 70%
  - **F**: Average < 60%

## Installation

### Requirements

- C++ Compiler (e.g., GCC or Clang)
- CMake (for building the project)

### Steps to Set Up

1. Clone the repository:
   ```bash
   git clone https://github.com/Fall2024-NSCC-ECampus/final-project-student-information-system-w0140158.git
   cd final-project-student-information-system-w0140158
