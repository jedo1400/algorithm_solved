#include <iostream>
#include <deque>

using namespace std;

void pasteArray(deque<deque<bool>> &target, deque<deque<bool>> &paste, const short &x, const short &y) {
    for (short i = 0; i < paste.size(); ++i)
        for (short j = 0; j < paste[0].size(); ++j)
            target[y+i][x+j] = paste[i][j];
}

void drawStar(const short &n, deque<deque<bool>> before) {
    short w = before[0].size() // w <= 3072
        , h = before.size(); // h <= 6143

    if (n == before.size()) {
        for (auto &i : before) {
            for (auto &j : i)
                cout << (j ? '*' : ' ');
            cout << '\n';
        }
        return;
    }

    deque<deque<bool>> result(h*2, deque<bool>((w+1)*2-1, 0));
    
    pasteArray(result, before, 0, h);
    pasteArray(result, before, w+1, h);
    pasteArray(result, before, w/2+1, 0);

    drawStar(n, result);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;

    deque<deque<bool>> element(3, deque<bool>(5));
    element = { {0, 0, 1, 0, 0}
              , {0, 1, 0, 1, 0}
              , {1, 1, 1, 1, 1} };

    drawStar(n, element);
}