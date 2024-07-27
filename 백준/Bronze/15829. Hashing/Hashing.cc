#include <iostream>
#include <string>

using namespace std;

const long long M = 1234567891;

unsigned long long getHash(const string &a) {
    unsigned long long result = 0;
    unsigned long long m = 1;

    for (short i = 0; i < a.length(); ++i) {
        result = (result + (a[i] - 96) * m) % M
        , m = (m*31) % M;
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    cout << getHash(a);
}
