#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    return (a % b ? gcd(b, a % b) : b);
}

int main() {
    int n, rst, prev, tmp, count = 0;
    cin >> n;
    vector<int> arr(n-1);
    
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (i == 1)
            rst = tmp-prev;
        if (i > 2)
            rst = gcd(tmp-prev, rst);
        if (i)
            arr[i-1] = tmp-prev;
        prev = tmp;
    } for (int i = 0; i < n-1; ++i)
        count += (arr[i]-rst)/rst;

    cout << count;
}