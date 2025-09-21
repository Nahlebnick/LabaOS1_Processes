#include "employee.h"
#include "InputUtils/InputUtils.h"

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

void employee::showAsString(std::ostream& out)
{
    out << std::fixed << std::setprecision(2);
    out << std::left << std::setw(10) << num
        << std::left << std::setw(10) << name
        << std::left << std::setw(10) << hours;
}
