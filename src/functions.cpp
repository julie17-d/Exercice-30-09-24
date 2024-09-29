#include "functions.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void displayMenu(int &a)
{
    cout << "Enter the number that corresponds with what you want to do:" << endl
         << "1. Add a grade." << endl
         << "2. Display the list of grades." << endl
         << "3. Delete a student's grade." << endl
         << "4. Display the average grade." << endl
         << "5. Exit." << endl;

    string b("");
    cin >> b;
    
    a = stoi(b);

    return;
}

void increaseTableSize(GradesList &a)
{
    if (a.nb == a.nbMax)
    {
        Grade *newGradesList = new Grade[a.nbMax + a.inc];
        for (int i = 0; i < a.nb; i++)
        {
            newGradesList[i] = a.table[i];
        }
        delete[] a.table;
        a.table = newGradesList;
        a.nbMax += a.inc;
    }
    return;
}

void reduceTableSize(GradesList &a)
{
    if (a.nb < a.nbMax - a.inc)
    {
        Grade *newGradesList = new Grade[a.nbMax - a.inc];
        for (int i = 0; i < a.nb; i++)
        {
            newGradesList[i] = a.table[i];
        }
        delete[] a.table;
        a.table = newGradesList;
        a.nbMax -= a.inc;
    }
    return;
}

bool checkNoExistingStudents(const GradesList &a, const Grade &grade)
{
    for (int i = 0; i < a.nb; i++)
    {
        if (!strcmp(a.table[i].lastName, grade.lastName) && !strcmp(a.table[i].firstName, grade.firstName))
        {
            return false;
        }
    }

    return true;
}

void addAGrade(GradesList &a, int &number)
{
    Grade grade;

    cout << "Enter the student's last name:" << endl;
    cin >> grade.lastName;
    cout << "Enter the student's first name:" << endl;
    cin >> grade.firstName;
    cout << "Enter the student's grade:" << endl;
    cin >> grade.value;

    if (checkNoExistingStudents(a, grade))
    {
        a.table[number] = grade;
        number++;
    }
    else
    {
        cout << "This student already has a grade." << endl;
    }

    increaseTableSize(a);

    return;
}

void bubbleSortLastNames(GradesList &a)
{
    int n = a.nb;
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a.table[j].lastName[0] > a.table[j + 1].lastName[0])
            {
                swap(a.table[j], a.table[j + 1]);
                swapped = true;
            }
            else if (a.table[j].lastName[0] == a.table[j + 1].lastName[0])
            {
                for (int x = 1; x < 9; x++)
                {
                    if (a.table[j].lastName[x] > a.table[j + 1].lastName[x])
                    {
                        swap(a.table[j], a.table[j + 1]);
                        swapped = true;
                    }
                }
            }
        }
        if (!swapped)
            break;
    }
    return;
}

void sortFirstNames(GradesList &a)
{
    int n = a.nb;

    for (int i = 0; i < n - 1; i++)
    {
        if (!strcmp(a.table[i].lastName, a.table[i + 1].lastName))
        {
            for (int x = 0; x < 9; x++)
            {
                if (a.table[i].firstName[0] > a.table[i + 1].firstName[0])
                {
                    swap(a.table[i], a.table[i + 1]);
                }
            }
        }
    }
    return;
}

void showGradesList(GradesList a)
{
    int i;

    for (i = 0; i < a.nb; i++)
    {
        cout << a.table[i].lastName << ", " << a.table[i].firstName << ": " << a.table[i].value << endl;
    }

    return;
}

void deleteGrade(GradesList &a, const char &first, const char &last, int &number)
{
    bool match = false;

    for (int i = 0; i < a.nb; i++)
    {
        if (!strcmp(a.table[i].lastName, &last) && !strcmp(a.table[i].firstName, &first))
        {
            match = true;
        }

        if (match)
        {
            a.table[i] = a.table[i + 1];
        }
    }

    number--;

    reduceTableSize(a);
    return;
}

void showAverageGrade(const GradesList &a, int &average)
{
    int b(0);

    for (int i = 0; i < a.nb; i++)
    {
        b += a.table[i].value;
    }

    average = b / a.nb;

    cout << "The average grade is: " << average << endl;
    return;
}