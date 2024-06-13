#include <iostream>
#include <vector>
#include <deque>

using namespace std;

bool isPrime(int n) {
    for (short i = 2; i*i <= n; ++i)
        if (!(n % i))
            return 0;
    return 1;
}

bool isPalindrome(int n) {
    vector<short> array;
    int m, size = 0;
    for (m = 1; n/m; m *= 10, ++size)
        continue;
    m /= 10;

    if (!(size % 2) && n != 11)
        return 0;

    while (m) {
        array.push_back(n/m);
        n %= m, m /= 10;
    }

    for (short i = 0; i < array.size()/2; ++i)
        if (array[i] != array[array.size()-1-i])
            return 0;
    return 1;
}

int main() {
    int a, b;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    if (b > 10000000)
        b = 10000000;

    deque<bool> prime(b+1, 1);

    for (int i = 2; i <= b; ++i)
        if (prime[i])
            for (int j = 2*i; j <= b; j += i)
                prime[j] = 0;
    
    for (int i = a; i <= b; ++i)
        if (prime[i] && isPalindrome(i))
            cout << i << '\n';
    cout << -1;
}