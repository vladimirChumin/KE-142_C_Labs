#include <iostream>
#include <vector>
#include "locale.h"
void firstExample() {
setlocale(LC_ALL, "Russian");
// Создание вектора для хранения целых чисел
std::vector<int> numbers;
// Добавление элементов в вектор
numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
// Доступ к элементам с использованием оператора []
std::cout << "Элемент с индексом 1: " << numbers[1] << std::endl;
// Итерация по вектору с использованием цикла range-based for
std::cout << "Содержимое вектора: ";
for (int num : numbers) {
std::cout << num << " ";
}
std::cout << std::endl;
}


#include <iostream>
#include <list>
#include "locale.h"
void secondExample() {
setlocale(LC_ALL, "Russian");
// Создание списка для хранения целых чисел
std::list<int> numbers;
// Добавление элементов в список
numbers.push_back(10); // Добавление в конец списка
numbers.push_back(20);
numbers.push_front(5); // Добавление в начало списка
// Итерация по списку с использованием итератора для доступа к элементам
std::cout << "Содержимое списка: ";
for (auto it = numbers.begin(); it != numbers.end(); ++it) {
std::cout << *it << " ";
}
std::cout << std::endl;
// Удаление элемента из списка
numbers.remove(20); // Удаление всех вхождений элемента со значением 20
// Повторная итерация по списку для вывода его содержимого после удаления элемента
std::cout << "Содержимое списка после удаления элемента: ";
for (int num : numbers) {
std::cout << num << " ";
}
std::cout << std::endl;
}


#include <iostream>
#include <map>
#include <string>
#include "locale.h"


void thirdExample() {
setlocale(LC_ALL, "Russian");
// Создание карты, где ключ - строка, а значение - int
std::map<std::string, int> ageMap;
// Добавление пар ключ-значение в карту
ageMap["Иван"] = 25;
ageMap["Елена"] = 30;
ageMap["Алексей"] = 28;
// Поиск элемента в карте по ключу и вывод его значения
std::string name = "Елена";
if (ageMap.find(name) != ageMap.end()) {
std::cout << "Возраст " << name << ": " << ageMap[name] << std::endl;
}
else {
std::cout << name << " не найден в карте." << std::endl;
}
// Итерация по карте и вывод всех пар ключ-значение
std::cout << "Весь список возрастов:" << std::endl;
for (const auto& pair : ageMap) {
std::cout << pair.first << ": " << pair.second << std::endl;
}
}

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include "locale.h"
class Employee {
public:
int id;
std::string name;
std::string department;
Employee(int id, std::string name, std::string department) : id(id), name(name), department(department) {}
virtual void display() {
std::cout << "ID: " << id << ", Name: " << name << ", Department: " << department << std::endl;
}
};

class FullTimeEmployee : public Employee {
public:
double salary;
FullTimeEmployee(int id, std::string name, std::string department, double salary)
: Employee(id, name, department), salary(salary) {}
void display() override {
Employee::display();
std::cout << "Salary: " << salary << std::endl;
}
};
class PartTimeEmployee : public Employee {
public:
double hourlyRate;
PartTimeEmployee(int id, std::string name, std::string department, double hourlyRate)
: Employee(id, name, department), hourlyRate(hourlyRate) {}
void display() override {
Employee::display();
std::cout << "Hourly Rate: " << hourlyRate << std::endl;
}
};


void fourthExample () {
setlocale(LC_ALL, "Russian");
std::vector<Employee*> employees;
std::list<std::string> departments;
std::map<std::string, std::vector<Employee*>> departmentEmployees;
// Добавление сотрудников и отделов в контейнеры
employees.push_back(new FullTimeEmployee(1, "Иван Иванов", "Разработка", 50000));
employees.push_back(new PartTimeEmployee(2, "Петр Петров", "Маркетинг", 300));
departments.push_back("Разработка");
departments.push_back("Маркетинг");
for (auto& emp : employees) {
departmentEmployees[emp->department].push_back(emp);
}
// Вывод информации о сотрудниках
for (auto& emp : employees) {
emp->display();
}
// Очистка динамически выделенной памяти
for (auto& emp : employees) {
delete emp;
}
}



#include <iostream>
#include <map>
#include <string>
#include "locale.h"
class Product {
public:
    int productID;
    std::string productName;
    double price;
    Product(int productID, std::string productName, double price)
    : productID(productID), productName(productName), price(price) {}
    virtual void display() {
        std::cout << "Product ID: " << productID << ", Name: " << productName << ", Price: " << price <<
        std::endl;
    }
};


class Electronics : public Product {

public:
    Electronics(int productID, std::string productName, double price)
    : Product(productID, productName, price) {}
    void display() override {
        Product::display();
        std::cout << "Category: Electronics" << std::endl;
    }
};
class Clothing : public Product {
public:
    Clothing(int productID, std::string productName, double price)
    : Product(productID, productName, price) {}
    void display() override {
        Product::display();
        std::cout << "Category: Clothing" << std::endl;
    }
};


void fifthExample() {
    setlocale(LC_ALL, "Russian");
    std::map<int, std::pair<Product*, int>> inventory;
    // Добавление продуктов в инвентарь
    inventory[1] = std::make_pair(new Electronics(1, "Smartphone", 500.0), 10);
    inventory[2] = std::make_pair(new Clothing(2, "T-Shirt", 20.0), 50);
    // Вывод инвентаря
    for (const auto& item : inventory) {
        std::cout << "Stock: " << item.second.second << " ";
        item.second.first->display();
    }
    // Очистка памяти
    for (auto& item : inventory) {
        delete item.second.first;
    }
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "locale.h"
class Employee2 {
public:
int id;
std::string name;
std::string department;
Employee2() : id(0) {} // Для десериализации
Employee2(int id, std::string name, std::string department)
: id(id), name(name), department(department) {}
// Сериализация данных сотрудника в строку
std::string serialize() const {
return std::to_string(id) + ";" + name + ";" + department;
}
// Десериализация строки в данные сотрудника
void deserialize(const std::string& data) {
size_t pos1 = data.find(';');
size_t pos2 = data.find(';', pos1 + 1);
id = std::stoi(data.substr(0, pos1));
name = data.substr(pos1 + 1, pos2 - pos1 - 1);
department = data.substr(pos2 + 1);
}
};

void writeEmployeesToFile(const std::vector<Employee2>& employees, const std::string& filename) {
std::ofstream fileOut(filename);
for (const auto& employee : employees) {
fileOut << employee.serialize() << std::endl;
}
fileOut.close();
}
void readEmployeesFromFile(std::vector<Employee2>& employees, const std::string& filename) {
std::ifstream fileIn(filename);
std::string line;
while (std::getline(fileIn, line)) {
Employee2 emp;
emp.deserialize(line);
employees.push_back(emp);
}
fileIn.close();
}

void sixthExample() {
setlocale(LC_ALL, "Russian");
std::vector<Employee2> employees;
employees.push_back(Employee2(1, "Иван Иванов", "Разработка"));
employees.push_back(Employee2(2, "Петр Петров", "Маркетинг"));
// Запись в файл
writeEmployeesToFile(employees, "employees.txt");
// Чтение из файла
std::vector<Employee2> loadedEmployees;
readEmployeesFromFile(loadedEmployees, "employees.txt");
// Вывод сотрудников, загруженных из файла
for (const auto& employee : loadedEmployees) {
std::cout << employee.id << " " << employee.name << " " << employee.department << std::endl;
}
}

int main() {
firstExample();
secondExample();
thirdExample();
fourthExample();
fifthExample();
sixthExample();
return 0;
}
