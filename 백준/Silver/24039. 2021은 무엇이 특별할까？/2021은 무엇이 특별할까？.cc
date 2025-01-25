#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<bool> is_prime(5000, 1);
    vector<int> prime;
    is_prime[1] = 0;

    for (int i = 2; i <= 5000; ++i)
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = i*2; j <= 5000; j += i)
                is_prime[j] = 0;
        }
    
    int n;
    cin >> n;

    int i = 1;
    while (prime[i] * prime[i-1] <= n)
        ++i;

    cout << prime[i] * prime[i-1];
}