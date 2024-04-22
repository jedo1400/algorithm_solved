#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int sangsunize(string input) {
    short result = 0;
    for (short i = input.size()-1; i >= 0; --i)
        result += ((short)input[i]-48) * pow(10, i);
    return result;
}

int main() {
    string a, b;
    int c, d;
    cin >> a >> b;
    if ((c = sangsunize(a)) > (d = sangsunize(b)))
        cout << c;
    else
        cout << d;
}