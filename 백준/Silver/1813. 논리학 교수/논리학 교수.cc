#include <iostream>
#include <vector>

using namespace std;

int main() {
    short n;
    cin >> n;
    
    vector<short> array(n+1, 0);
    for (short i = 0; i < n; ++i) {
        short m;
        cin >> m;
        ++array[m];
    }

    for (short i = n; i >= 0; --i)
        if (i == array[i]) {
            cout << i;
            return 0;
        }

    cout << -1;
}