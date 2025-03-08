#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <fstream>
#include <string>
#include <filesystem>
#include <cmath>
#include <valarray>
#include <locale>
#include <memory>

using namespace std;
namespace fs = filesystem;

vector<string> getFilesInDirectory(const string& directoryPath) {
    vector<string> files;
    try {
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (fs::is_regular_file(entry.path())) {
                files.push_back(entry.path().string());
            }
        }
    } catch (const fs::filesystem_error& e) {
        cerr << "Ошибка при доступе к директории: " << e.what() << endl;
    }
    return files;
}

class MiniFunctions {
protected:
    struct StringFunction {
        string name;
        function<string(string)> func;
    };
    struct IntFunction {
        string name;
        function<int(int)> func;
    };
    struct DoubleFunction {
        string name;
        function<double(double)> func;
    };

    static vector<StringFunction> stringFunctions;
    static vector<IntFunction> intFunctions;
    static vector<DoubleFunction> doubleFunctions;

    string lastFunction;

public:
    MiniFunctions () {};

    string returnLastFunction (){return lastFunction;}

    function<string(string)> getRandomStringFunction() {
        int randomInt = rand() % stringFunctions.size();
        lastFunction = stringFunctions[randomInt].name;
        return stringFunctions[randomInt].func;
    }

    function<int(int)> getRandomIntFunction() {
        int randomInt = rand() % intFunctions.size();
        lastFunction = intFunctions[randomInt].name;
        return intFunctions[randomInt].func;
    }

    function<double(double)> getRandomDoubleFunction() {
        int randomInt = rand() % doubleFunctions.size();
        lastFunction = doubleFunctions[randomInt].name;
        return doubleFunctions[randomInt].func;
    }

};

// Инициализация статических членов класса внутри класса
vector<MiniFunctions::StringFunction> MiniFunctions::stringFunctions = {
    {"Добавление восклицательного знака в конце слова.", [](string s) { return s + "!"; }},
    {"Преобразование строки в верхний регистр.", [](string s) { transform(s.begin(), s.end(), s.begin(), ::toupper); return s; }},
    {"Умножение длины строки на 2.", [](string s) { return s + s; }},
    {"Удаление пробелов в начале и конце строки.", [](string s) { s.erase(0, s.find_first_not_of(' ')); s.erase(s.find_last_not_of(' ') + 1); return s; }},
    {"Инвертирование строки", [] (string s) {reverse(s.begin(), s.end()); return s; }}
};

vector<MiniFunctions::IntFunction> MiniFunctions::intFunctions = {
    {"Удвоение числа.", [](int i) { return i * 2; }},
    {"Утроение числа.", [](int i) { return i * 3; }},
    {"Изменение числа на случайное.", [](int i) { return rand() % 100; }},
    {"Добавление к числу 10.", [](int i) { return i + 10; }},
    {"Возведение числа в квадрат.", [](int i) { return i * i; }}
};

vector<MiniFunctions::DoubleFunction> MiniFunctions::doubleFunctions = {
    {"Удвоение числа.", [](double d) { return d * 2; }},
    {"Возведение числа в квадрат.", [](double d) { return d * d; }},
    {"Умножение числа на 1,39.", [](double d) { return d * 1.39; }},
    {"Добавление к числу 0,5.", [](double d) { return d + 0.5; }},
    {"Умножение числа на 10", [](double d) { return d * 10; }}
};

class Processor {
    protected:
    string filePath;
    vector<string> data;
    vector<string> oldData;

    public:
    Processor(string fileP) : filePath(fileP) {
        loadData();
    }

    ~Processor() {
        saveData();
    }

    string serializeData (vector<string> currentData) {
        string serializedData = "";
        for (string element : currentData) {
            serializedData += element + "|";
        }
        return serializedData;
    }

    string returnFilePath () {
        return filePath;
    }

vector<string> deserializeData(const string &serializedLine) {
    if (serializedLine.empty())  return {};

    vector<string> deserializedData;
    size_t start = 0;
    size_t end = serializedLine.find('|', start);

    while (end != string::npos) {
        deserializedData.push_back(serializedLine.substr(start, end - start));
        start = end + 1;
        end = serializedLine.find('|', start);
    }

    if (start < serializedLine.size()) {
        deserializedData.push_back(serializedLine.substr(start));
    }

    return deserializedData;
}
    void saveData () {
        string serializedData = serializeData(data);

        ofstream fileOut(filePath);
        fileOut << serializedData << "\n" << serializeData(oldData);
        fileOut.close();
    }

    void loadData () {
        ifstream fileIn(filePath);
        if (!fileIn.is_open()) {
            cout << "Ошибка при открытии файла: " << filePath << endl;
        }
        string line;
        getline(fileIn, line);

        for (string element : deserializeData(line)) {
            data.push_back(element);
        }
        fileIn.close();
    }

    void printData () {
        for (string element : data) {
            cout << element << endl;
        }
    }

    virtual void useFunction () {}
};

class ProcessorForInt : public Processor {
    protected:
    function<int(int)> func;

    public:
    ProcessorForInt (string fileP, const function<int(int)> &func) : Processor(fileP), func(func) {}

    void useFunction () override {
       for (string &element : data) {
           oldData.push_back(element);
           int intElem = stoi(element);
           element = to_string(func(intElem));
       }
    }
};

class ProcessorForString : public Processor {
    protected:
    function<string(string)> func;

    public:
    ProcessorForString (string fileP, const function<string(string)> &func) : Processor(fileP), func(func) {}

    void useFunction () override {
       for (string &element : data) {
           oldData.push_back(element);
           element = func(element);
       }
    }
};

class ProcessorForDouble : public Processor {
    protected:
    function<double(double)> func;

    public:
    ProcessorForDouble (string fileP, const function<double(double)> &func) : Processor(fileP), func(func) {}

    void useFunction () override {
       for (string &element : data) {
           oldData.push_back(element);
           int intElem = stod(element);
           element = to_string(func(intElem));
       }
    }
};

int main () {
    vector<string> files = getFilesInDirectory("Lab8/files/");
    vector<unique_ptr<Processor>> processors;
    vector<thread> threads;
    MiniFunctions miniFunc;

    for (string file : files) {
        bool isInt = file.find("int") != string::npos;
        bool isString = file.find("string") != string::npos;
        bool isDouble = file.find("double") != string::npos;

        if (isInt || isString || isDouble) {
            if (isInt) {
                auto processor = make_unique<ProcessorForInt>(file, miniFunc.getRandomIntFunction());
                processors.push_back(move(processor));
            }
            else if (isString) {
                auto processor = make_unique<ProcessorForString>(file, miniFunc.getRandomStringFunction());
                processors.push_back(move(processor));
            }
            else if (isDouble) {
                auto processor = make_unique<ProcessorForDouble>(file, miniFunc.getRandomDoubleFunction());
                processors.push_back(move(processor));
            }
            cout << "К файлу " << file << " передана функция " << miniFunc.returnLastFunction() << endl;
        }
    }

    for (int i = 0; i < processors.size(); i++) {
        threads.emplace_back([processor = processors[i].get(), i] {processor->useFunction();});
    }

    for (thread &t : threads) {
        t.join();
    }

    cout << "Работа завершена." << endl;
    return 0;
}