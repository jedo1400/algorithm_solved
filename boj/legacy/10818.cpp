#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    int n, in, min = INT_MAX, max = INT_MIN;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> in;
        if (min > in) min = in;
        if (max < in) max = in;
    } cout << min << ' ' << max;
}