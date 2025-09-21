#include "FATAL.h"

void FATAL::PrintMessage(std::string mes, bool await)
{
    std::cout << mes << std::endl;
    if (await)
        system("pause");
    exit(-1);
}