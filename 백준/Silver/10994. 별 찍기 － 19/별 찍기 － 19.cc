#include <iostream>
#include <vector>

using namespace std;

void draw(vector<vector<short>> &array, short pos = 0) {
    static short border = array.size()/2 + (array.size() % 2 ? 1 : 0);

    if (pos >= border) 
        return;
    
    for (short i = pos; i < array.size()-pos; ++i)
        array[pos][i] = 1
        , array[i][pos] = 1
        , array[array.size()-pos-1][i] = 1
        , array[i][array.size()-pos-1] = 1;

    draw(array, pos+2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;
    vector<vector<short>> star(n*4-3, vector<short>(n*4-3, 0));

    draw(star);
    for (short i{}; i < star.size(); ++i) {
        for (short j{}; j < star.size(); ++j)
            cout << (star[i][j] ? '*' : ' ');
        cout << '\n';
    }
}