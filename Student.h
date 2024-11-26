#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string lastName;
    std::string firstName;
    int studentNumber;
    float midterm1;
    float midterm2;
    float finalExam;

public:
    // Constructor
    Student(const std::string& lastName, const std::string& firstName, int studentNumber,
            float midterm1, float midterm2, float finalExam);

    // Getters and setters
    std::string getLastName() const;
    std::string getFirstName() const;
    int getStudentNumber() const;
    float getMidterm1() const;
    float getMidterm2() const;
    float getFinalExam() const;

    void setLastName(const std::string& lastName);
    void setFirstName(const std::string& firstName);
    void setStudentNumber(int studentNumber);
    void setMidterm1(float grade);
    void setMidterm2(float grade);
    void setFinalExam(float grade);

    // Calculate average grade
    float calculateAverage(float weightMidterm1, float weightMidterm2, float weightFinal) const;

    // Get letter grade
    char getLetterGrade(float weightMidterm1, float weightMidterm2, float weightFinal) const;
};

#endif // STUDENT_H
