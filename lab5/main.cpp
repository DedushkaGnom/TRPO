#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

/*
 * Задание 1
 * Выполнить задачу в соответствии с номером варианта. При выполнении задачи использовать лямбда-выражения (max – 3 балла).
 * Задание 2
 * Повторить выполнение своего варианта задания с использованием классов (max – 4 балла).
 * Задание 3
 * Повторить выполнение своего варианта задания, но с использованием параметризованных классов (max – 5 баллов).
 *
 * Дан целочисленный вектор. Используя функцию find_if найти первое простое число
 * (по определению 0 и 1 простыми числами не являются)*/

using namespace std;

template <typename T>
class FindFirstSimple
{
private:
    vector<T> arr;
public:
    // The constructor.
    FindFirstSimple(vector<T> arr) : arr(arr) {};

    void operator()() {
        const typename vector<T>::const_iterator result = find_if(arr.begin(), arr.end(), [](T input)
        { if (input == 0 || input == 1) return false;
            for (int i = 2; i <= sqrt(input); i++) {
                if (input % i == 0) {
                    return false;
                }
            }
            return true;
        });
        if (result != arr.end())
        {
            cout << "The first simple number in the vector is "
                 << *result << "." << endl;
        }
        else {cout << "The vectors contains no simple numbers."
                   << endl;
        }
    }
};


int main()
{
    // Create a vector of signed integers with a few elements.
    vector<int> v;
    v.push_back(34);
    v.push_back(43);
    v.push_back(56);
    v.push_back(5);
    v.push_back(1);
    (FindFirstSimple(v)());


    return 0;
}
