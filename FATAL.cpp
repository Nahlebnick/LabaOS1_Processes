#include "FATAL.h"

void FATAL::PrintMessage(string mes, bool await = 1)
{
    cout << mes << endl;
    if (await)
        system("pause");
    exit(-1);
}