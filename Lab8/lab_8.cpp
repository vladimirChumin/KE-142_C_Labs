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
#include "DataHandler.h"
#include "DataProcessors.h"
#include "miniFunctions.h"

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

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0)); // инициализируем rand()

    string directory = "Lab8/files"; // Лучше использовать "/"
    vector<string> files = getFilesInDirectory(directory);

    vector<shared_ptr<DataHandler>> handlers;

    // Создаём потоки
    vector<thread> threads;

    for (size_t i = 0; i < files.size(); i++) {
        string file = files[i];
        size_t lastSlash = file.find_last_of("/\\");
        string filename = (lastSlash == string::npos) ? file : file.substr(lastSlash + 1);

        // Файл вида "1int.txt" -> type = "int"
        string type = filename.substr(1, 3);

        cout << "Потоку " << i << " назначена функция: ";

        if (type == "int") {
            auto f = miniFunctions::getRandomIntFunction();
            handlers.push_back(make_shared<IntDataHandler>(file, f));
            cout << "Функция для int" << endl;
        }
        else if (type == "str") {
            auto f = miniFunctions::getRandomStringFunction();
            handlers.push_back(make_shared<StringDataHandler>(file, f));
            cout << "Функция для string" << endl;
        }
        else if (type == "dou") {
            auto f = miniFunctions::getRandomDoubleFunction();
            handlers.push_back(make_shared<DoubleDataHandler>(file, f));
            cout << "Функция для double" << endl;
        }
        else {
            cout << "Ошибка: неизвестный тип '" << type << "' в файле " << file << endl;
        }
    }

    // Запускаем потоки
    for (auto& h : handlers) {
        // Передаём shared_ptr по значению, чтобы копия жила в лямбде
        threads.emplace_back([h]() {
            h->useFunction(); // Применяем функцию
        });
    }

    // Ждём завершения всех потоков
    for (auto& t : threads) {
        t.join();
    }

    cout << "It's done" << endl;
    return 0;
}
