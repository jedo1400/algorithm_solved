#include <iostream>
#include <stdlib.h>
#include <utility>
#include <deque>

using namespace std;

class snake {
private:
    deque<deque<bool>> apple;
    deque<pair<short, char>> move;

    deque<deque<bool>> body_map;
    deque<pair<short, short>> body_pos;

    short direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    short board_size
        , x = 1, y = 1, cur_direction{} // direction[0]부터
        , tick{};

    void turnDirection(const char&);
    bool moveSnake();

public:
    snake(short n) {
        board_size = n;
        for (short i = 0; i <= board_size; ++i) {
            apple.push_back(deque<bool>(board_size+1,0));
            body_map.push_back(deque<bool>(board_size+1,0));
        }
        body_pos.push_front(make_pair(1, 1));
        body_map[1][1] = 1;
    }

    void addApple(const short&, const short&);
    void addMove(const short&, const char&);
    void drawBoard();
    short doGame();
};

void snake::drawBoard() {
    for (short i = 1; i <= board_size; ++i) {
        for (short j = 1; j <= board_size; ++j) {
            if (apple[i][j]) {
                cout << 2;
                continue;
            }
            cout << body_map[i][j];
        }
        cout << '\n';
    }
}

bool snake::moveSnake() { // 0 = 게임이 계속됨, 1 = 끝남
    x += direction[cur_direction][0], y += direction[cur_direction][1];

    if (!y || !x || y > board_size || x > board_size || body_map[y][x]) {// 만약 이동한 좌표가 공허거나 몸인 경우
        x -= direction[cur_direction][0], y -= direction[cur_direction][1]; // undo
        return 1;
    }

    body_map[y][x] = 1;
    body_pos.push_front(make_pair(x, y));

    if (apple[y][x]) // 만약 이동한 칸에 사과가 있는 경우
        apple[y][x] = 0;
    else {
        pair<short, short> tail = body_pos.back();
        body_map[tail.second][tail.first] = 0; // 꼬리 자르기
        body_pos.pop_back();
    }
    return 0;
}

void snake::turnDirection(const char &c) {
    if (c == 'L')
        cur_direction = (cur_direction + 3) % 4;
    else
        cur_direction = (cur_direction + 1) % 4;
}

void snake::addApple(const short &x, const short &y) {
    apple[y][x] = 1;
}

void snake::addMove(const short& t, const char& d) {
    move.push_back(make_pair(t, d));
}

short snake::doGame() {
    while (!moveSnake()) {
        ++tick;
        pair<short, char> next_move = move.front();
        if (next_move.first == tick) {
            turnDirection(next_move.second);
            move.pop_front();
        }
    }
    return tick;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, k, l; // 보드의 크기(정사각형), 사과의 개수
    cin >> n >> k;
    snake game(n);
    
    while (k--) {
        short x, y;
        cin >> y >> x;
        game.addApple(x, y);
    }

    cin >> l;
    while (l--) {
        short tick;
        char direction;
        cin >> tick >> direction;
        game.addMove(tick, direction);
    }
    
    cout << game.doGame()+1;
}