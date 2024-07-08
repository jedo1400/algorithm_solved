#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> array(n);

    for (int i = 0; i < n; ++i)
        cin >> array[i];
    
    int largest = 0, profit = 0;
    for (int i = n-1; i >= 0; --i) {
        if (largest < array[i])
            largest = array[i];
        if (profit < largest-array[i])
            profit = largest-array[i];
    }

    cout << profit;
}