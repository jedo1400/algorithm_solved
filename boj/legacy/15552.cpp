#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    short* result = new short[t]{};
    short temp;

    for (int i = 0; i < t; ++i)
        for (short j = 0; j < 2; ++j) {
            cin >> temp;
            result[i] += temp;
        }
    for (int i = 0; i < t; ++i)
        cout << result[i] << "\n";
}