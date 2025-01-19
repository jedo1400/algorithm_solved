#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int w{}, h{};
    bool array[501][501] = {0,};

    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        w = max(w, max(x1, x2)), h = max(h, max(y1, y2));
        for (int i = y1; i < y2; ++i)
            for (int j = x1; j < x2; ++j)
                array[i][j] = 1;
    }

    int result{};
    for (int i{}; i < h; ++i)
        for (int j{}; j < w; ++j)
            if (array[i][j]) ++result;

    cout << result;
}