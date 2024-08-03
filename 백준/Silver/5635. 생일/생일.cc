#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, d, m, y;
    int oldest_age = INT_MAX, youngest_age = INT_MIN;
    string name, oldest, youngest;

    cin >> n;

    for (short i = 0; i < n; ++i) {
        cin >> name >> d >> m >> y;
        int tmp = ((int)y*10000) + (m*100) + d;

        if (oldest_age > tmp) oldest = name, oldest_age = tmp;
        if (youngest_age < tmp) youngest = name, youngest_age = tmp;
    }
    
    cout << youngest << '\n' << oldest;
}