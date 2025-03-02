#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <chrono>
#include <fstream>
#include <string>
#include <filesystem>
#include <algorithm>
#include <math.h>
#include <valarray>
using namespace std;

namespace fs = filesystem;


vector<string> getFilesInDirectory(const string& directoryPath) {
    vector<string> files;

    try {
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (fs::is_regular_file(entry.path())) { // Только файлы (без папок)
                files.push_back(entry.path().string()); // Сохраняем путь в виде строки
            }
        }
    } catch (const fs::filesystem_error& e) {
        cerr << "Ошибка при доступе к директории: " << e.what() << endl;
    }

    return files;
}
class DataHandler {
protected:
    string filePath;
    vector<string> data;

public:
    DataHandler(const string& filePath) : filePath(filePath) {
        deserialize();
    }

    ~DataHandler() {
        saveData();
    }

    virtual void useFunction() = 0;
    virtual void getRandFunction() = 0;
    void saveData() {
        string text = serialize();
        ofstream fileOut(filePath);
        if (fileOut.is_open()) {
            fileOut << text << endl;
            fileOut.close();
        }
    }

    string loadData() {
        ifstream fileIn(filePath);
        if (!fileIn.is_open()) {
            cerr << "Ошибка: файл не найден: " << filePath << endl;
            return "";
        }

        string line;
        getline(fileIn, line);
        fileIn.close();

        return line;
    }

    string serialize() {
        string result;
        for (const string& element : data) {
            result += element + "|";
        }
        if (!result.empty()) { // Проверка перед pop_back()
            result.pop_back();
        }
        return result;
    }

    void deserialize() {
        string line = loadData();
        if (line.empty()) return; // Если файл пуст, не продолжаем обработку

        size_t start = 0;
        size_t end = line.find('|');

        while (end != string::npos) {
            data.push_back(line.substr(start, end - start));
            start = end + 1;
            end = line.find('|', start);
        }
    }
};

class IntDataHandler : public DataHandler {
protected:
    function<int(int)> func;
public:
    IntDataHandler(const string& filePath, function<int(int)> func)
        : DataHandler(filePath), func(func) {}

    void useFunction() override {
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
};

class StringDataHandler : public DataHandler {
protected:
    function<string(string)> func;
public:
    StringDataHandler(const string& filePath, function<string(string)> func)
        : DataHandler(filePath), func(func) {}

    void useFunction() override {
        for (string& elem : data) {
            elem = func(elem);
        }
    }
};

class DoubleDataHandler : public DataHandler {
protected:
    function<double(double)> func;
public:
    DoubleDataHandler(const string& filePath, function<double(double)> func)
        : DataHandler(filePath), func(func) {}

    void useFunction() override {
        for (string& elem : data) {
            try {
                double cur_elem = stod(elem);
                cur_elem = func(cur_elem);
                elem = to_string(cur_elem).substr(0, to_string(cur_elem).find('.') + 3); // Округление до 2 знаков
            } catch (const invalid_argument&) {
                cerr << "Ошибка: невозможно преобразовать '" << elem << "' в double!" << endl;
            } catch (const out_of_range&) {
                cerr << "Ошибка: число '" << elem << "' выходит за границы double!" << endl;
            }
        }
    }
};


class miniFunctions {
protected:
    struct StringFunction {
        function<string(string)> func;
        string description;
    };
    struct IntFunction {
        function<int(int)> func;
        string description;
    };
    struct DoubleFunction {
        function<double(double)> func;
        string description;
    };

