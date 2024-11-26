#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.h"
#include <vector>
#include <algorithm>

class StudentManager {
private:
    std::vector<Student> students;
    float weightMidterm1 = 0.25;
    float weightMidterm2 = 0.25;
    float weightFinal = 0.50;

public:
    // Add a student
    void addStudent(const Student& student);

    // Remove a student by student number
    void removeStudent(int studentNumber);

    // Print all students
    void printAllStudents() const;

    // Print students in alphabetical order
    void printStudentsSorted() const;

    // Print a specific student's data
    void printStudent(int studentNumber) const;

    // Delete all students
    void deleteAllStudents();

    // Set grade weights
    void setGradeWeights(float weightMidterm1, float weightMidterm2, float weightFinal);

    // Utility: Compare students
    static bool compareStudents(const Student& a, const Student& b);
};

#endif // STUDENT_MANAGER_H
