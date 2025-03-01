#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void decrypt(string &str) {
    int size = sqrt(str.length());
    vector<vector<char>> w(size, vector<char>(size));
    string result;

    int ptr{};
    for (auto &i : w)
        for (auto &j : i)
            j = str[ptr++];
    
    for (int x = size-1; x >= 0; --x)
        for (int y = 0; y < size; ++y)
            result += (w[y][x]);
    
    str = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;
        
        decrypt(str);

        cout << str << '\n';
    }
}