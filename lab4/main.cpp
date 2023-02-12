#include <iostream>
#include <cmath>
#include "vector"
#include "algorithm"

using namespace std;

/*
Дан целочисленный список. Используя функцию for_each найти сумму простых элементов списка
(по определению 0 и 1 простыми числами не являются).
 */

template <typename T>
bool isSimple(T input) {
    if (input == 0 || input == 1) return false;
    for (int i = 2; i <= sqrt(input); i++) {
        if (input % i == 0) {
            return false;
        }
    }
    return true;
}

template<typename T>
class IsSimpleSum {
private:
    vector<T> arr;
public:
    IsSimpleSum(vector<T> arr) : arr(arr) {};

    void operator()() {
        int result = 0;
        for_each(arr.begin(), arr.end(), [&result](T i) { if (isSimple(i)) result += i; });
        cout << result;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    (IsSimpleSum(arr)());
}