#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    return a % b ? gcd(b, a % b) : b;
}

int main() {
    int ratio[2][2];
    int divide_to, result[2];
    for (short i = 0; i < 2; ++i)
        cin >> ratio[i][0] >> ratio[i][1];
    result[0] = ratio[0][0] * ratio[1][1] + ratio[0][1] * ratio[1][0]
    , result[1] = ratio[0][1] * ratio[1][1]
    , divide_to = gcd(result[0], result[1]);
    cout << result[0]/divide_to << ' ' << result[1]/divide_to;
}