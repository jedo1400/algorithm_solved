#include <iostream>
#include <vector>

using namespace std;

struct bridge {
    short west, east;
};

int main() {
    short biggest = 0;
    int t;
    cin >> t;

    bridge* tc = new bridge[t];

    for (int i = 0; i < t; ++i) {
        cin >> tc[i].west >> tc[i].east;
        ++tc[i].west, ++tc[i].east;
        if (tc[i].east > biggest)
            biggest = tc[i].east;
    }

    vector<vector<int>> pascal_triangle(biggest+2, vector<int>(biggest+2));

    for (short i = 1; i <= biggest; ++i)
        for (short j = 1; j <= i; ++j)
            if (j == 1 || j == i) pascal_triangle[i][j] = 1;
            else pascal_triangle[i][j] = pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j];

    for (int i = 0; i < t; ++i)
        cout << pascal_triangle[tc[i].east][tc[i].west] << '\n';
}