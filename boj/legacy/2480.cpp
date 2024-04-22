#include <iostream>

using namespace std;

int main() {
    short arr[3], count = 0, last, largest = 0;
    cin >> arr[0] >> arr[1] >> arr[2];
    for (short i = 0; i < 3; ++i) {
        for (short j = 0; j < 3; ++j)
            if (i != j && arr[i] == arr[j])
                count++, last = arr[i];
        if (arr[i] > largest)
            largest = arr[i];
    }
    if (count == 6)
        cout << 10000+arr[0]*1000;
    else if (count == 2)
        cout << 1000+last*100;
    else
        cout << largest*100;
}