#include <iostream>
#include <deque>

using namespace std;

void fillZero(deque<deque<bool>> &array, short x_start
                                        , short y_start
                                        , short x_end
                                        , short y_end) {
    for (short i = y_start; i <= y_end; ++i)
        for (short j = x_start; j <= x_end; ++j)
            array[i][j] = 0;
    return;
}

void star(deque<deque<bool>> &array, short n, short m = 3) {
    if (n < m) return;

    short weight = m/3;
    for (short y = weight; y < array.size(); y += m)
        for (short x = weight; x < array.size(); x += m)
            fillZero(array, x, y, x+weight-1, y+weight-1);
    star(array, n, m*3);
}

int main() {
    short n;
    cin >> n;

    deque<deque<bool>> array(n, deque<bool>(n, 1));
    star(array, n);
    for (short i = 0; i < array.size(); ++i) {
        for (short j = 0; j < array[i].size(); ++j) {
            cout << (array[i][j] ? '*' : ' ');
        }
        cout << '\n';
    }
}