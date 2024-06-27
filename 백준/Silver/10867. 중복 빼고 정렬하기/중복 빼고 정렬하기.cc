#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    set<int> array;

    for (int i = 0; i < n; ++i) {
        cin >> m;
        array.insert(m);
    }

    for (auto &i : array)
        cout << i << ' ';
}