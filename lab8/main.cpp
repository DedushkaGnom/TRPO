#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include "numeric"

using namespace std;

int main() {
    //first task
    vector<uint16_t> arr_uint16(20);
    iota(arr_uint16.begin(), arr_uint16.end(), 0x3145 );
    cout << "Original:" << endl;
    for (auto i: arr_uint16) { cout << hex << i << " "; }
    random_shuffle(arr_uint16.begin(), arr_uint16.end());
    cout << "\nShuffled:" << endl;
    for (auto i: arr_uint16) { cout << i << " "; }
    cout << endl;
    qsort(arr_uint16.begin().base(), size_t(arr_uint16.size()),
          sizeof(arr_uint16.at(0)), [](const void *a, const void *b)
          {
              auto arg1 = *static_cast<const uint16_t *>(a);
              auto arg2 = *static_cast<const uint16_t *>(b);
              if (arg1 > arg2) return  1;
              if (arg1 < arg2) return  -1;
              return 0;
          }
    );
    cout << "Sorted:" << endl;
    for (auto i: arr_uint16) { cout << i << " "; }
    cout << dec << endl << endl;

    //second task
    vector<int> acceleration = {1, 2, 3, -4, 5};
    vector<int> speed(acceleration.size());
    partial_sum(acceleration.begin(), acceleration.end(), speed.begin());
    vector<int> location(speed.size());
    partial_sum(speed.begin(), speed.end(), location.begin());
    for(auto i : acceleration) cout << i << " ";
    cout << endl;
    for(auto i : speed) cout << i << " ";
    cout << endl;
    for(auto i : location) cout << i << " ";
    cout << endl;
}





