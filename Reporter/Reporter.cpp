#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "employee.h"
#include "FATAL.h"
#include "FileUtils/FileUitls.h"
#pragma warning (disable:4996)

using namespace std;

void reportEmployees(vector<employee>& employees, double hourlyWage, ostream& out)
{
    int i = 0;
    while (i < employees.size())
    {
        double salary = hourlyWage * employees[i].hours;
        out << std::fixed << std::setprecision(2);
        out << std::left << std::setw(10) << employees[i].num
            << std::left << std::setw(10) << employees[i].name
            << std::left << std::setw(10) << employees[i].hours;
        out << left << setw(10) << salary << endl;
        i++;
    }
    
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RUS");
    if (argc < 4)
    {
        FATAL::PrintMessage("Usage: Reporter <binfile> <reportfile> <hourly_wage>");
    }

    string reportFileName = argv[2];

    double hourlyWage;
    try
    {
        hourlyWage = stod(argv[3]);
    }
    catch (...)
    {
        FATAL::PrintMessage("Ошибка: ставка должна быть числом");
    }

    ofstream fout(reportFileName);
    if (!fout)
    {
        FATAL::PrintMessage("Не удалось открыть файл отчёта");
    }

    auto employees = readEmployeesFromFile(argv[1]);

    fout << "\n=== Отчёт из файла " << argv[1] << " ===\n\n";
    fout << left << setw(10) << "Номер"
        << left << setw(10) << "Имя"
        << left << setw(10) << "Часы"
        << left << setw(10) << "Зарплата" << endl;

    reportEmployees(employees, hourlyWage, fout);
    fout << "\n=== Конец отчёта ===\n";

    return 0;
}
