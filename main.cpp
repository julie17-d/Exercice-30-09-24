#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    int menuChoice(0), average(0);
    GradesList gradesList;
    gradesList.nb = 0;
    gradesList.table = new Grade[gradesList.nbMax];

    while (true)
    {
        displayMenu(menuChoice);

        switch (menuChoice)
        {
        case 1:
            addAGrade(gradesList, gradesList.nb);
            break;
        case 2:
            bubbleSortLastNames(gradesList);
            sortFirstNames(gradesList);
            showGradesList(gradesList);
            break;
        case 3:
            char firstName[9];
            char lastName[9];
            cout << "Enter student's last name:" << endl;
            cin >> lastName;
            cout << "Enter student's first name" << endl;
            cin >> firstName;
            deleteGrade(gradesList, *firstName, *lastName, gradesList.nb);
            break;
        case 4:
            showAverageGrade(gradesList, average);
            break;
        case 5:
            delete[]gradesList.table;
            return 0;
        default:
            cout << "There's been an error. Please try again." << endl;
            break;
        }
    }

    delete[]gradesList.table;

    return 0;
}