    vector<StringFunction> stringFunctions;
    vector<IntFunction> intFunctions;
    vector<DoubleFunction> doubleFunctions;

public:
    miniFunctions() {
        stringFunctions = {
            {[](string s) { return s + "!"; }, "Добавляет в конец строки '!'" },
            {[](string s) { return s + to_string(rand() % 10); }, "Добавляет случайное число от 0 до 9 в конец строки" },
            {[](string s) { transform(s.begin(), s.end(), s.begin(), ::tolower); return s; }, "Переводит всю строку в нижний регистр" },
            {[](string s) { if (!s.empty()) transform(s.begin(), s.begin() + 1, s.begin(), ::tolower); return s; }, "Переводит первую букву в нижний регистр" },
            {[](string s) { if (!s.empty()) reverse(s.begin(), s.end()); return s; }, "Разворачивает строку задом наперёд" }
        };

        intFunctions = {
            {[](int i) { return (i > 0) ? rand() % (i + 1) : 0; }, "Возвращает случайное число от 0 до i" },
            {[](int i) { return i * -1; }, "Меняет знак числа (i → -i)" },
            {[](int i) { return (rand() % 100) * i; }, "Умножает число на случайное число от 0 до 99" },
            {[](int i) { return static_cast<int>(sqrt(i)); }, "Возвращает квадратный корень числа (целочисленно)" },
            {[](int i) { return (i > 0) ? static_cast<int>(log10(i)) : 0; }, "Возвращает логарифм числа по основанию 10 (целочисленно)" }
        };

        doubleFunctions = {
            {[](double i) { return pow(i, 2); }, "Возводит число в квадрат" }, {[](double i) { return sqrt(i); }, "Вычисляет квадратный корень" }, {[](double i) { return i / 2; }, "Делит число на 2" }, {[](double i) { return i / ((rand() % 9) + 1); }, "Делит число на случайное число от 1 до 9" },
            {[](double i) { return i; }, "Возвращает число без изменений" }
        };
    }

    void printDescription(string type, int number) {
    if (type == "int") {cout << intFunctions[number].description << endl;}
    else if (type == "string") {cout << stringFunctions[number].description << endl;}
    else if (type == "double") {cout << doubleFunctions[number].description << endl;};
    }

    function<string(string)>  getRandStringFunction() {
        int RandIndex = rand() % stringFunctions.size();
        function<string(string)> curFunction;
        curFunction = stringFunctions[RandIndex].func;
        cout << "Передана функция: " << stringFunctions[RandIndex].description << endl;
        return curFunction;
    }

    function<int(int)> getRandIntFunction() {
        int RandIndex = rand() % intFunctions.size();
        function<int(int)> curFunction;
        curFunction = intFunctions[RandIndex].func;
        cout << "Передана функция: " << intFunctions[RandIndex].description << endl;
        return curFunction;
    }

    function<double(double)> getRandDoubleFunction() {
        int RandIndex = rand() % doubleFunctions.size();
        function<double(double)> curFunction;
        curFunction = doubleFunctions[RandIndex].func;
        cout << "Передана функция: " << doubleFunctions[RandIndex].description << endl;
        return curFunction;
    }
};

int main() {
    string directory = "Lab8/files";
    vector<string> files = getFilesInDirectory(directory);
    vector<shared_ptr<DataHandler>> handlers;
    miniFunctions miniFunctions;

    for (size_t i = 0; i < files.size(); i++) {
        string file = files[i];

        size_t lastSlash = file.find_last_of("/\\");
        string filename = (lastSlash == string::npos) ? file : file.substr(lastSlash + 1);

        string type = filename.substr(1, 3);

        cout << "Потоку " << i << " назначена функция: ";

        if (type == "int") {
            function<int(int)> randFunction = miniFunctions.getRandIntFunction();
            handlers.push_back(make_shared<IntDataHandler>(file, randFunction));
            cout << "Функция для int" << endl;
        }
        else if (type == "str") {
            function<string(string)> randFunction = miniFunctions.getRandStringFunction();
            handlers.push_back(make_shared<StringDataHandler>(file, randFunction));
            cout << "Функция для string" << endl;
        }
        else if (type == "dou") {
            function<double(double)> randFunction = miniFunctions.getRandDoubleFunction();
            handlers.push_back(make_shared<DoubleDataHandler>(file, randFunction));
            cout << "Функция для double" << endl;
        }
        else {
            cout << "Ошибка: Неизвестный тип данных в файле " << file << endl;
        }
    }

    cout << "It's done" << endl;
    return 0;
}