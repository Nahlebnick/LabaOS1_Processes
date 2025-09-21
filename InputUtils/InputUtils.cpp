#include "InputUtils.h"

int getIntValue(std::istream& in)
{
    int value;
    while (true)
    {
        if (in >> value)
        {
            return value;
        }
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "������ ��� ����� Int. ���������� �����.\n";
    }
}

double getDoubleValue(std::istream& in)
{
    double value;
    while (true)
    {
        if (in >> value) return value;
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "������ ��� ����� Int. ���������� �����.\n";
    }
}
