#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <chrono>
#include <fstream>
#include <string>
#include "locale.h"

using namespace std;

class FileExtractor {
protected:
    string filename;
    vector<string> data;

public:
    FileExtractor(const string& file) : filename(file) {}

    void saveData() {
        string text = serialize(data);
        ofstream fileOut(filename);
        if (fileOut.is_open()) {
            fileOut << text << endl;
            fileOut.close();
        }
    }

    void loadData() {
        ifstream fileIn(filename);
        if (!fileIn.is_open()) {
            cerr << "Ошибка: файл не найден!" << endl;
            return;
        }

        string line;
        while (getline(fileIn, line)) {
            for (string element : deserialize(line)) {
                data.push_back(element);
            }
        }
        fileIn.close();
    }

    string serialize(const vector<string>& data) {
        if (data.empty()) return "";

        string result;
        for (const string& element : data) {
            result += element + "|";
        }
        result.pop_back();
        return result;
    }

    vector<string> deserialize(const string& data) {
        vector<string> result;
        size_t start = 0;
        size_t end = data.find('|');

        while (end != string::npos) {
            result.push_back(data.substr(start, end - start));
            start = end + 1;
            end = data.find('|', start);
        }

        return result;
    }

    void printData() {
        for (const string& str : data) {
            cout << str << endl;
        }
    }
};

