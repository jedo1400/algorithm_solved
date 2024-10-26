#include <iostream>
#include <vector>

using namespace std;

void pasteArray(vector<vector<char>> &target, vector<vector<char>> &paste, const short &x, const short &y) {
    for (short i = 0; i < paste.size(); ++i)
        for (short j = 0; j < paste[0].size(); ++j)
            target[y+i][x+j] = paste[i][j];
}

void solve(vector<vector<char>> element, vector<vector<char>> &memo) {
    short w = element[0].size()
        , h = element.size();

    if (h >= 1<<10) { // n == 10
        memo = element;
        return;
    }

    vector<vector<char>> result(h*2, vector<char>(w*2, ' '));
    pasteArray(result, element, h, 0);
    pasteArray(result, element, 0, h);
    pasteArray(result, element, w, h);

    solve(result, memo);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<char>> element(2, vector<char>(4));
    element = { {' ', '/', '\\', ' '}
              , {'/', '_', '_', '\\'} };

    const short h = 1<<10
                , w = 1<<11;

    vector<vector<char>> memo(h, vector<char>(w));
    solve(element, memo);

    while (1) {
        short n;
        cin >> n;

        if (!n)
            break;
        
        short lw = 1<<n;

        for (short i = 0; i < lw; ++i) {
            for (short j = w/2-lw; j <= w/2+i; ++j)
                cout << memo[i][j];
            cout << '\n';
        }
        cout << '\n';
    }
}