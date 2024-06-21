#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, m
        , pkg, one, cheapest[2] = { 1000, 1000 };
    int rst = INT_MAX;
    cin >> n >> m;

    for (short i = 0; i < m; ++i) {
        cin >> pkg >> one;
        if (pkg < cheapest[0]) cheapest[0] = pkg;
        if (one < cheapest[1]) cheapest[1] = one;
    }

    int a = (n/6*cheapest[0])+(n%6*cheapest[1])
        , b = (n/6+1)*cheapest[0]
        , c = n*cheapest[1];
    
    if (a < rst) rst = a;
    if (b < rst) rst = b;
    if (c < rst) rst = c;

    cout << rst;
}