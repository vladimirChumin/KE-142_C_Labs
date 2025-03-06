#include "miniFunctions.h"

#include <cmath>
#include <cstdlib>  // Для rand()
#include <iostream>

// === Определение статических векторов ===
const vector<miniFunctions::IntFunction> miniFunctions::intFunctions = {
    {"Увеличить числа на 1", [](int x) { return x + 1; }},
    {"Удвоить числа", [](int x) { return x * 2; }},
    {"Превратить все числа в единицу", [](int x) {return 1;}},
    {"Вычесть 3", [](int x) { return x - 3; }},
    {"Изменить знак всех чисел", [] (int x) {return x * -1;}}
};

const vector<miniFunctions::StringFunction> miniFunctions::stringFunctions = {
    {"Добавить восклицательный знак", [](string s) { return s + "!"; }},
    {"Добавить 'Hello, ' перед строкой", [](string s) { return "Hello, " + s; }},
    {"Обрезать строку до половины", [](string s) { return s.substr(0, s.size() / 2); }},
    {"Инвертировать строку", {[](string s) { if (!s.empty()) reverse(s.begin(), s.end()); return s; }}},
    {"Поменять первую символ на верхний регистр", [](string s) { if (!s.empty()) transform(s.begin(), s.begin() + 1, s.begin(), ::toupper()); return s; }}
};


const vector<miniFunctions::DoubleFunction> miniFunctions::doubleFunctions = {
    {"Разделить на 2", [](double d) { return d / 2.0; }},
    {"Умножить на 1.1", [](double d) { return d * 1.1; }},
    {"Вычесть 3.14", [](double d) { return d - 3.14; }},
    {"Вернуть модуль числа", [] (double d) {return abs(d);}},
    {"Вернуть корень чисел", [] (double d) {return ::sqrt(d);}}
};

// === Методы выбора случайной функции ===
function<int(int)> miniFunctions::getRandomIntFunction() {
    int randIndex = rand() % intFunctions.size();
    cout << intFunctions[randIndex].description;
    return intFunctions[randIndex].func;
}

function<string(string)> miniFunctions::getRandomStringFunction() {
    int randIndex = rand() % stringFunctions.size();
    cout << stringFunctions[randIndex].description;
    return stringFunctions[randIndex].func;
}

function<double(double)> miniFunctions::getRandomDoubleFunction() {
    int randIndex = rand() % doubleFunctions.size();
    cout << doubleFunctions[randIndex].description;
    return doubleFunctions[randIndex].func;
}
