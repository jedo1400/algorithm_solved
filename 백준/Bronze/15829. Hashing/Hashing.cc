#include <iostream>
#include <string>

using namespace std;

const int M = 1234567891;

long long getHash(const string &a) {
    long long result = 0, m = 1;

    for (short i = 0; i < a.length(); ++i) {
        result = (result + (a[i] - 96) * m) % M
        , m = (m%M)*31 ;
    }
    
    return result;
}

int main() {
    cin.ignore();
    string a;
    cin >> a;
    cout << getHash(a);
}