#include "Salary.h"

// Конструктор без параметров
Salary::Salary() : m_salary(0), m_bonus(0) {}

// Конструктор с параметрами
Salary::Salary(const std::string& name, double salary, int bonus)
    : m_name(name), m_salary(salary), m_bonus(bonus) {}

// Конструктор копирования
Salary::Salary(const Salary& other)
    : m_name(other.m_name), m_salary(other.m_salary), m_bonus(other.m_bonus) {}

// Деструктор
Salary::~Salary() {}

// Селекторы и модификаторы
void Salary::setName(const std::string& name) {
    m_name = name;
}

void Salary::setSalary(double salary) {
    m_salary = salary;
}

void Salary::setBonus(int bonus) {
    m_bonus = bonus;
}

std::string Salary::getName() const {
    return m_name;
}

double Salary::getSalary() const {
    return m_salary;
}

int Salary::getBonus() const {
    return m_bonus;
}
