#include <iostream>
#include <vector>
#include <deque>

using namespace std;

bool is_prime(unsigned int n) {
    if (n < 2) return 0;
    for (unsigned int i = 2; (long long)i*i <= (long long)n; ++i)
        if (!(n % i))
            return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned int n, m;
    cin >> n >> m;

    deque<bool> prime(m+1, 1);
    prime[0] = 0;

    for (unsigned int i = 1; i <= m; ++i) {
        if (i == 1) prime[1] = 0;
        else if (prime[i] && !is_prime(i))
            for (unsigned int j = i; j <= m; j *= 2)
                prime[j] = 0;
    }
    
    for (unsigned int i = n; i <= m; ++i)
        if (prime[i])
            cout << i << '\n';    
}