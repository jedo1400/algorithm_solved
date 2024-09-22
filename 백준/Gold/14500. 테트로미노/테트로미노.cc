#include <iostream>
#include <vector>

using namespace std;

short max(short &a, short &b) {
    return a > b ? a : b;
}

class tetromino {
public:
    vector<vector<short>> board;

    tetromino(short width, short height) { // init
        w = width
        , h = height
        , board = vector<vector<short>> (h, vector<short>(w));
    }

    short solve();

private:
    vector<pair<short, short>> pattern;
    short w, h;

    void addPattern(initializer_list<initializer_list<short>>);
    short findBest();

    short placeStraight();
    short placeSquare();
    short placeL();
    short placeS();
    short placeT();
};

void tetromino::addPattern(initializer_list<initializer_list<short>> p) { // {[h, w], ...}
    for (auto &i : p) {
        bool isFirst = 1;
        short h, w;

        for (auto &j : i) {
            if (isFirst) h = j;
            else w = j;
            isFirst = 0;
        }

        pattern.push_back(make_pair(h, w));
    }
}

short tetromino::findBest() { // pair<h, w>

    // get border weight
    short w_border{}, h_border{};

    bool test[4][4] = {0,};

    for (auto &i : pattern) {
        test[i.first][i.second] = 1;
        if (i.first > h_border) h_border = i.first;
        if (i.second > w_border) w_border = i.second;
    }

    // bruteforce
    short best{};

    for (short i = 0; i < h - h_border; ++i)
        for (short j = 0; j < w - w_border; ++j) {
            short sum{};

            for (auto &k : pattern)
                sum += board[i+k.first][j+k.second];

            if (sum > best)
                best = sum;
        }

    pattern.clear();
    return best;
}

short tetromino::placeStraight() { // 1000*4
    short best{}, cmp;

    // standing
    this->addPattern({{0, 0}, {1, 0}, {2, 0}, {3, 0}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // lying
    this->addPattern({{0, 0}, {0, 1}, {0, 2}, {0, 3}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    return best;
}

short tetromino::placeSquare() {
    short result;

    this->addPattern({{0, 0}, {1, 0}, {0, 1}, {1, 1}});
    result = this->findBest();
    
    return result;
}

short tetromino::placeL() {
    short best{}, cmp;

    // default
    this->addPattern({{0, 0}, {1, 0}, {2, 0}, {2, 1}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // -90 
    this->addPattern({{1, 0}, {1, 1}, {1, 2}, {0, 2}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // -180
    this->addPattern({{0, 0}, {0, 1}, {1, 1}, {2, 1}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // -270
    this->addPattern({{1, 0}, {0, 0}, {0, 1}, {0, 2}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // symmetry
    this->addPattern({{0, 1}, {1, 1}, {2, 1}, {2, 0}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // (symmetry) 90
    this->addPattern({{0, 0}, {1, 0}, {1, 1}, {1, 2}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // (symmetry) 180
    this->addPattern({{0, 1}, {0, 0}, {1, 0}, {2, 0}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // (symmetry) 270
    this->addPattern({{0, 0}, {0, 1}, {0, 2}, {1, 2}}); // ㄱ
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    return best;
}

short tetromino::placeS() {
    short best{}, cmp;

    // default
    this->addPattern({{0, 0}, {1, 0}, {1, 1}, {2, 1}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // 90 
    this->addPattern({{1, 0}, {1, 1}, {0, 1}, {0, 2}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // symmetry
    this->addPattern({{0, 1}, {1, 1}, {1, 0}, {2, 0}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // symmetry(90)
    this->addPattern({{0, 0}, {0, 1}, {1, 1}, {1, 2}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    return best;
}

short tetromino::placeT() {
    short best{}, cmp;

    // default
    this->addPattern({{0, 0}, {0, 1}, {1, 1}, {0, 2}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // 90 
    this->addPattern({{1, 0}, {0, 1}, {1, 1}, {2, 1}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // flip
    this->addPattern({{0, 1}, {1, 0}, {1, 1}, {1, 2}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    // flip(90)
    this->addPattern({{0, 0}, {1, 0}, {2, 0}, {1, 1}});
    cmp = this->findBest();
    if (best < cmp) best = cmp;

    return best;
}

short tetromino::solve() {
    short largest{};

    largest = max(largest, this->placeStraight())
    , largest = max(largest, this->placeSquare())
    , largest = max(largest, this->placeL())
    , largest = max(largest, this->placeS())
    , largest = max(largest, this->placeT());

    return largest;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    short n, m;
    cin >> n >> m;
    tetromino tetro(m, n);

    for (short i = 0; i < n; ++i)
        for (short j = 0; j < m; ++j) {
            cin >> tetro.board[i][j];
        }

    cout << tetro.solve();
}
