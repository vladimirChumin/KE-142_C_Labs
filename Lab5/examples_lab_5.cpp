#include <iostream>
#include <string>
using namespace std;
class Vehicle {
private:
    string make;
    int year;
public:
    Vehicle(string m, int y) : make(m), year(y) {}
    void setMake(string m) {
        make = m;
    }
    string getMake() const {
        return make;
    }
    void setYear(int y) {
        year = y;
    }
    int getYear() const {
        return year;
    }
    virtual void displayInfo() {
        cout << "Make: " << make << ", Year: " << year << endl;
    }
};
class Car : public Vehicle {
private:
    bool isSedan;
public:
    Car(string m, int y, bool isS) : Vehicle(m, y), isSedan(isS) {}
    void setIsSedan(bool isS) {
        isSedan = isS;
    }
    bool getIsSedan() const {
        return isSedan;
    }
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Is Sedan: " << (isSedan ? "Yes" : "No") << endl;
    }
};
class Motorcycle : public Vehicle {
private:
    bool hasSidecar;
public:
    Motorcycle(string m, int y, bool hasS) : Vehicle(m, y), hasSidecar(hasS) {}
    void setHasSidecar(bool hasS) {
        hasSidecar = hasS;
    }
    bool getHasSidecar() const {
    }
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Has Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
    }
};
int carExamples() {
    Car car1("Toyota", 2020, true);
    Motorcycle motorcycle1("Harley-Davidson", 2019, false);
    car1.displayInfo(); // Демонстрация информации о машине
    motorcycle1.displayInfo(); // Демонстрация информации о мотоцикле
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
class Person {
protected: // Защищенные члены класса
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
class Student : public Person {
protected: // Дополнительные защищенные члены специфичные для студента
    string studentID;
public:
    Student(string n, int a, string id) : Person(n, a), studentID(id) {}
    void display() {
        Person::display(); // Вызов метода display базового класса
        cout << "Student ID: " << studentID << endl;
    }
};
class Teacher : public Person {
protected: // Дополнительные защищенные члены специфичные для учителя
    string subject;
public:
    Teacher(string n, int a, string sub) : Person(n, a), subject(sub) {}
    void display() {
        Person::display(); // Вызов метода display базового класса
        cout << "Teaches: " << subject << endl;
    }
};
int studentExamples() {
    Student student1("Alice", 20, "S12345");
    Teacher teacher1("Bob", 45, "Mathematics");
    student1.display();
    cout << "----------------" << endl;
    teacher1.display();
    return 0;
}

int main () {
    carExamples();
    carExamples();
    return 0;
 }