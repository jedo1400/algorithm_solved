#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, tmp;
    cin >> n;
    map<int, int> array;

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        array[tmp] = 1;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        if (array[tmp]) cout << 1;
        else cout << 0;
        cout << ' ';
    }

    
}