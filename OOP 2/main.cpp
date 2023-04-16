#include <iostream>
#include "Salary.h"

int main() {
    setlocale(0, "Rus");
    // Создание объекта с помощью конструктора без параметров
    Salary employee1;
    employee1.setName("Ivanov Ivan Ivanovich");
    employee1.setSalary(1000);
    employee1.setBonus(10);

    // Создание объекта с помощью конструктора с параметрами
    Salary employee2("Petrov Petr Petrovich", 2000, 20);

    // Создание объекта с помощью конструктора копирования
    Salary employee3(employee1);

    // Вывод информации о сотрудниках
    std::cout << "Работник 1:\n Имя: " << employee1.getName() << "\n Зарплата: " << employee1.getSalary() << "\n Премия: " << employee1.getBonus() << std::endl;
    std::cout << "Работник 2:\n Имя: " << employee2.getName() << "\n Зарплата: " << employee2.getSalary() << "\n Премия: " << employee2.getBonus() << std::endl;
    std::cout << "Работник 3:\n Имя: " << employee3.getName() << "\n Зарплата: " << employee3.getSalary() << "\n Премия: " << employee3.getBonus() << std::endl;

    return 0;
}