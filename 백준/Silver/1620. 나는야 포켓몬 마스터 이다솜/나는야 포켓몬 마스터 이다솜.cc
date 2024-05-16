#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string tmp;
    cin >> n >> m;
    map<string, int> array_rev;
    vector<string> array(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
        array_rev[array[i]] = i+1;
    }

    while (m--) {
        cin >> tmp;
        if (tmp[0] <= 57)
            cout << array[stoi(tmp)-1]; 
        else
            cout << array_rev[tmp];
        cout << '\n';
    }
}