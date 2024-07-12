#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<short> array(1001);
    short i = 1, n = 1;
    while (i <= 1000) {
        short j;
        for (j = i; (j <= 1000) && (j < i + n); ++j)
            array[j] = n;
        i = j, ++n;
    }

    short a, b;
    unsigned short result = 0;
    cin >> a >> b;

    for (short i = a; i <= b; ++i)
        result += array[i];
    
    cout << result;
}