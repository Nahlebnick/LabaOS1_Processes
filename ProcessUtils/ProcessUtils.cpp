#include "ProcessUtils.h"
#include "../FATAL.h"
#pragma warning (disable:4996)

void StartProcess(const std::string commandLine, const std::string errorMessage)
{
    wchar_t* wtext = new wchar_t[commandLine.size() + 1];

    mbstowcs(wtext, commandLine.c_str(), commandLine.length());
    LPWSTR lpszCommandLine = wtext;

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    if (!CreateProcess(NULL, lpszCommandLine,
        NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    {
        delete[] wtext;
        FATAL(errorMessage);
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    delete[] wtext;
}
