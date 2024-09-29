#include "classes.cpp"

// Displays the menu
// Param a: user's choice
void displayMenu(int &a);

// Allows the user to add a grade
// Param a: list of grades to add the grade to
// Param number: how many grades are already in that list
void addAGrade(GradesList &a, int &number);

// Bubble sorts the students by last names
// Param a: list of grades
void bubbleSortLastNames(GradesList &a);

// Sorts the students by first names
// Param a: list of grades
void sortFirstNames(GradesList &a);

// Displays the list of grades
// Param a: list of grades to display
void showGradesList(GradesList a);

// Delete a grade by entering a student's first and last name
// Param a: list of grades
// Param first: student's first name
//  Param last: student's last name
// Param number: number of grades in the list
void deleteGrade(GradesList &a, const char &first, const char &last, int &number);

// Show the students' average grade
// Param a: list of grades
// Param average: the average grade
void showAverageGrade(const GradesList &a, int &average);

// Increase table size once the number of students gets too high for the maximum amount
// Param a: list of grades
void increaseTableSize(GradesList &a);

// Decrease table size once the number of students gets too low for the maximum amount
// Param a: list of grades
void reduceTableSize(GradesList &a);

// Check if student is already on the list
// returns true if no students with that first and last name exists, false otherwise
// Param a: list of grades
// Param grade: new grade/student to add
bool checkNoExistingStudents(const GradesList &a, const Grade &grade);