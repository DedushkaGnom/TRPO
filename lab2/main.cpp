#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
 * 1
 * 1, 15	В векторе целого типа заменить максимальный элемент суммой предыдущих элементов, минимальный – суммой последующих элементов.
 *
 * 2
 *Дана строка слов, разделенных пробелами. Сформируйте новую строку, вставив перед каждым вхождением слова "and"
 * запятую. Определите, сколько в строке симметричных слов (слов-перевёртышей, например, «казак», «шалаш»).
 * */
using namespace std;

void addDelim(string &input) {
    for (int i = 0; i < input.size() - 2; i++) {
        if (input[i] == 'a' && input[i + 1] == 'n' && input[i + 2] == 'd') {
            input.insert(i, ",");
            i++;
        }
    }
    cout << input << endl;
}

int findPalindrome(string input) {
    string dividers = " ,.";
    string word;
    vector<string> result;
    for (auto symbol: input) {
        if (dividers.find(symbol) != string::npos) {
            result.push_back(word);
            word = "";
        } else {
            word += symbol;
        }
    }
    //очистка от лишних пробелов
    for (int i = 0; i < result.size(); i++) {
        if (result[i].empty()) result.erase(result.cbegin() + i);
    }
    int amountOfPalindrome = 0;
    for(int i = 0; i < result.size(); i++){
        string temp = result[i];
        std::reverse(temp.begin(), temp.end());
        if(result[i] == temp) amountOfPalindrome++;
    }
    return amountOfPalindrome;
}

int main() {
    /////////
    //task1//
    /////////
    vector<int> array = {2, 1, 5, 15, 0, 3};
    string a;
    a = "21312";
    std::reverse(a.begin(), a.end());
    //int a = 5;
    //for(int i = 0; i < a; i++) {
    //    array.push_back(rand()%10);
    //}
    //for(auto i:array) cout << i << " ";

    vector<int> sort_array = array;
    sort(sort_array.begin(), sort_array.end());

    int maximum = sort_array.back();
    int minimum = sort_array.front();

    //find max
    int max_iter = 0;
    int max_sum = 0;
    while (array[max_iter] != maximum) {
        max_sum += array[max_iter];
        max_iter++;
    }

    //find min
    int min_iter = 0;
    int min_sum = 0;
    while (array[min_iter] != minimum) {
        min_iter++;
    }
    for (int i = min_iter; i < array.size(); i++) {
        min_sum += array[i];
    }

    //results
    cout << "Sum for min: " << min_sum << endl;
    array[min_iter] = min_sum;
    cout << "Sum for max: " << max_sum << endl;
    array[max_iter] = max_sum;
    for (auto i: array) cout << i << " ";

    /////////
    //task2//
    /////////
    cout << "\n\n\n";
    string str = "Gospodi, za chto mne etot sas and Gospodi vse vot eto";
    addDelim(str);
    cout << "Palindromes: " << findPalindrome(str) << endl;

    return 0;
}
