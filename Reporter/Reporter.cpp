// Reporter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "employee.h"
#pragma warning (disable:4996)

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        std::cout << "Usage: Reporter <binfile> <reportfile> <hourly_wage>" << std::endl;
        return 0;
    }

    FILE* f;
    f = fopen(argv[1], "rb");

    if (!f)
    {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return 0;
    }

    std::string reportFileName = argv[2];

    double hourlyWage = std::stod(argv[3]);

    freopen(reportFileName.c_str(), "w", stdout);

    cout << "Отчет по файлу \"" << argv[1] << "\"" << endl;
    cout << "Номер\tИмя\tЧасы\tЗарплата" << endl;

    employee emp;
    while (fread(&emp, sizeof(struct employee), 1, f))
    {
        double salary = hourlyWage * emp.hours;
        cout << fixed << setprecision(2);
        cout << emp.num << "\t" << emp.name << "\t" << emp.hours << "\t" << salary << endl;
    }
    fclose(f);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
