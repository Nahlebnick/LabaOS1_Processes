#include "FATAL.h"

void FATAL(std::string mes, bool await)
{
    std::cerr << mes << std::endl;
    if (await)
        system("pause");
    exit(-1);
}