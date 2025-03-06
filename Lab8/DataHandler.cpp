#include <iostream>
#include <vector>
#include <thread>
#include <fstream>
#include <string>
#include <filesystem>
#include "DataHandler.h"
using namespace std;

DataHandler::DataHandler(const string& filePath) : filePath(filePath) {
    deserialize();
}

DataHandler::~DataHandler() {
    saveData();
}

void DataHandler::saveData() {
    string text = serialize();
    ofstream fileOut(filePath);
    if (fileOut.is_open()) {
        fileOut << text << endl;
        fileOut.close();
    }
}

string DataHandler::loadData() {
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

string DataHandler::serialize() {
    string result;
    for (const string& element : data) {
        result += element + "|";
    }
    if (!result.empty()) {
        result.pop_back(); // убрать лишний '|'
    }
    return result;
}

void DataHandler::deserialize() {
    string line = loadData();
    if (line.empty()) return;
    size_t start = 0;
    size_t end = line.find('|');
    while (end != string::npos) {
        data.push_back(line.substr(start, end - start));
        start = end + 1;
        end = line.find('|', start);
    }
}


