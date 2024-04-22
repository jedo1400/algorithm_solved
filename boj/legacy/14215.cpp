#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    short input[3], largest = SHRT_MIN, smallSum = 0, result = 0;
    for (short i = 0; i < 3; ++i) {
        cin >> input[i];
        if (input[i] > largest) largest = input[i];
        smallSum += input[i];
    } smallSum -= largest;
    if (largest >= smallSum) {
        largest = smallSum-1;
        cout << largest*2+1;
        return 0;
    }

    for (short i = 0; i < 3; ++i)
        result += input[i];
    cout << result;
}