#include <iostream>
#include <deque>

using namespace std;

void shift(deque<bool> &gear, bool direction) { // 1 반시계, 0 시계
    if (direction) {
        bool tmp = gear[0];

        for (short i = 1; i < gear.size(); ++i)
            gear[i-1] = gear[i];

        gear[gear.size()-1] = tmp;
    }

    else {
        bool tmp = gear[gear.size()-1];

        for (short i = gear.size()-1; i; --i)
            gear[i] = gear[i-1];

        gear[0] = tmp;
    }
}

void rotate(deque<deque<bool>> &gear, short num, bool direction) {
    deque<bool> together(5, 0);
    for (short i = 1; i <= 3; ++i)
        together[i] = gear[i][2] ^ gear[i+1][6]; // 서로 기어 극성이 다르면

    together[4] = gear[4][6] ^ gear[3][2];

    bool flag_front{}, flag_back{}; // num으로부터 극성이 다른 톱니가 앞뒤 연속으로 이어져있는가
    shift(gear[num], direction);

    for (short i = 1; i <= 3; ++i) {
        direction = !direction;

        if (!flag_front && num-i >= 1 && together[num-i])
            shift(gear[num-i], direction);
        else flag_front = 1;

        if (!flag_back && num+i <= 4 && together[num+i-1])
            shift(gear[num+i], direction);
        else flag_back = 1;
    }
        
}

int main() {
    deque<deque<bool>> gear(5, deque<bool>(8, 0));
    for (short i = 1; i <= 4; ++i)
        for (short j = 0; j < 8; ++j) {
            char tmp;
            cin >> tmp;
            gear[i][j] = tmp-48;    
        }
    
    short k, score{};
    cin >> k;
    for (short i = 0; i < k; ++i) {
        short n, m; // 톱니바퀴 번호, 회전할 방향 (1 시계, -1 반시계)
        cin >> n >> m;
        rotate(gear, n, m == 1 ? 0 : 1);
    }

    for (short i = 1; i <= 4; ++i)
        if (gear[i][0])
            score += 1 << (i-1);

    cout << score;
}