#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, h, w;
    char str[100] = {0,};
    cin >> n >> h >> w;
    vector<vector<char>> note(h, vector<char>(w*n));

    for (auto &i : note)
        for (auto &j : i)
            cin >> j;
    
    for (int i{}; i < w*n; i += w) {
        char current = '?';
        for (int j{}; j < h && current == '?'; ++j)
            for (int k = i; k < i+w && current == '?'; ++k)
                if (note[j][k] != '?')
                    current = note[j][k];
        str[i/w] = current;
    }

    cout << str;
}