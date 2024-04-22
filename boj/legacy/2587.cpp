#include <iostream>
#include <vector>

using namespace std;

int main() {
    short temp, sum = 0;
    vector<short> array(5);
    for (short i = 0; i < 5; ++i) {
        cin >> array[i];
        sum += array[i];
    }
    for (short i = 0; i < 5; ++i)
        for (short j = i; j < 5; ++j)
            if (i != j && array[i] > array[j])
               temp = array[i]
               , array[i] = array[j]
               , array[j] = temp;
    
    cout << sum/5 << endl << array[2];
}