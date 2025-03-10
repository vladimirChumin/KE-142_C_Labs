#include <iostream>
#include <limits> // Для numeric_limits
using namespace std;

class TemperatureLogger {
private:
static const int MAX_READINGS = 365; // Предполагаем максимум 365 показаний
int temperatures[MAX_READINGS]; // Массив для хранения показаний температуры
int numReadings; // Текущее количество показаний
public:
// Конструктор
TemperatureLogger() : numReadings(0) {
for (int i = 0; i < MAX_READINGS; ++i) {
temperatures[i] = 0;
}
}
// Метод для добавления показания температуры
void addReading(int temp) {
if (numReadings < MAX_READINGS) {
temperatures[numReadings++] = temp;
} else {
std::cout << "Достигнуто максимальное количество показаний, добавление невозможно." << std::endl;
}
}
// Метод для расчета средней температуры
double calculateAverage() const {
if (numReadings == 0) return 0; // Предотвращаем деление на ноль
int sum = 0;
for (int i = 0; i < numReadings; ++i) {
sum += temperatures[i];
}
return static_cast<double>(sum) / numReadings;
}
// Метод для поиска максимального показания температуры
int findMaxTemperature() const {
int maxTemp = std::numeric_limits<int>::min(); // Инициализируем наименьшим возможным значением
for (int i = 0; i < numReadings; ++i) {
if (temperatures[i] > maxTemp) {
maxTemp = temperatures[i];
}
}
return maxTemp;
}
// Метод для поиска минимального показания температуры
int findMinTemperature() const {
int minTemp = std::numeric_limits<int>::max(); // Инициализируем наибольшим возможным значением
for (int i = 0; i < numReadings; ++i) {
if (temperatures[i] < minTemp) {
minTemp = temperatures[i];
}
}
return minTemp;
}
};
int temperatureExample() {
TemperatureLogger logger;
// Пример использования
logger.addReading(23);
logger.addReading(25);
logger.addReading(22);
logger.addReading(26);
logger.addReading(24);
std::cout << "Средняя температура: " << logger.calculateAverage() << std::endl;
std::cout << "Максимальная температура: " << logger.findMaxTemperature() << std::endl;
std::cout << "Минимальная температура: " << logger.findMinTemperature() << std::endl;
return 0;
}

