#include <iostream>
#include <iomanip>

struct employee
{
    int num;
    char name[10];
    double hours;

    friend std::istream& operator>>(std::istream&, employee&);
    friend std::ostream& operator<<(std::ostream&, const employee&);
    void showAsString(std::ostream&);
};