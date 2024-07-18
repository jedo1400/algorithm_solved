#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class board {
public:
    string pos_of_king
         , pos_of_rock;

    board(const string& king, const string& rock) { // init
        pos_of_king = king
        , pos_of_rock = rock;
    }

    void movePiece(const string&);
private:
    // bool selected_piece; // 0 = king, 1 = rock
    string calcPos(const short&, const short&, const bool&);
};

void board::movePiece(const string& movement) {
    short x_offset{}, y_offset{};

    if (movement == "R")    x_offset = 1;
    if (movement == "L")    x_offset = -1;
    if (movement == "B")    y_offset = -1;
    if (movement == "T")    y_offset = 1;
    if (movement == "RT")   x_offset = 1, y_offset = 1;
    if (movement == "LT")   x_offset = -1, y_offset = 1;
    if (movement == "RB")   x_offset = 1, y_offset = -1;
    if (movement == "LB")   x_offset = -1, y_offset = -1;

    string king_moved_pos = this->calcPos(x_offset, y_offset, 0)
         , rock_moved_pos = this->calcPos(x_offset, y_offset, 1);

    if (king_moved_pos == "out_of_board") return;

    else if (king_moved_pos == pos_of_rock) {
        if (king_moved_pos == rock_moved_pos || rock_moved_pos == "out_of_board")
            return;
        else
            pos_of_king = king_moved_pos
            , pos_of_rock = rock_moved_pos;
    }
    
    else
        pos_of_king = king_moved_pos;
}

string board::calcPos(const short& x_offset, const short& y_offset, const bool& type_of_piece) {
    string result;
    string* str_pos = &(type_of_piece ? pos_of_rock : pos_of_king);

    // char* pos = str_pos->data(); // string -> char*
    char* pos = new char[3];
    strcpy(pos, str_pos->c_str());

    pos[0] += x_offset, pos[1] += y_offset;

    if (pos[0] < 65 || pos[0] > 72 || pos[1] < 49 || pos[1] > 56)
        return "out_of_board";

    result.push_back((char)(pos[0]));
    result.push_back((char)(pos[1]));

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string king, rock;
    short n;
    cin >> king >> rock >> n;
    board board(king, rock);

    string direction;
    for (short i = 0; i < n; ++i) {
        cin >> direction;
        board.movePiece(direction);
    }

    cout << board.pos_of_king << '\n' << board.pos_of_rock;
}