#include <iostream>

using namespace std;

int getSumOfNumbers(int n) {
    int result = n % 10; // 일의 자릿수
    for (int i = 10; i < n; i *= 10)
        result += (n / i) % 10;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i)
        if (i+getSumOfNumbers(i) == n) {
            cout << i;
            return 0;
        }
    cout << 0;
}


