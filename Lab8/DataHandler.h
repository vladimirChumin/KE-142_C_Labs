#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class DataHandler {
protected:
    string filePath;
    vector<string> data;

public:
    DataHandler(const string& filePath);
    virtual ~DataHandler();

    virtual void useFunction() = 0; // Чисто виртуальная функция

    void saveData();
    string loadData();
    string serialize();
    void deserialize();
};

#endif // DATA_HANDLER_H