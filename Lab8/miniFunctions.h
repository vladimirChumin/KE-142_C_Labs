#ifndef MINIFUNCTIONS_H
#define MINIFUNCTIONS_H

#include <string>
#include <vector>
#include <functional>

using namespace std;

class miniFunctions {
protected:
    struct StringFunction {
        string description;
        function<string(string)> func;
    };

    struct IntFunction {
        string description;
        function<int(int)> func;
    };

    struct DoubleFunction {
        string description;
        function<double(double)> func;
    };

    static const vector<IntFunction> intFunctions;
    static const vector<StringFunction> stringFunctions;
    static const vector<DoubleFunction> doubleFunctions;

public:
    static function<int(int)> getRandomIntFunction();
    static function<string(string)> getRandomStringFunction();
    static function<double(double)> getRandomDoubleFunction();
};

#endif // MINIFUNCTIONS_H
