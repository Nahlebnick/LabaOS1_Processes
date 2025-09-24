#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

#define NOMINMAX
#include <windows.h>

#include "employee.h"
#include "FATAL.h"
#include "InputUtils/InputUtils.h"
#include "ProcessUtils/ProcessUtils.h"
#include "FileUtils/FileUitls.h"

#pragma warning (disable:4996)

using namespace std;

void printEmployees(const vector<employee>& employees)
{
    cout << "-------------------------------\n";
    int i = 0;
    while (i < employees.size())
    {
        cout << employees[i] << endl;
        i++;
    }
    cout << "-------------------------------\n";
}

void printReport(string filename)
{
    ifstream file(filename);
    if (!file)
    {
        FATAL("Error while opening report file for printing");
    }

    cout << "\n=== Отчёт из файла " << filename << " ===\n\n";

    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    cout << "\n=== Конец отчёта ===\n";
}

void startCreator(const string& binfile, int count)
{
    string commandLine = "Creator.exe " + binfile + " " + to_string(count);
    StartProcess(commandLine, "Error: cannot start Creator");
}

void startReporter(const string& binfile, string reportfile, double rate)
{
    string commandLine = "Reporter.exe " + binfile + " " + reportfile + " " + to_string(rate);
    StartProcess(commandLine, "Error: cannot start Creator");
}

int main()
{
    setlocale(LC_ALL, "rus");
    string binfile;
    int count;

    cout << "Введите название бинарного файла (расширение по умолчанию.bin): ";
    binfile = getFilename(cin, ".bin");
    cout << "Введите количество записей: ";
    count = getIntValue(cin);

    startCreator(binfile, count);

    cout << "\nСодержимое файла:\n";
    auto employees = readEmployeesFromFile(binfile);
    printEmployees(employees);

    string reportfile;
    double rate;
    cout << "\nВведите имя файла отчета: ";
    reportfile = getFilename(cin, ".txt");
    cout << "Введите оплату за час: ";
    rate = getDoubleValue(cin);

    startReporter(binfile, reportfile, rate);
    printReport(reportfile);

    system("pause");
    return 0;
}
