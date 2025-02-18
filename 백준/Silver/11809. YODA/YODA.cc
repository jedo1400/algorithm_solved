#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    vector<int> r1, r2;
    cin >> a >> b;

    while (a && b) {
        if (a % 10 >= b % 10)
            r1.push_back(a % 10);
        if ( a % 10 <= b % 10)
            r2.push_back(b % 10);
        a /= 10, b /= 10;
    }

    while (a) {
        r1.push_back(a % 10);
        a /= 10;
    }
    
    while (b) {
        r2.push_back(b % 10);
        b /= 10;
    }

    int c{}, d{};
    for (int i = 0, j = 1; i < r1.size(); ++i, j *= 10) 
        c += r1[i] * j;
    
    for (int i = 0, j = 1; i < r2.size(); ++i, j *= 10)
        d += r2[i] * j;
    
    if (r1.empty()) cout << "YODA";
    else cout << c;

    cout << '\n';

    if (r2.empty()) cout << "YODA";
    else cout << d;
}