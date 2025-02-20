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

void task2_2() {
    int exponent;
    char baseType;

    cout << "Enter 'i' for integer base or 'd' for floating-point base: ";
    cin >> baseType;

    cout << "Enter the exponent (non-negative integer): ";
    cin >> exponent;

    if (exponent < 0) {
        cout << "Exponent must be non-negative." << endl;
        return;
    }

    if (baseType == 'i') {
        int intBase;
        cout << "Enter the integer base: ";
        cin >> intBase;
        cout << "Result: " << power(intBase, exponent) << endl;
    }
    else if (baseType == 'd') {
        double doubleBase;
        cout << "Enter the floating-point base: ";
        cin >> doubleBase;
        cout << "Result: " << power(doubleBase, exponent) << endl;
    }
    else {
        cout << "Invalid base type." << endl;
    }
}

int main() {
    calculate();
    task2_1();
    task2_2();

    return 0;
}
