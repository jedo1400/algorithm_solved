#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

int main() {
    short x, y, w, h, shortest = SHRT_MAX;
    cin >> x >> y >> w >> h;
    if (shortest > abs(w-x)) shortest = abs(w-x);
    if (shortest > abs(h-y)) shortest = abs(h-y);
    if (shortest > abs(0-x)) shortest = abs(0-x);
    if (shortest > abs(0-y)) shortest = abs(0-y);
    cout << shortest;
}