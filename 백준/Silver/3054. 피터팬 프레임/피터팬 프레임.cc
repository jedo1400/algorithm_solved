#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> frame(5);

void drawPeterPanFrame(const char &to_print, const short &print_border) {
    if (print_border == 1 || print_border == 3) {
        frame[0].append("..#..");
        frame[4].append("..#..");
    }
    else {
        frame[0].append(".#..");
        frame[4].append(".#..");
    }

    frame[1].append(".#.#");
    frame[2].append( {'#', '.', to_print, '.'} );
    frame[3].append(".#.#");

    if (print_border == 2 || print_border == 3) {
        frame[1].append(".");
        frame[2].append("#");
        frame[3].append(".");   
    }
}

void drawWendyFrame(const char &to_print, const short& offset) {
    frame[0].replace(offset, 5, "..*..");
    frame[1].replace(offset, 5, ".*.*.");
    frame[2].replace(offset, 5, {'*', '.', to_print, '.', '*'} );
    frame[3].replace(offset, 5, ".*.*.");
    frame[4].replace(offset, 5, "..*..");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    if (input.length() == 1)
        drawPeterPanFrame(input[0], 3);
    else
        for (short i = 0; i < input.length(); ++i) {
            if (!i)
                drawPeterPanFrame(input[i], 1);
            else if (i == input.length()-1)
                drawPeterPanFrame(input[i], 2);
            else
                drawPeterPanFrame(input[i], 0);
        }

    for (short i = 8; i <= frame[0].length()-5; i += 12)
        drawWendyFrame(frame[2][i+2], i);

    for (short i = 0; i < 5; ++i) {
        for (auto &i : frame[i])
            cout << i;
        cout << '\n';
    }
}
