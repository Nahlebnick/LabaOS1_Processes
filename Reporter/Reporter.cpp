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
    emp.showAsString(cout);
    cout << left << setw(10) << salary << endl;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RUS");
    if (argc < 4)
    {
        FATAL::PrintMessage("Usage: Reporter <binfile> <reportfile> <hourly_wage>");
    }

    FILE* f;
    f = fopen(argv[1], "rb");

    if (!f)
    {
        FATAL::PrintMessage("Error while opening file");
    }

    std::string reportFileName = argv[2];

    double hourlyWage = std::stod(argv[3]);

    (void) freopen(reportFileName.c_str(), "w", stdout);

    cout << "\n=== Отчёт из файла " << argv[1] << " ===\n\n";
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
