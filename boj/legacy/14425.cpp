#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, m, count = 0;
    string param;
    cin >> n >> m;
    map<string, bool> array;

    for (short i = 0; i < n; ++i) {
        cin >> param;
        array[param] = 1;
    }

    for (short i = 0; i < m; ++i) {
        cin >> param;
        if (array.count(param))
            count++;
    } cout << count;
}