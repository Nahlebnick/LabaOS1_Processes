#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "employee.h"
#pragma warning (disable:4996)

using namespace std;

void FATAL(string mes, bool await = 1)
{
    cout << mes << endl;
    if (await)
        system("pause");
    exit(-1);
}

void printFile(string filename)
{
    cout << "Файл " + filename << endl;
    FILE* f;
    f = fopen(filename.c_str(), "rb");
    employee emp;
    while (fread(&emp, sizeof(struct employee), 1, f))
    {
        cout << "Имя: " << emp.name << endl;
        cout << "Номер: " << emp.num << endl;
        cout << "Кол-во отработанных часов: " << emp.hours << endl;
    }
    fclose(f);
}

void printReport(string filename)
{
    
}

int main()
{
    setlocale(LC_ALL, "rus");
    string binfile;
    int count;
    cout << "Введите имя бинарного файла: ";
    cin >> binfile;
    cout << "Введите количество записей: ";
    cin >> count;
    binfile += " ";

    string commandLine = "Creator.exe " + binfile + " " + to_string(count);
    wchar_t* wtext = new wchar_t[commandLine.size()+1];

    mbstowcs(wtext, commandLine.c_str(), commandLine.length());
    LPWSTR lpszCommandLine = wtext;

    STARTUPINFO si = { sizeof(si) };    
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    if (!CreateProcess(NULL, lpszCommandLine,
        NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    {
        FATAL("Error: cannot start Creator");
        return 0;
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    delete[] wtext;

    printFile(binfile);

    string reportfile;
    double rate;
    cout << "\nВведите имя файла отчета: ";
    cin >> reportfile;
    cout << "Введите оплату за час: ";
    cin >> rate;

    // Запуск Reporter
    string cmdReporter = "Reporter.exe " + binfile + " " + reportfile + " " + to_string(rate);
    wtext = new wchar_t[cmdReporter.size()+1];
    mbstowcs(wtext, cmdReporter.c_str(), cmdReporter.length());
    lpszCommandLine = wtext;

    if (!CreateProcess(NULL, lpszCommandLine,
        NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    {
        FATAL("Error: cannot start Reporter");
        return 0;
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    printReport(reportfile);

    delete[] wtext;

    return 0;
}
