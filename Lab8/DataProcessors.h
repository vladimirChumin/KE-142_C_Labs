#ifndef DATAPROCESSORS_H
#define DATAPROCESSORS_H

#include "DataHandler.h"
#include <functional>

class IntDataHandler : public DataHandler {
protected:
    function<int(int)> func;

public:
    IntDataHandler(const string& filePath, function<int(int)> func);
    void useFunction() override;
};

class StringDataHandler : public DataHandler {
protected:
    function<string(string)> func;

public:
    StringDataHandler(const string& filePath, function<string(string)> func);
    void useFunction() override;
};

class DoubleDataHandler : public DataHandler {
protected:
    function<double(double)> func;

public:
    DoubleDataHandler(const string& filePath, function<double(double)> func);
    void useFunction() override;
};

#endif // DATA_HANDLERS_H

