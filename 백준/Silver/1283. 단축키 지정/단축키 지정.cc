#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void highlight(string& str, const short idx) {
    str.replace(idx, 1, string("[") + str[idx] + ']');
}

bool hasAlphabet(const set<char> &sc, const char& c) {
    if (sc.find(c+(32 * (c >= 97 ? -1 : 1))) != sc.end())
        return 1;
    return (sc.find(c) != sc.end() ? 1 : 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;

    vector<string> array(n);
    set<char> sc;
    
    cin.ignore();
    for (short i = 0; i < n; ++i) {
        bool FLAG_OF_CONTINUE = false;
        getline(cin, array[i]);

        // 만약 첫 글자거나 이전 글자가 공백이며(단어의 시작이고) 사용되지 않았다면
        for (short j = 0; j < array[i].length(); ++j)
            if ((!j || array[i][j-1] == ' ') && !hasAlphabet(sc, array[i][j])) {
                sc.insert(array[i][j]);
                highlight(array[i], j);
                FLAG_OF_CONTINUE = true;
                break;
            }
        if (FLAG_OF_CONTINUE) continue;

        // 해당하지 않는 경우 순회해서 사용되지 않은 글자 찾기
        for (short j = 0; j < array[i].length(); ++j)
            if (!hasAlphabet(sc, array[i][j]) && array[i][j] != ' ') {
                sc.insert(array[i][j]);
                highlight(array[i], j);
                break;
            }
    }

    for (short i = 0; i < n; ++i)
        cout << array[i] << '\n';
}