#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int idx{};
int r, c; // y, x

void split(int x, int y, int size) {
    if (x == c && y == r) {
        cout << idx;
        return;
    }

    int w = size/2;
    
    if (c < x+size && r < y+size && c >= x && r >= y) { // 사분탐색??
        split(x, y, w);
        split(x+w, y, w);
        split(x, y+w, w);
        split(x+w, y+w, w);
    } else
      idx += size*size;      
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    short n;
    cin >> n >> r >> c;

    split(0, 0, 1 << n);
}
