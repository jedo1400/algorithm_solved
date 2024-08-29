#include <iostream>

using namespace std;

int main() {
    int n, cnt{};
    cin >> n;
    for (int i = n; i; --i) {
        int total{};
        for (int j = i; total < n && j; --j)
            total += j;
        if (total == n)
            ++cnt;
    }
    
    cout << cnt;
}