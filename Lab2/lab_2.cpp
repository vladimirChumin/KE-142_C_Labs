#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double addNumbers(double a, double b) {
    return a + b;
}

double minusNumbers(double a, double b) {
    return a - b;
}

double multiplyNumbers(double a, double b) {
    return a * b;
}

double deliNumbers(double a, double b) {
    return a / b;
}

void calculate() {
    char operation;
    double num1, num2;
    string result;
    bool isProcess = true;

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
            } else {
                result = "Error: Division by zero";
            }
            break;
        default:
            result = "Error: Invalid operator";
            cout << "Result: " << result << endl;
            return;
    }
    cout << "Result: " << result << endl;
}

// ========== PART 2.1 (Prime check & Multiplication table) ==========

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void printMultiplicationTable(int num) {
    for (int i = 1; i <= 9; i++) {
        cout << num << " x " << i << " = " << (num * i) << endl;
    }
}

void task2_1() {
    for (int i = 1; i <= 5; i++) {
        int num;
        cout << "Enter number #" << i << ": ";
        cin >> num;

        if (isPrime(num)) {
            cout << "It's a prime number" << endl;
        } else {
            cout << "It's not a prime number" << endl;
        }
        printMultiplicationTable(num);
        cout << "----------------" << endl;
    }
}

// ========== PART 2.2 (Power with overload) ==========
int power(int base, int exponent) {
    if (exponent == 0) return 1;
    return base * power(base, exponent - 1);
}
double power(double base, int exponent) {
    if (exponent == 0) return 1.0;
    return base * power(base, exponent - 1);
}

int task2_2()
{
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

int main() {
    // // calculate();
    // task2_1();
    task2_2();

    return 0;
}
