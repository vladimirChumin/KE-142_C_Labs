#include "DataProcessors.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include "DataHandler.h"

IntDataHandler::IntDataHandler(const string& filePath, function<int(int)> func)
    : DataHandler(filePath), func(func) {}

void IntDataHandler::useFunction() {
    for (string& elem : data) {
        try {
            int curElem = stoi(elem);
            curElem = func(curElem);
            elem = to_string(curElem);
        } catch (const invalid_argument&) {
            cerr << "Ошибка: невозможно преобразовать '" << elem << "' в int!" << endl;
        } catch (const out_of_range&) {
            cerr << "Ошибка: число '" << elem << "' выходит за границы int!" << endl;
        }
    }
}

// === Реализация StringDataHandler ===
StringDataHandler::StringDataHandler(const string& filePath, function<string(string)> func)
    : DataHandler(filePath), func(func) {}

void StringDataHandler::useFunction() {
    for (string& elem : data) {
        elem = func(elem);
    }
}

// === Реализация DoubleDataHandler ===
DoubleDataHandler::DoubleDataHandler(const string& filePath, function<double(double)> func)
    : DataHandler(filePath), func(func) {}

void DoubleDataHandler::useFunction() {
    for (string& elem : data) {
        try {
            double cur_elem = stod(elem);
            cur_elem = func(cur_elem);
            // округлим до 2 знаков
            elem = to_string(cur_elem).substr(0, to_string(cur_elem).find('.') + 3);
        } catch (const invalid_argument&) {
            cerr << "Ошибка: невозможно преобразовать '" << elem << "' в double!" << endl;
        } catch (const out_of_range&) {
            cerr << "Ошибка: число '" << elem << "' выходит за границы double!" << endl;
        }
    }
}