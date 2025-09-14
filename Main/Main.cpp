#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "employee.h"
#pragma warning (disable:4996)

using namespace std;

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

    char lpszCommandLine[] = "Creator.exe ";
    strcat(lpszCommandLine, binfile.c_str());
    strcat(lpszCommandLine, to_string(count).c_str());
    STARTUPINFO si = { sizeof(si) };    
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    if (!CreateProcess(NULL, NULL,
        NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    {
        cout << "Error: cannot start Creator" << endl;
        _getch();
        return 0;
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    string reportfile;
    double rate;
    cout << "\nВведите имя файла отчета: ";
    cin >> reportfile;
    cout << "Введите оплату за час: ";
    cin >> rate;

    // Запуск Reporter
    string cmdReporter = "Reporter.exe " + binfile + " " + reportfile + " " + to_string(rate);
    if (!CreateProcess(NULL, NULL,
        NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    {
        cout << "Error: cannot start Reporter" << endl;
        _getch();
        return 0;
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
