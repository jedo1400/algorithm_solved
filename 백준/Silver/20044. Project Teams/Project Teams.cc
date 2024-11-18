#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> power(2*n);

    for (auto &i : power)
        cin >> i;

    sort(power.begin(), power.end());

    int result = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int sum = power[i] + power[2*n-i-1];
        if (sum < result)
            result = sum;
    }

    cout << result;
}