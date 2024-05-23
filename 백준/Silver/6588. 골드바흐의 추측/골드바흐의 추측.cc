#include <iostream>
#include <string.h>

#define MAXIMUM 1000001

using namespace std;

bool isPrime(const int &n) {
    for (int i = 2; i*i <= n; ++i) 
        if (!(n % i))
            return 0;
    return 1;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool prime[MAXIMUM];
    memset(prime, 1, sizeof(bool)*MAXIMUM);
    for (int i = 3; i < MAXIMUM; i += 2) // 홀수 소수의 합이 필요하기 때문에
        if (prime[i] && !isPrime(i))
            for (int j = 1; i*j < MAXIMUM; ++j)
                prime[i*j] = 0;

    int n = 6;
    while (cin >> n && n) {
        bool solved = 0;
        for (int i = n-3; i > 2; i -= 2)
            if (prime[i] && prime[n-i]) {
                cout << n << " = " << n-i << " + " << i << '\n';
                solved = 1;
                break;
            }
        if (!solved)
            cout << "Goldbach's conjecture is wrong.\n";
    }
}