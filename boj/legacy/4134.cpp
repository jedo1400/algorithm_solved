#include <iostream>

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

    unsigned int n, tmp, j;
    cin >> n;
    for (unsigned int i = 0; i < n; ++i) {
        cin >> tmp;
        for (j = tmp; !is_prime(j); ++j)
            continue;
        cout << j << '\n';
    } 
}