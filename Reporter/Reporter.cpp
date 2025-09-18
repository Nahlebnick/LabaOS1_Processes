#include <iostream>
#include <string>
#include <iomanip>
#include "employee.h"
#include "FATAL.h"
#pragma warning (disable:4996)

using namespace std;

void reportEmployee(employee& emp, double hourlyWage)
{
    double salary = hourlyWage * emp.hours;
    cout << fixed << setprecision(2);
    cout << left << setw(10) << emp.num 
        << left << setw(10) << emp.name
        << left << setw(10) << emp.hours
        << left << setw(10) << salary << endl;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RUS");
    if (argc < 4)
    {
        FATAL::PrintMessage("Usage: Reporter <binfile> <reportfile> <hourly_wage>");
        return 0;
    }

    FILE* f;
    f = fopen(argv[1], "rb");

    if (!f)
    {
        FATAL("Error while opening file");
        return 0;
    }

    std::string reportFileName = argv[2];

    double hourlyWage = std::stod(argv[3]);

    (void) freopen(reportFileName.c_str(), "w", stdout);

    cout << "Отчет по файлу \"" << argv[1] << "\"" << endl;
    cout << left << setw(10) << "Номер"
        << left << setw(10) << "Имя"
        << left << setw(10) << "Часы"
        << left << setw(10) << "Зарплата" << endl;

    employee emp;
    while (fread(&emp, sizeof(struct employee), 1, f))
    {
        reportEmployee(emp, hourlyWage);
    }
    fclose(f);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
