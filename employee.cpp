#include "employee.h"
#include "InputUtils/InputUtils.h"
#pragma warning (disable:4996);

std::istream& operator>>(std::istream& in, employee& emp)
{
    std::cout << "������� ������ ����������" << std::endl;
    std::cout << "�����: ";
    emp.num = getIntValue(in);

    std::cout << "���: ";
    in >> emp.name;

    std::cout << "���-�� ������������ �����: ";
    emp.hours = getDoubleValue(in);

    return in;
}

std::ostream& operator<<(std::ostream& out, const employee& emp)
{
    out << "���: " << emp.name << std::endl;
    out << "�����: " << emp.num << std::endl;
    out << "���-�� ������������ �����: " << emp.hours << std::endl;

    return out;
}

bool operator<(const employee& emp1, const employee& emp2)
{
    return emp1.num < emp2.num;
}

bool operator>(const employee& emp1, const employee& emp2)
{
    return emp1.num > emp2.num;
}
