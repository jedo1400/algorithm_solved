#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string param, param2;
    cin >> n;
    map<string, bool, greater<string>> array;

    for (int i = 0; i < n; ++i) {
        cin >> param >> param2;
        array[param] = param2 == "enter" ? 1 : 0;
    } 
    for (auto iter = array.begin(); iter != array.end(); ++iter)
        if (iter->second)
            cout << iter->first << '\n';
}