#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s, p;
    cin >> s >> p;
    
    int ptr{}, result{};
    while (ptr < p.length()) {
        int skip{};

        for (int i{}; i < s.length(); ++i) {
            int j{};

            while (p[ptr+j] == s[i+j])
                ++j;

            skip = max(skip, j);
        }

        ptr += skip, ++result;
    }

    cout << result;
}