










// Задание 3.1

//#include <iostream>
//
//class Calculator {
//public:
//  static int add(int a, int b) {
//    return a + b;
//  }
//
//  static double add(double a, double b) {
//    return a + b;
//  }
//
//  static int subtract(int a, int b) {
//    return a - b;
//  }
//
//  static double subtract(double a, double b) {
//    return a - b;
//  }
//  static int multiply(int a, int b) {
//    return a * b;
//  }
//
//  static double multiply(double a, double b) {
//    return a * b;
//  }
//  static double divide(int a, int b) {
//    if (b == 0) {
//      throw "Error: devision by zero";
//    }
//    else {
//      return a / b;
//    }
//  }
//
//  static double divide(double a, double b) {
//    if (b == 0) {
//      throw "Error: devision by zero";
//    }
//    else {
//      return a / b;
//    }
//  }
//};
//
//int main() {
//  using namespace std;
//
//  int frstNum, scndNum, result;
//  char operation;
//
//  cout << "Enter first number: ";
//  cin >> frstNum;
//  cout << "\nEnter second number: ";
//  cin >> scndNum;
//  cout << "Enter the operator: ";
//  cin >> operation;
//
//  switch (operation)
//  {
//  case '+':
//    cout << frstNum << " + " << scndNum << " = " << Calculator::add(frstNum, scndNum) << endl;
//    break;
//
//  case '-':
//    cout << frstNum << " + " << scndNum << " = " << Calculator::subtract(frstNum, scndNum) << endl;
//    break;
//
//  case '*':
//    cout << frstNum << " + " << scndNum << " = " << Calculator::multiply(frstNum, scndNum) << endl;
//    break;
//
//  case '/':
//    cout << frstNum << " + " << scndNum << " = " << Calculator::divide(frstNum, scndNum) << endl;
//    break;
//
//  default:
//    cout << "Error: unexpected operator";
//  }
//
//  return 0;
//}
// Задание 4.1


//#include <iostream>
//#include <string>
//#include <sstream>
//
//class Book {
//public:
//    std::string bookName;
//    std::string author;
//    std::string year;
//    std::string status;
//
//    // Конструктор по умолчанию
//    Book() : bookName("Unknown"), author("Unknown"), year("Unknown"), status("Unknown") {}
//
//    // Параметризованный конструктор
//    Book(const std::string& bookName, const std::string& author, const std::string& year, const std::string& status)
//        : bookName(bookName), author(author), year(year), status(status) {
//    }
//
//    // Копирующий конструктор
//    Book(const Book& other)
//        : bookName(other.bookName), author(other.author), year(other.year), status(other.status) {
//    }
//
//    // Деструктор
//    ~Book() {
//        std::cout << bookName << " was deleted!" << std::endl;
//    }
//};
//
//std::string replace(std::string text) {
//    if (!text.empty() && text.front() == ' ') {
//        text.erase(0, 1);
//        if (text.length() == 0 || (text.length() == 1) && text[0] == ' ') {
//            return "Unknown";
//        }
//    }
//
//    return text;
//}
//
//int main() {
//    using namespace std;
//    char addNewBook;
//    cout << "Do you want to add a new book? (y/n): ";
//    cin >> addNewBook;
//    cin.ignore();
//
//    if (addNewBook == 'y') {
//        string allBookInfo;
//
//        cout << "Please, enter book details in format: book name, author, year, status\n";
//        getline(cin, allBookInfo);
//
//        stringstream ss(allBookInfo);
//        string bookName, author, year, status;
//
//        getline(ss, bookName, ',');
//        getline(ss, author, ',');
//        getline(ss, year, ',');
//        getline(ss, status, ',');
//
//        Book book(replace(bookName), replace(author), replace(year), replace(status)); //
//
//        cout << "\nNew book added:\n";
//        cout << "Book Name: " << book.bookName << "\nAuthor: " << book.author
//            << "\nYear: " << book.year << "\nStatus: " << book.status << endl;
//    }
//    else {
//        cout << "No new book added.\n";
//    }
//
//    return 0;
//}

// 5.1

