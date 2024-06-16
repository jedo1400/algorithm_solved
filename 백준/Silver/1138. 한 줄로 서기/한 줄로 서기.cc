#include <iostream>
#include <vector>

using namespace std;

short findNearEmptyIndex(vector<short> &array, short i) {
    short k, empty = 0;
    for (k = 0; empty < i || array[k] != 0; ++k)
        if (!(array[k]))
            ++empty;
    return k;
}

int main() {
    short n, i;
    cin >> n;

    vector<short> array(n, 0);
    
    for (short j = 1; j <= n; ++j) {
        cin >> i;
        array[findNearEmptyIndex(array, i)] = j;
    }

    for (short j = 0; j < n; ++j)
        cout << array[j] << ' ';
}