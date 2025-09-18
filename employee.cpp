#include "employee.h"

std::istream& operator>>(std::istream& in, employee& emp)
{
    std::cout << "������� ������ ����������" << std::endl;
    std::cout << "�����: ";
    in >> emp.num;

    std::cout << "���: ";
    in >> emp.name;

    std::cout << "���-�� ������������ �����: ";
    in >> emp.hours;

    return in;
}

std::ostream& operator<<(std::ostream& out, const employee& emp)
{
    out << "���: " << emp.name << std::endl;
    out << "�����: " << emp.num << std::endl;
    out << "���-�� ������������ �����: " << emp.hours << std::endl;

    return out;
}
