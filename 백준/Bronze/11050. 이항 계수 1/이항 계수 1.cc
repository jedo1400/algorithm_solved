#include <iostream>
#include <vector>

using namespace std;

int main() {
    short n, k;
    cin >> n >> k;
    ++n, ++k;
    
    vector<vector<int>> pascal_triangle(n+2, vector<int>(n+2));

    for (short i = 1; i <= n+1; ++i)
        for (short j = 1; j <= i; ++j)
            if (j == 1 || j == i) pascal_triangle[i][j] = 1;
            else pascal_triangle[i][j] = pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j];

    // for (short i = 1; i <= n+1; ++i) {
    //     for (short j = 1; j <= n+1; ++j)
    //         cout << pascal_triangle[i][j] << ' ';
    //     cout << endl;
    // }

    cout << pascal_triangle[n][k];
}