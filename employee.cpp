#include "employee.h"

std::istream& operator>>(std::istream& in, employee& emp)
{
    std::cout << "Введите данные сотрудника" << std::endl;
    std::cout << "Номер: ";
    in >> emp.num;

    std::cout << "Имя: ";
    in >> emp.name;

    std::cout << "Кол-во отработанных часов: ";
    in >> emp.hours;

    return in;
}

std::ostream& operator<<(std::ostream& out, const employee& emp)
{
    out << "Имя: " << emp.name << std::endl;
    out << "Номер: " << emp.num << std::endl;
    out << "Кол-во отработанных часов: " << emp.hours << std::endl;

    return out;
}
