#pragma once
#include <string>

class Salary {
public:
    // Конструкторы
    Salary();
    Salary(const std::string& name, double salary, int bonus);
    Salary(const Salary& other);

    // Деструктор
    ~Salary();

    // Селекторы и модификаторы
    void setName(const std::string& name);
    void setSalary(double salary);
    void setBonus(int bonus);
    std::string getName() const;
    double getSalary() const;
    int getBonus() const;

private:
    std::string m_name;
    double m_salary;
    int m_bonus;
};