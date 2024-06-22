#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<bool> prime(100001, 1);
    prime[0] = 0, prime[1] = 0; // 1은 소수가 아니야
    for (int i = 2; i*i <= 100000; ++i)
        if (prime[i])
            for (int j = i*i; j <= 100000; j += i)
                prime[j] = 0;

    int a, b, under_prime = 0;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        short cnt = 0;
        if (!prime[i]) { // 소수는 소인수분해가 안돼
            int c = i;
            while (c != 1) {
                int j;
                for (j = 2; c % j; ++j)
                    continue;
                c /= j;
                ++cnt;
            }
        }
        if (prime[cnt])
            ++under_prime;
    }

    cout << under_prime;
    return 0;
}