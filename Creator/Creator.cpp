#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "employee.h"
#include "FATAL.h"
#include "FileUtils/FileUitls.h"
#pragma warning (disable:4996)
//AllurReport

using namespace std;

vector<employee> getEmployees(int empCount)
{
    vector<employee> employees;
    int i = 0;
    while (i < empCount)
    {
        employee emp;
        cin >> emp;
        employees.push_back(emp);
        i++;
    }
    return employees;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "RUS");
    if (argc < 3)
    {
        FATAL::PrintMessage("Usage: Creator <filename> <count>");
    }

    string filename = argv[1];

    int empCount = std::stoi(argv[2]);

    auto employees = getEmployees(empCount);
    writeEmployeesIntoFile(filename, employees);
    return 0;

}