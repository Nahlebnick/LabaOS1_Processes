#include <iostream>
#include <string>
#include <conio.h>
#include "employee.h"
#include "FATAL.h"
#pragma warning (disable:4996)
//AllurReport

using namespace std;

void writeEmployees(int empCount, FILE* f)
{
    int i = 0;
    while (i < empCount)
    {
        employee emp{};
        cin >> emp;
        if (f) fwrite(&emp, sizeof(struct employee), 1, f);
        i++;
    }
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "RUS");
    if (argc < 3)
    {
        FATAL::PrintMessage("Usage: Creator <filename> <count>");
    }

    FILE* f;
    f = fopen(argv[1], "wb");

    if (!f)
    {
        FATAL::PrintMessage("Error while opening file");
    }

    int empCount = std::stoi(argv[2]);
    writeEmployees(empCount, f);    
    if (f) fclose(f);
    return 0;

}