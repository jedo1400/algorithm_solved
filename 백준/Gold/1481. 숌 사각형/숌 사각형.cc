#include <iostream>

using namespace std;

int n, d
    , square[10][10]{0,}
    , row_mask[10]{0,}, col_mask[10]{0,};

void __fill(int r, int c, bool init = 1) {
    static bool complete = 0;
    if (init)
        complete = 0;
        
    if (c == n) {
        complete = 1;
        return;
    }
    
    for (int i = 0; i < d; ++i) {
        int num = 1 << i;

        if ((row_mask[r] | col_mask[c]) & num) continue;

        square[r][c] = i;
        row_mask[r] |= num;
        col_mask[c] |= num;
        
        __fill(r, c+1, 0);
        if (complete) return;

        row_mask[r] &= ~num;
        col_mask[c] &= ~num;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> d;

    for (int i = 0; i <= n-d; ++i)
        for (int j = n-d; j < n; ++j) {
                square[i][j]   = j-n+d
                , square[j][i] = j-n+d;

                int num = 1 << (j-n+d); // 0~n-1

                row_mask[j]   |= num
                , col_mask[j] |= num;
                
                // cout << row_mask[0] << ' ' << j-n+d << '\n';
            }
    
    for (int r = n-d+1; r < n; ++r)
        __fill(r, n-d+1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << square[i][j] << ' ';
        cout << '\n';
    }
}