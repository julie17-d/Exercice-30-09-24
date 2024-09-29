class Grade
{
public:
    char lastName[9];
    char firstName[9];
    int value;
};

class GradesList
{
public:
    int nb;
    int inc = 5;
    int nbMax = inc;
    Grade *table;
};
