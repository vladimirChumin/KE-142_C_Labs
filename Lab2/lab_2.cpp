#include <iostream>
#include <string>
#include <cmath>

int addNumbers(int a, int b) {
  int result;
  result = a + b;
  return result;

}
int minusNumbers(int a, int b) {
  int result;
  result = a - b;
  return result;
}

double deliNumbers(double a, double b) {
  double result;
  result = a / b;
  return result;
}

int multiplyNumbers(int a, int b) {
  int result;
  result = a * b;
  return result;
}

int main()
{
    using namespace std;
    char operation;
    double num1, num2;
    string result;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    cout << "Your numbers are " << num1 << " and " << num2 << endl;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
    case '+':
        result = to_string(addNumbers(num1, num2));
        break;
    case '-':
        result = to_string(minusNumbers(num1, num2));
        break;
    case '*':
        result = to_string(multiplyNumbers(num1, num2));
        break;
    case '/':
        if (num2 != 0) {
            result = to_string(deliNumbers(num1, num2));
        }
        else {
            result = "Error: Division by zero";
        }
        break;
    default:
            result = "Error";
        return 1;
    }

    cout << "Your result is: " << result << endl;
    return 0;
}

 // Задание 2.1
bool isPrime(int num) {
  if (num <= 1) return false;
  for (int i = 2; i <= sqrt(num); ++i) {
    if (num % i == 0) return false;
  }
  return true;
}

int printMultiplicationTable(int num) {
  for (int i = 1; i <= 9; i++) {
    std::cout << num * i << std::endl;
  }
  return 0;
}

int main() {
  using namespace std;

  for (int i = 1; i <= 5; i++) {
    int num;

    cout << "Enter " << i << " number" << endl;
    cin >> num;
    if (isPrime(num)) {
      cout << "It's prime number\n";
    }
    else {
      cout << "It's not prime number\n";
    }
    printMultiplicationTable(num);
  }
}

 // Задание 2.2
using namespace std;
int power(int base, int exponent) {
  if (exponent == 0) return 1;
  return base * power(base, exponent - 1);
}
double power(double base, int exponent) {
  if (exponent == 0) return 1.0;
  return base * power(base, exponent - 1);
}

int main() {
  int intBase, exponent;
  double doubleBase;
  char baseType;
  cout << "Введите 'i' для целочисленного основания или 'd' для основания с плавающей запятой: ";
  cin >> baseType;
  cout << "Введите показатель степени (неотрицательное целое число): ";
  cin >> exponent;
  if (exponent < 0) {
    cout << "Показатель степени должен быть неотрицательным." << endl;
    return 1;
  }
  if (baseType == 'i') {
    cout << "Введите целочисленное основание: ";
    cin >> intBase;
    cout << "Результат: " << power(intBase, exponent) << endl;
  }
  else if (baseType == 'd') {
    cout << "Введите основание с плавающей запятой: ";
    cin >> doubleBase;
    cout << "Результат: " << power(doubleBase, exponent) << endl;
  }
  else {
    cout << "Неверный тип основания." << endl;
  }
  return 0;
}
