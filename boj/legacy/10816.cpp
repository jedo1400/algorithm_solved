#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, temp;
    cin >> n;
    map<int, int> array;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        array[temp]++;
    }
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        cout << array[temp] << ' ';
    }
}