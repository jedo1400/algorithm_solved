#include <iostream>
#include <vector>

using namespace std;

int main() {
    short n, temp;
    cin >> n;
    vector<short> array(n);
    for (short i = 0; i < n; ++i)
        cin >> array[i];
    for (short i = 0; i < n; ++i)
        for (short j = i; j < n; ++j)
            if (i != j && array[i] > array[j])
               temp = array[i]
               , array[i] = array[j]
               , array[j] = temp;
    
    for (short i = 0; i < n; ++i)
        cout << array[i] << endl;
}