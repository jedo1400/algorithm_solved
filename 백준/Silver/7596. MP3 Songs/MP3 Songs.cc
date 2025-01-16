#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt = 1;
    while (cin >> n && n) {
        cin.ignore();
        
        vector<string> array(n);
        for (auto &i : array)
            getline(cin, i);
        
        sort(array.begin(), array.end());

        cout << cnt++ << '\n';
        for (auto &i : array)
            cout << i << '\n';
    }
}