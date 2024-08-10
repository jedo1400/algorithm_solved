#include <iostream>
#include <string>
#include <vector>

using namespace std;

class paper {
public:
    string name;
    bool type[19];
    // bool* type;

    // paper(const short& n) {
    //     type = new bool[n-1];
    // }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, cnt = 1;

    while (1) {
        cin >> n;
        if (!n) break;

        paper *papers = new paper[n];
        bool flag{};

        for (short i = 0; i < n; ++i) {
            cin >> papers[i].name;
            for (short j = 0; j < n-1; ++j) {
                char tmp;
                cin >> tmp;
                papers[i].type[j] = (tmp == 'P' ? 0 : 1);
            }
        }

        cout << "Group " << cnt << '\n';
        for (short i = 0; i < n; ++i) {
            for (short j = 0; j < n-1; ++j)
                if (papers[i].type[j]) {
                    short index = i-(j+1);
                    if (index < 0)
                        index += n;
                    cout << papers[index].name << " was nasty about " << papers[i].name << '\n';
                    flag = true;
                }
        }
        
        if (!flag)
            cout << "Nobody was nasty\n";
        cout << '\n';
        delete[] papers;
        ++cnt;
    }
}