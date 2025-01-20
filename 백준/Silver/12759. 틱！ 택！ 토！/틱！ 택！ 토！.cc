#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, board[3][3] = {0,};
    cin >> n;
    bool turn = n == 1 ? 0 : 1;

    for (int i{}; i < 9; ++i) {
        int x, y;
        cin >> y >> x;
        board[y-1][x-1] = turn+1, turn = !turn;

        for (int j{}; j < 3; ++j) { // 가로 세로
            int comp_x{}, comp_y{}
                , before_x = board[j][0], before_y = board[0][j];
            for (int k = 1; k < 3; ++k) {
                if (before_x == board[j][k])
                    ++comp_x;
                if (before_y == board[k][j])
                    ++comp_y;
            }

            if (before_x && comp_x == 2) {
                cout << before_x; return 0;
            }
            if (before_y && comp_y == 2) {
                cout << before_y; return 0;
            }
        }

        // 좌 -> 우 대각선
        if (board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[0][0]) {
            cout << board[0][0]; return 0;
        }
        
        // 우 -> 좌 대각선
        if (board[0][2] && board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == board[2][0]) {
            cout << board[0][2]; return 0;
        }
    }
    
    cout << 0;
}