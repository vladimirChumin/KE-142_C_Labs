// Задание 6.1


//#include <iostream>
//#include <cmath>  // Для pow()
//using namespace std;
//
//class Polynomial {
//private:
//    int degree;        // Степень полинома
//    double* coeffs;    // Динамический массив коэффициентов
//
//public:
//    // Конструктор
//    Polynomial(int deg) : degree(deg) {
//        coeffs = new double[degree + 1]();  // Выделение памяти и инициализация 0
//    }
//
//    // Деструктор
//    ~Polynomial() {
//        delete[] coeffs;  // Освобождение памяти
//    }
//
//    // Ввод коэффициентов полинома
//    void inputCoefficients() {
//        cout << "Введите коэффициенты от старшего (x^" << degree << ") до младшего (x^0):\n";
//        for (int i = 0; i <= degree; i++) {
//            cout << "Коэффициент при x^" << (degree - i) << ": ";
//            cin >> coeffs[i];
//        }
//    }
//
//    // Вывод полинома
//    void display() const {
//        for (int i = 0; i <= degree; i++) {
//            if (coeffs[i] != 0) {
//                cout << coeffs[i] << "x^" << (degree - i);
//                if (i < degree) cout << " + ";
//            }
//        }
//        cout << endl;
//    }
//
//    // Перегрузка оператора + для сложения двух полиномов
//    Polynomial operator+(const Polynomial& other) const {
//        int maxDegree = max(degree, other.degree);  // Находим максимальную степень
//        Polynomial result(maxDegree);  // Создаем новый полином
//
//        // Копируем коэффициенты из текущего полинома
//        for (int i = 0; i <= degree; i++) {
//            result.coeffs[maxDegree - degree + i] = coeffs[i];
//        }
//
//        // Складываем коэффициенты из второго полинома
//        for (int i = 0; i <= other.degree; i++) {
//            result.coeffs[maxDegree - other.degree + i] += other.coeffs[i];
//        }
//
//        return result;
//    }
//
//    // Вычисление значения полинома при заданном x
//    double evaluate(double x) const {
//        double result = 0;
//        for (int i = 0; i <= degree; i++) {
//            result += coeffs[i] * pow(x, degree - i);  // Считаем x^степень
//        }
//        return result;
//    }
//};
//
//// Главная функция
//int main() {
//    int degree1, degree2;
//
//    cout << "Введите степень первого полинома: ";
//    cin >> degree1;
//    Polynomial poly1(degree1);
//    poly1.inputCoefficients();
//
//    cout << "Введите степень второго полинома: ";
//    cin >> degree2;
//    Polynomial poly2(degree2);
//    poly2.inputCoefficients();
//
//    cout << "\nПервый полином: ";
//    poly1.display();
//    cout << "Второй полином: ";
//    poly2.display();
//
//    // Сложение полиномов
//    Polynomial sum = poly1 + poly2;
//    cout << "Сумма полиномов: ";
//    sum.display();
//
//    // Вычисление значения полинома
//    double x;
//    cout << "\nВведите x для вычисления P(x): ";
//    cin >> x;
//    cout << "P(x) = " << poly1.evaluate(x) << endl;
//
//    return 0;
//}
