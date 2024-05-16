#include <iostream>

using namespace std;

int main() {
    bool WB_Board[8][8] = {0,}, BW_Board[8][8] = {0,};
    for (short i = 0; i < 8; ++i) // initialize
        for (short j = 0; j < 8; ++j)
            if ((i+1) % 2 == 0)
                if ((j+1) % 2 == 0) BW_Board[i][j] = 1;
                else                WB_Board[i][j] = 1;
            else
                if ((j+1) % 2 == 0) WB_Board[i][j] = 1;
                else                BW_Board[i][j] = 1;

    short n, m, smallest[2] = {64, 64}; // 8*8, WB -> BW
    char temp;
    bool board[50][50] = {0,};
    cin >> n >> m;

    for (short i = 0; i < n; ++i)
        for (short j = 0; j < m; ++j) {
            cin >> temp;
            if (temp == 'B') board[i][j] = 1;
        }
    
    for (short i = 0; i <= n-8; ++i)
        for (short j = 0; j <= m-8; ++j) {
            short WB_Diff = 0, BW_Diff = 0;
            for (short k = i; k < i+8; ++k)
                for (short l = j; l < j+8; ++l)
                    if (WB_Board[k-i][l-j] != board[k][l]) WB_Diff++;
                    else BW_Diff++;
            if (WB_Diff < smallest[0]) smallest[0] = WB_Diff;
            if (BW_Diff < smallest[1]) smallest[1] = BW_Diff;
        }
    cout << (smallest[0] < smallest[1] ? smallest[0] : smallest[1]);
}