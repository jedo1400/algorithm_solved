#include <iostream>
#include <vector>

using namespace std;

int main() {
    double n, best = 0, result = 0;
    cin >> n;

    vector<double> array(n);

    for (short i = 0; i < n; ++i) {
        cin >> array[i];
        if (array[i] > best) best = array[i];
    }

    for (short i = 0; i < n; ++i) 
        result += array[i]/best*100;
    cout << result/n;
}
