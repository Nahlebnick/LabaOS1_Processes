#include "employee.h"
#include "InputUtils/InputUtils.h"
#pragma warning (disable:4996);

std::istream& operator>>(std::istream& in, employee& emp)
{
    std::cout << "Введите данные сотрудника" << std::endl;
    std::cout << "Номер: ";
    emp.num = getIntValue(in);

    std::cout << "Имя: ";
    in >> emp.name;

    std::cout << "Кол-во отработанных часов: ";
    emp.hours = getDoubleValue(in);

    return in;
}

std::ostream& operator<<(std::ostream& out, const employee& emp)
{
    out << "Имя: " << emp.name << std::endl;
    out << "Номер: " << emp.num << std::endl;
    out << "Кол-во отработанных часов: " << emp.hours << std::endl;

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
