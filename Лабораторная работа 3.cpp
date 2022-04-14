// Лабораторная работа 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Создать абстрактный класс «римское число». Объявить в классе следующие функции:
//ToString() : String, возвращающую строковое представление числа;
//ToDouble() : Double, возвращающую арабское представление числа.
//Унаследовать от этого класса два других : «целое римское число» и «вещественное римское число».
//В основном коде программы реализовать функцию сложения полиморфных(как целых так и вещественных) римских чисел.
//Применить функцию к массиву полиморфных римских чисел и вывести результат сложения на экран.
//Усложнение 1 (+2 балла). Определить перегруженную операцию присваивания к римскому числу строки. 
//Проверить работоспособность на массиве полиморфных адресов.
//Усложнение 2(+2 балла).Определить перегруженную операцию присваивания к римскому числу числа типа double.
//Проверить работоспособность на массиве полиморфных адресов.

#pragma once
#include <iostream>
#include <string>
using namespace std;

class RimNumber {
private:
protected:
    virtual string ToString(double enter) = 0;
    virtual double ToDouble(string enter) = 0;
    double enter;

public:
    RimNumber(double enter) : enter(enter) {};
    operator double();
    virtual RimNumber& operator=(double arab);
    virtual RimNumber& operator=(RimNumber& num);
};

class IntRimNumber : public RimNumber {
private:
    string number_ar;
    int length;
    bool point;
    bool slash;
    double error;
    double number_arab;
protected:
    string ToString(double enter) override {
        int number_arint = (int)enter;
        number_ar = to_string(number_arint);
        return number_ar;
    }
    double ToDouble(string number_rim) override {
        length = number_rim.length();
        for (int i = length - 1; i >= 0; i--) {
            if (number_rim == "." or number_rim == ",") {
                point = true;
            }
            if (number_rim == "/") {
                slash = true;
            }
        }
        if ((point) or (slash)) {
            cout << "This is the fraction. Changing interface on real numbers..." << endl;
            error = 999999999;
            return error;
        }
        else {
            for (int i = 0; i < length; i++) {
                if ((number_rim[i] == 'i') or (number_rim[i] == 'I')) {
                    if ((number_rim[i + 1] == 'v') or (number_rim[i + 1] == 'V') or (number_rim[i + 1] == 'x') or (number_rim[i + 1] == 'X')) {
                        number_arab += 0;
                    }
                    else {
                        number_arab += 1;
                    }
                }
                if ((number_rim[i] == 'v') or (number_rim[i] == 'V')) {
                    if ((number_rim[i - 1] == 'i') or (number_rim[i - 1] == 'I')) {
                        number_arab += 4;
                    }
                    else {
                        number_arab += 5;
                    }
                }
                if ((number_rim[i] == 'x') or (number_rim[i] == 'X')) {
                    if ((number_rim[i - 1] == 'i') or (number_rim[i - 1] == 'I')) {
                        number_arab += 9;
                    }
                    else {
                        if ((number_rim[i + 1] == 'l') or (number_rim[i + 1] == 'L') or (number_rim[i + 1] == 'c') or (number_rim[i + 1] == 'C')) {
                            number_arab += 0;
                        }
                        else {
                            number_arab += 10;
                        }
                    }
                }
                if ((number_rim[i] == 'l') or (number_rim[i] == 'L')) {
                    if ((number_rim[i - 1] == 'x') or (number_rim[i - 1] == 'X')) {
                        number_arab += 40;
                    }
                    else {
                        number_arab += 50;
                    }
                }
                if ((number_rim[i] == 'c') or (number_rim[i] == 'C')) {
                    if ((number_rim[i - 1] == 'x') or (number_rim[i - 1] == 'X')) {
                        number_arab += 90;
                    }
                    else {
                        if ((number_rim[i + 1] == 'd') or (number_rim[i + 1] == 'D') or (number_rim[i + 1] == 'm') or (number_rim[i + 1] == 'M')) {
                            number_arab += 0;
                        }
                        else {
                            number_arab += 100;
                        }
                    }
                }
                if ((number_rim[i] == 'd') or (number_rim[i] == 'D')) {
                    if ((number_rim[i - 1] == 'c') or (number_rim[i - 1] == 'C')) {
                        number_arab += 400;
                    }
                    else {
                        number_arab += 500;
                    }
                }
                if ((number_rim[i] == 'm') or (number_rim[i] == 'M')) {
                    if ((number_rim[i - 1] == 'c') or (number_rim[i - 1] == 'C')) {
                        number_arab += 900;
                    }
                    else {
                        number_arab += 1000;
                    }
                }
            }
        }
        return number_arab;
    }
public:
    IntRimNumber(double enter) : RimNumber(enter) {
        void summ(double number_arab) {}
    };
};


int main()
{
    int choise;
    //const size_t i = 0;
    int choise_1;
    int choise_2;
    string roman;
    double entering;
    string arab;
    //IntRimNumber a(roman);
    RimNumber* list[2];
    cout << "What numbers do you want to work with?" << endl;
    cout << "Enter 1, if you want to summ two roman numbers and translate in arabic" << endl;
    cout << "Enter 2, if you want to summ two arabic numbers and translate in string" << endl;
    for (int i = 0; i < 2; i++) {
        if (choise == 1) {
            cout << "We will work with..." << endl;
            cout << "1 - with integer numbers" << endl;
            cout << "2 - with real numbers" << endl;
        }
        if (choise == 2) {
            cout << "Enter your 2 numbers, which want to add it" << endl;
            cin >> entering;
            list[i] = new IntRimNumber(entering);

        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

RimNumber& RimNumber::operator=(RimNumber& num)
{
    // TODO: вставьте здесь оператор return
}
