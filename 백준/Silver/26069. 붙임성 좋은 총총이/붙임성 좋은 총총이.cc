#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    unordered_map<string, bool> rainbow_dance;
    rainbow_dance["ChongChong"] = 1;
    string tmp[2];
    short n, result = 0;

    cin >> n;

    for (short i = 0; i < n; ++i) {
        cin >> tmp[0] >> tmp[1];
        if (rainbow_dance[tmp[0]] || rainbow_dance[tmp[1]])
            rainbow_dance[tmp[0]] = 1, rainbow_dance[tmp[1]] = 1;
    }

    for (auto iter = rainbow_dance.begin(); iter != rainbow_dance.end(); ++iter)
        if (iter->second) ++result;

    cout << result;
}