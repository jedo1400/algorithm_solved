#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, bool> array;
    int n, m, tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        array[tmp] = 1;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        cout << array[tmp] << '\n';
    }
}