#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool is_invalid{};
    bool visited[6][6]{0,};
    string pos[2], init_pos; // 이동 전[0], 후[1]
    cin >> pos[0]; // init
    visited[pos[0][1]-49][pos[0][0]-65] = 1
    , init_pos = pos[0];

    for (short i = 0; i < 35; ++i) {
        cin >> pos[1];

        bool *ptr = &visited[pos[1][1]-49][pos[1][0]-65];
        if (*ptr)
            is_invalid = 1;
        else
            *ptr = 1;

        short moved_w = abs(pos[1][0] - pos[0][0])
            , moved_h = abs(pos[1][1] - pos[0][1]);
        
        if (!(moved_w == 2 && moved_h == 1) && !(moved_w == 1 && moved_h == 2))
            is_invalid = 1;
        
        pos[0] = pos[1];
    }

    short moved_w = abs(init_pos[0] - pos[0][0])
        , moved_h = abs(init_pos[1] - pos[0][1]);
    if (!(moved_w == 2 && moved_h == 1) && !(moved_w == 1 && moved_h == 2))
        is_invalid = 1;

    cout << (is_invalid ? "Invalid" : "Valid");
}