#include "Student.h"

// Constructor
Student::Student(const std::string& lastName, const std::string& firstName, int studentNumber,
                 float midterm1, float midterm2, float finalExam)
    : lastName(lastName), firstName(firstName), studentNumber(studentNumber),
      midterm1(midterm1), midterm2(midterm2), finalExam(finalExam) {}

// Getters
std::string Student::getLastName() const { return lastName; }
std::string Student::getFirstName() const { return firstName; }
int Student::getStudentNumber() const { return studentNumber; }
float Student::getMidterm1() const { return midterm1; }
float Student::getMidterm2() const { return midterm2; }
float Student::getFinalExam() const { return finalExam; }

// Setters
void Student::setLastName(const std::string& lastName) { this->lastName = lastName; }
void Student::setFirstName(const std::string& firstName) { this->firstName = firstName; }
void Student::setStudentNumber(int studentNumber) { this->studentNumber = studentNumber; }
void Student::setMidterm1(float grade) { midterm1 = grade; }
void Student::setMidterm2(float grade) { midterm2 = grade; }
void Student::setFinalExam(float grade) { finalExam = grade; }

// Calculate average
float Student::calculateAverage(float weightMidterm1, float weightMidterm2, float weightFinal) const {
    return (midterm1 * weightMidterm1 + midterm2 * weightMidterm2 + finalExam * weightFinal);
}

// Get letter grade
char Student::getLetterGrade(float weightMidterm1, float weightMidterm2, float weightFinal) const {
    float average = calculateAverage(weightMidterm1, weightMidterm2, weightFinal);
    if (average > 90) return 'A';
    if (average > 80) return 'B';
    if (average > 70) return 'C';
    if (average > 60) return 'D';
    return 'F';
}
