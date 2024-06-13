#include <iostream>
// #include <limits.h>
#include <vector>

using namespace std;

struct dungchi {
    short x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;
    vector<dungchi> list(n);
    for (short i{}; i < n; ++i)
        cin >> list[i].x >> list[i].y;
    //     if (lx < list[i].x && ly < list[i].y)
    //         lx = list[i].x, ly = list[i].y;
    // }

    for (short i{}; i < n; ++i) {
        short rank = 1;
        for (short j{}; j < n; ++j)
            if (i != j && list[i].x < list[j].x && list[i].y < list[j].y)
                ++rank;
        cout << rank << ' ';
    }
}