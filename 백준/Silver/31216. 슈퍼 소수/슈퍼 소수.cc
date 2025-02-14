#include <iostream>
#include <limits>
#include <vector>

#define MAX 318138

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool is_prime[MAX] = {0,};
    for (int i = 2; i < MAX; ++i) is_prime[i] = 1;

    for (int i = 2; i < MAX; ++i)
        if (is_prime[i])
            for (int j = i*2; j < MAX; j += i)
                is_prime[j] = 0;
    
    vector<int> prime;
    for (int i = 2; i < MAX; ++i)
        if (is_prime[i])
            prime.push_back(i);
    
    vector<int> super_prime;
    for (int i = 0; i < prime.size(); ++i)
        if (prime[i] && is_prime[i+1])
            super_prime.push_back(prime[i]);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << super_prime[n-1] << '\n';
    }
}