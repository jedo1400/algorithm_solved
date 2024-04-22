#include <iostream>
#include <cmath>

using namespace std;

short numlen(int n) {
    short result;
    for (result = 0; n >= 10; n /= 10)
        result++;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1;
    while (n) {
        cin >> n;
        if (n) {
            bool flag = 0;
            short memo = numlen(n);
            short array[5] = {0,};
            for (short i = pow(10, memo), j = 0; i >= 10; i /= 10, ++j)
                array[j] = n/i, n %= i;
            array[memo] = n % 10;
            for (short i = 0; i <= (memo+1)/2-1; ++i) {
                if (array[i] != array[memo-i]) {
                    flag = 1;
                    break;
                }
            }
            cout << (flag ? "no" : "yes") << '\n';
            n = 1;
        }
    }
}