//#include <iostream>
//#include <string>
//
//class Animal {
//protected:
//  std::string name;
//  int age;
//public:
//  Animal(std::string name, int age) : name(name), age(age) {};
//
//  int makeSaund() {
//    std::cout << "Animal makes a sound.\n";
//    return 0;
//  }
//
//  virtual ~Animal() {}
//};
//
//class Dog : public Animal {
//public:
//  Dog(std::string name, int age) : Animal(name, age) {};
//  int makeSaund() {
//    std::cout << "Dog barks.\n";
//    return 0;
//  }
//
//  ~Dog() override {}
//};
//
//class Cat : public Animal {
//public:
//  Cat(std::string name, int age) : Animal(name, age) {};
//  int makeSaund() {
//    std::cout << "Cat meows.\n";
//    return 0;
//  }
//
//  ~Cat() override{}
//
//};
//int main() {
//  Cat frstCat("Barsik", 3);
//  Dog frstDog("Borbos", 4);
//
//  frstCat.makeSaund();
//  frstDog.makeSaund();
//
//  return 0;
//}

// Задание 6.1


//#include <iostream>
//#include <cmath>  // Для pow()
//using namespace std;
//
//class Polynomial {
//private:
//    int degree;        // Степень полинома
//    double* coeffs;    // Динамический массив коэффициентов
//
//public:
//    // Конструктор
//    Polynomial(int deg) : degree(deg) {
//        coeffs = new double[degree + 1]();  // Выделение памяти и инициализация 0
//    }
//
//    // Деструктор
//    ~Polynomial() {
//        delete[] coeffs;  // Освобождение памяти
//    }
//
//    // Ввод коэффициентов полинома
//    void inputCoefficients() {
//        cout << "Введите коэффициенты от старшего (x^" << degree << ") до младшего (x^0):\n";
//        for (int i = 0; i <= degree; i++) {
//            cout << "Коэффициент при x^" << (degree - i) << ": ";
//            cin >> coeffs[i];
//        }
//    }
//
//    // Вывод полинома
//    void display() const {
//        for (int i = 0; i <= degree; i++) {
//            if (coeffs[i] != 0) {
//                cout << coeffs[i] << "x^" << (degree - i);
//                if (i < degree) cout << " + ";
//            }
//        }
//        cout << endl;
//    }
//
//    // Перегрузка оператора + для сложения двух полиномов
//    Polynomial operator+(const Polynomial& other) const {
//        int maxDegree = max(degree, other.degree);  // Находим максимальную степень
//        Polynomial result(maxDegree);  // Создаем новый полином
//
//        // Копируем коэффициенты из текущего полинома
//        for (int i = 0; i <= degree; i++) {
//            result.coeffs[maxDegree - degree + i] = coeffs[i];
//        }
//
//        // Складываем коэффициенты из второго полинома
//        for (int i = 0; i <= other.degree; i++) {
//            result.coeffs[maxDegree - other.degree + i] += other.coeffs[i];
//        }
//
//        return result;
//    }
//
//    // Вычисление значения полинома при заданном x
//    double evaluate(double x) const {
//        double result = 0;
//        for (int i = 0; i <= degree; i++) {
//            result += coeffs[i] * pow(x, degree - i);  // Считаем x^степень
//        }
//        return result;
//    }
//};
//
//// Главная функция
//int main() {
//    int degree1, degree2;
//
//    cout << "Введите степень первого полинома: ";
//    cin >> degree1;
//    Polynomial poly1(degree1);
//    poly1.inputCoefficients();
//
//    cout << "Введите степень второго полинома: ";
//    cin >> degree2;
//    Polynomial poly2(degree2);
//    poly2.inputCoefficients();
//
//    cout << "\nПервый полином: ";
//    poly1.display();
//    cout << "Второй полином: ";
//    poly2.display();
//
//    // Сложение полиномов
//    Polynomial sum = poly1 + poly2;
//    cout << "Сумма полиномов: ";
//    sum.display();
//
//    // Вычисление значения полинома
//    double x;
//    cout << "\nВведите x для вычисления P(x): ";
//    cin >> x;
//    cout << "P(x) = " << poly1.evaluate(x) << endl;
//
//    return 0;
//}
