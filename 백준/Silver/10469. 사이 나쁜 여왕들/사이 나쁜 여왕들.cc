#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int weight[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1} };
    int cnt{};
    bool board[8][8] = {0,};
    
    bool result = 1;
    for (int i{}; i < 8; ++i)
        for (int j{}; j < 8; ++j) {
            char c;
            cin >> c;

            if (c == '*') {
                ++cnt;

                if (board[i][j]) // 현재 위치로 다른 여왕이 이동 할 수 있는 경우
                    result = 0; 
                
                else {
                    board[i][j] = 1;
                    for (int k{}; k < 8; ++k) {
                        int moved_x = j+weight[k][0], moved_y = i+weight[k][1];
                        while (moved_x >= 0 && moved_x < 8 && moved_y >= 0 && moved_y < 8)
                            board[moved_y][moved_x] = 1, moved_x += weight[k][0], moved_y += weight[k][1];
                    }
                }
            }
        }

    cout << (result && cnt == 8 ? "valid" : "invalid");
}