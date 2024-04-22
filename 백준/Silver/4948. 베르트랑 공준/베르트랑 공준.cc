#include <iostream>
#include <deque>

using namespace std;

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i*i <= n; ++i)
        if (!(n % i))
            return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 1;

    while(n) {
            int count = 0;
            cin >> n;
        if (n) {
            deque<bool> prime(2*n+1, 1);
            prime[1] = 0;
            for (int i = n+1; i <= 2*n; ++i)
                if (prime[i] && !isPrime(i))
                    for (int j = i; j <= 2*n; j *= 2)
                        prime[j] = 0;
            for (int i = n+1; i <= 2*n; ++i)
                if (prime[i])
                    ++count;
            cout << count << endl;
        }
    }
}