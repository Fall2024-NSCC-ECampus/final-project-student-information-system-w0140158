#include "StudentManager.h"
#include <iostream>

// Add a student
void StudentManager::addStudent(const Student& student) {
    students.push_back(student);
}

// Remove a student
void StudentManager::removeStudent(int studentNumber) {
    std::erase_if(students,
                  [studentNumber](const Student& s) { return s.getStudentNumber() == studentNumber; });
}

// Print all students
void StudentManager::printAllStudents() const {
    for (const auto& student : students) {
        std::cout << student.getLastName() << ", " << student.getFirstName()
                  << " (" << student.getStudentNumber() << ")\n";
    }
}

// Print students sorted
void StudentManager::printStudentsSorted() const {
    std::vector<Student> sortedStudents = students;
    std::sort(sortedStudents.begin(), sortedStudents.end(), compareStudents);
    for (const auto& student : sortedStudents) {
        std::cout << student.getLastName() << ", " << student.getFirstName()
                  << " (" << student.getStudentNumber() << ")\n";
    }
}

// Print a specific student's data
void StudentManager::printStudent(int studentNumber) const {
    for (const auto& student : students) {
        if (student.getStudentNumber() == studentNumber) {
            std::cout << "Name: " << student.getFirstName() << " " << student.getLastName() << "\n"
                      << "Student Number: " << student.getStudentNumber() << "\n"
                      << "Midterm 1: " << student.getMidterm1() << "\n"
                      << "Midterm 2: " << student.getMidterm2() << "\n"
                      << "Final Exam: " << student.getFinalExam() << "\n";
            return;
        }
    }
    std::cout << "Student not found.\n";
}

// Delete all students
void StudentManager::deleteAllStudents() {
    students.clear();
}

// Set grade weights
void StudentManager::setGradeWeights(float weightMidterm1, float weightMidterm2, float weightFinal) {
    this->weightMidterm1 = weightMidterm1;
    this->weightMidterm2 = weightMidterm2;
    this->weightFinal = weightFinal;
}

// Compare students
bool StudentManager::compareStudents(const Student& a, const Student& b) {
    if (a.getLastName() == b.getLastName()) {
        return a.getFirstName() < b.getFirstName();
    }
    return a.getLastName() < b.getLastName();
}
