#include <iostream>
#include <string>
#include <sstream>
#include <locale>

// Задание 1.1
int helloWorld()
{
    std::cout << "Hello World!\n";
    return 0;
}

//Задание 1.2
#include <iostream>
#include <string>
#include <sstream>

int calculate()
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

    switch (operation)
    {
    case '+':
        result = to_string(num1 + num2);
        break;
    case '-':
        result = to_string(num1 - num2);
        break;
    case '*':
        result = to_string(num1 * num2);
        break;
    case '/':
        if (num2 != 0)
            result = to_string(num1 / num2);
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

//Задание 1.3
#include <iostream>
#include <string>
#include <sstream>
#include <locale>

int cycle() {
    using namespace std;
    setlocale(LC_ALL, "");

    int n, sum = 0;
    char choice;

    cout << "Enter the number:\n";
    cin >> n;
    cout << "Chose the cycle: for(1), while(2), do-while(3): " << endl;
    std::cin >> choice;

    int i = 1;

    switch (choice)
    {
    case '1':
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        break;

    case '2':
        while (i <= n) {
            sum += i;
            i++;
        }
        break;

    case '3':
        i = 1;
        do {
            sum += i;
            i++;
        } while (i <= n);
        break;

    default:
        cout << "You entered an invalid character" << endl;
        return 0;
    }

    cout << "Result: " << sum << endl;
    return 0;
}



int main() {
    // helloWorld();
    // calculate();
    cycle();
    return 0;
}
