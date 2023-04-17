#include <iostream>
#include "Person.h"

class Student : public Person {
private:
    std::string subject;
    int grade;

public:
    Student(std::string n, int a, std::string s, int g);

    void setSubject(std::string s);
    void setGrade(int g);
    std::string getSubject();
    int getGrade();
    void checkGrade();
};

Student::Student(std::string n, int a, std::string s, int g) : Person(n, a) {
    subject = s;
    grade = g;
}

void Student::setSubject(std::string s) {
    subject = s;
}

void Student::setGrade(int g) {
    grade = g;
}

std::string Student::getSubject() {
    return subject;
}

int Student::getGrade() {
    return grade;
}

void Student::checkGrade() {
    if (grade < 4) {
        std::cout << "The grade of " << name << " in " << subject << " is unsatisfactory." << std::endl;
    }
    else {
        std::cout << "The grade of " << name << " in " << subject << " is satisfactory." << std::endl;
    }
}

int main() {
    Student student("Alice", 20, "Math", 3);

    std::cout << "Name: " << student.getName() << std::endl;
    std::cout << "Age: " << student.getAge() << std::endl;
    std::cout << "Subject: " << student.getSubject() << std::endl;
    std::cout << "Grade: " << student.getGrade() << std::endl;

    student.checkGrade();

    student.setGrade(5);

    student.checkGrade();

    return 0;
}