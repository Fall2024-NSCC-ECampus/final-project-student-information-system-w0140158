#include "StudentManager.h"
#include <iostream>
#include <iomanip>
#include <limits>

// Function to display the menu
void printMenu() {
    std::cout << "\n==============================\n"
              << "     Student Management       \n"
              << "==============================\n"
              << "1. Add Student\n"
              << "2. Remove Student\n"
              << "3. Print All Students\n"
              << "4. Print Students Sorted\n"
              << "5. Print Specific Student\n"
              << "6. Delete All Students\n"
              << "7. Set Grade Weights\n"
              << "8. Exit\n"
              << "==============================\n"
              << "Enter your choice: ";
}

// Utility function to handle input errors
void handleInputError() {
    std::cin.clear(); // Clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    std::cout << "\n[Error] Invalid input. Please try again.\n";
}

// Main program
int main() {
    StudentManager manager;
    int choice;

    do {
        printMenu();

        // Validate the choice input
        if (!(std::cin >> choice)) {
            handleInputError();
            continue;
        }

        try {
            switch (choice) {
                case 1: {
                    std::string lastName, firstName;
                    int studentNumber;
                    float midterm1, midterm2, finalExam;

                    std::cout << "\n--- Add New Student ---\n";
                    std::cout << "Enter Last Name: ";
                    std::cin >> lastName;

                    std::cout << "Enter First Name: ";
                    std::cin >> firstName;

                    std::cout << "Enter Student Number: ";
                    if (!(std::cin >> studentNumber)) {
                        handleInputError();
                        break;
                    }

                    std::cout << "Enter Midterm 1 Grade (0-100): ";
                    if (!(std::cin >> midterm1) || midterm1 < 0 || midterm1 > 100) {
                        handleInputError();
                        break;
                    }

                    std::cout << "Enter Midterm 2 Grade (0-100): ";
                    if (!(std::cin >> midterm2) || midterm2 < 0 || midterm2 > 100) {
                        handleInputError();
                        break;
                    }

                    std::cout << "Enter Final Exam Grade (0-100): ";
                    if (!(std::cin >> finalExam) || finalExam < 0 || finalExam > 100) {
                        handleInputError();
                        break;
                    }

                    // Add the student
                    manager.addStudent(Student(lastName, firstName, studentNumber, midterm1, midterm2, finalExam));
                    std::cout << "\n[Success] Student added successfully.\n";
                    break;
                }
                case 2: {
                    int studentNumber;
                    std::cout << "\n--- Remove Student ---\n";
                    std::cout << "Enter Student Number to Remove: ";
                    if (!(std::cin >> studentNumber)) {
                        handleInputError();
                        break;
                    }

                    manager.removeStudent(studentNumber);
                    std::cout << "\n[Info] Student removed (if found).\n";
                    break;
                }
                case 3: {
                    std::cout << "\n--- All Students ---\n";
                    manager.printAllStudents();
                    break;
                }
                case 4: {
                    std::cout << "\n--- Students Sorted Alphabetically ---\n";
                    manager.printStudentsSorted();
                    break;
                }
                case 5: {
                    int studentNumber;
                    std::cout << "\n--- Student Details ---\n";
                    std::cout << "Enter Student Number: ";
                    if (!(std::cin >> studentNumber)) {
                        handleInputError();
                        break;
                    }

                    manager.printStudent(studentNumber);
                    break;
                }
                case 6: {
                    std::cout << "\n--- Delete All Students ---\n";
                    manager.deleteAllStudents();
                    std::cout << "\n[Success] All student data has been deleted.\n";
                    break;
                }
                case 7: {
                    float weightMidterm1, weightMidterm2, weightFinal;
                    std::cout << "\n--- Set Grade Weights ---\n";

                    std::cout << "Enter weight for Midterm 1 (e.g., 0.25): ";
                    if (!(std::cin >> weightMidterm1)) {
                        handleInputError();
                        break;
                    }

                    std::cout << "Enter weight for Midterm 2 (e.g., 0.25): ";
                    if (!(std::cin >> weightMidterm2)) {
                        handleInputError();
                        break;
                    }

                    std::cout << "Enter weight for Final Exam (e.g., 0.50): ";
                    if (!(std::cin >> weightFinal)) {
                        handleInputError();
                        break;
                    }

                    if (weightMidterm1 + weightMidterm2 + weightFinal != 1.0) {
                        std::cout << "\n[Error] Invalid weights! The total must equal 1.0.\n";
                    } else {
                        manager.setGradeWeights(weightMidterm1, weightMidterm2, weightFinal);
                        std::cout << "\n[Success] Grade weights have been updated.\n";
                    }
                    break;
                }
                case 8:
                    std::cout << "\n[Info] Exiting program. Goodbye!\n";
                    break;
                default:
                    std::cout << "\n[Error] Invalid choice. Please try again.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "\n[Exception] " << e.what() << "\n";
        }
    } while (choice != 8);

    return 0;
}
