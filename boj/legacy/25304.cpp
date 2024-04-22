#include <iostream>

using namespace std;

int main() {
    int x, temp, sum = 0;
    short n;
    cin >> x >> n;
    int* result = new int[n]{};
    for (short i = 0; i < n; ++i)
        for (short j = 0; j < 2; ++j) {
            cin >> temp;
            j == 0 ? result[i] += temp : result[i] *= temp; 
        }
    for (short i = 0; i < n; ++i)
        sum += result[i];
    cout << (sum == x ? "Yes" : "No");
}