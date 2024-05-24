#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>

#define MAXIMUM 1003002 // https://www.acmicpc.net/board/view/129810 엣지 케이스 확인 잘해야함

using namespace std;

int intlen(const int &n) {
    int i, j;
    for (i = 1, j = 1; n / i > 9; i *= 10, ++j)
        continue;
    return j;
}

vector<short> intsplit(int n) {
    vector<short> result;
    for (int i = pow(10, intlen(n)-1); i > 0; i /= 10)
        result.push_back(n / i), n %= i;
    return result;
}

bool isPalindrome(const int &n) {
    if (intlen(n) == 1)
        return 1;
    vector<short> array = intsplit(n);
    for (short i = array.size()-1, j = 0; j < array.size()/2; --i, ++j)
        if (array[i] != array[j])
            return 0;
    return 1;
}

bool isPrime(const int &n) {
    for (int i = 2; i*i <= n; ++i)
        if (!(n % i))
            return 0;
    return 1;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool prime[MAXIMUM];
    memset(prime, 1, sizeof(bool)*MAXIMUM);
    prime[1] = 0; // https://www.acmicpc.net/board/view/111754 조심

    for (int i = 2; i < MAXIMUM; ++i)
        if (prime[i] && !isPrime(i))
            for (int j = 1; i*j < MAXIMUM; ++j)
                prime[i*j] = 0;

    int n, result;
    cin >> n;
    
    for (int i = n; i < MAXIMUM; ++i)
        if (prime[i] && isPalindrome(i)) {
            cout << i;
            break;
        }
}