class Matrix {
private:
    static const int ROWS = 3; // Количество строк
    static const int COLS = 3; // Количество столбцов
    int data[ROWS][COLS]; // 2D массив для данных матрицы
public:
    // Конструктор для инициализации матрицы нулями
    Matrix() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                data[i][j] = 0;
            }
        }
    }
    // Функция для ввода данных матрицы пользователем
    void inputMatrix() {
        cout << "Введите данные матрицы (" << ROWS << "x" << COLS << "):\n";
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                cin >> data[i][j];
            }
        }
    }
    // Функция для сложения двух матриц
    Matrix add(const Matrix& m) const {
        Matrix result;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return result;
    }
    // Функция для вычитания двух матриц
    Matrix subtract(const Matrix& m) const {
        Matrix result;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                result.data[i][j] = data[i][j] - m.data[i][j];
            }
        }
        return result;
    }
    // Функция для отображения матрицы
    void display() const {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }
};
int matrixExample() {
    Matrix m1, m2, result;
    cout << "Ввод данных для Матрицы 1:\n";
    m1.inputMatrix();
    cout << "Ввод данных для Матрицы 2:\n";
    m2.inputMatrix();
    cout << "Матрица 1:\n";
    m1.display();
    cout << "Матрица 2:\n";
    m2.display();
    result = m1.add(m2);
    cout << "Результат сложения:\n";
    result.display();
    result = m1.subtract(m2);
    cout << "Результат вычитания:\n";
    result.display();
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
// Определение структуры Student
struct Student {
string name;
int id;
float grades[5]; // Массив для хранения 5 оценок студента
};
// Функция для заполнения записи студента
void populateStudent(Student& s) {
cout << "Введите имя студента: ";
cin >> s.name;
cout << "Введите ID студента: ";
cin >> s.id;
for (int i = 0; i < 5; ++i) {
cout << "Введите оценку " << (i + 1) << ": ";
cin >> s.grades[i];
}
}
// Функция для отображения записи студента
void displayStudent(const Student& s) {
cout << "Имя: " << s.name << ", ID: " << s.id << ", Оценки: ";
for (int i = 0; i < 5; ++i) {
cout << s.grades[i] << " ";
}
cout << endl;
}
// Функция для расчета и отображения средней оценки студента
void displayAverageGrade(const Student& s) {
float sum = 0;
for (int i = 0; i < 5; ++i) {
sum += s.grades[i];
}
cout << "Средняя оценка для " << s.name << ": " << (sum / 5) << endl;
}
int studentExample() {
const int NUM_STUDENTS = 3; // Количество студентов
Student students[NUM_STUDENTS]; // Массив структур Student
// Заполнение и отображение данных каждого студента
for (int i = 0; i < NUM_STUDENTS; ++i) {
cout << "Студент " << (i + 1) << endl;
populateStudent(students[i]);
displayStudent(students[i]);
displayAverageGrade(students[i]);
cout << endl;
}
return 0;
}

class TemperatureLogger2 {
private:
    int *temperatures; // Указатель на массив температур
    int capacity; // Максимальное количество показаний
    int numReadings; // Текущее количество показаний
public:
    // Конструктор
    TemperatureLogger2(int cap) : capacity(cap), numReadings(0) {
        temperatures = new int[capacity]; // Динамическое выделение памяти
        for (int i = 0; i < capacity; ++i) {
            temperatures[i] = 0;
        }
    }
    // Деструктор
    ~TemperatureLogger2() {
        delete[] temperatures; // Освобождение выделенной памяти
    }
    // Метод для добавления показания температуры
    void addReading(int temp) {
        if (numReadings < capacity) {
            temperatures[numReadings++] = temp;
        } else {
            cout << "Достигнута максимальная емкость, добавить больше показаний невозможно." << endl;
        }
    }
    // Метод для расчета средней температуры
    double calculateAverage() const {
        if (numReadings == 0) return 0; // Предотвращение деления на ноль
        int sum = 0;
        for (int i = 0; i < numReadings; ++i) {
            sum += temperatures[i];
        }
        return static_cast<double>(sum) / numReadings;
    }
    // Другие методы (findMaxTemperature, findMinTemperature) остаются аналогичными и опущены для краткости
};
int temperatureExample2() {
    TemperatureLogger2 logger(365); // Создание объекта logger с емкостью для 365 показаний
    // Пример использования
    logger.addReading(23);
    logger.addReading(25);
    // Добавление дополнительных показаний по мере необходимости...
    cout << "Средняя температура: " << logger.calculateAverage() << endl;
    return 0;
}


class Matrix2 {
private:
    static const int ROWS = 2; // Упрощено для демонстрации
    static const int COLS = 2; // Упрощено для демонстрации
    int data[ROWS][COLS]; // 2D массив для хранения данных матрицы
public:
    // Конструктор для инициализации элементов матрицы нулями
    Matrix2() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                data[i][j] = 0;
            }
        }
    }
    // Функция для ввода данных матрицы
    void inputMatrix() {
        cout << "Введите данные матрицы (" << ROWS << "x" << COLS << "):\n";
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                cin >> data[i][j];
            }
        }
    }
    // Перегрузка оператора + для сложения двух матриц
    Matrix2 operator+(const Matrix2& other) const {
        Matrix2 result;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    // Функция для отображения матрицы
    void display() const {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int matrixExample2() {
    Matrix2 m1, m2, result;
    cout << "Ввод данных для Матрицы 1:\n";
    m1.inputMatrix();
    cout << "Ввод данных для Матрицы 2:\n";
    m2.inputMatrix();
    result = m1 + m2; // Использование перегруженного оператора +
    cout << "Результат сложения:\n";
    result.display();
    return 0;
}


int main () {
    matrixExample();
    matrixExample2();
    studentExample();
    temperatureExample();
    temperatureExample2();


    return 0;
}