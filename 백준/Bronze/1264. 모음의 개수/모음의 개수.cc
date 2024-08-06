#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string in, vowel = "aeiouAEIOU";
    while (1) {
        getline(cin, in);
        if (in == "#") break;
        
        short cnt{};
        for (auto &i : in)
            for (auto &j : vowel)
                if (i == j) {
                    ++cnt;
                    break;
                }
        
        cout << cnt << '\n';
    }
}