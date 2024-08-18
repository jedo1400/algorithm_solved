#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;

    vector<vector<short>> stu(n, vector<short>(5));
    for (short i = 0; i < n; ++i) //학생
        for (short j = 0; j < 5; ++j) //학년
            cin >> stu[i][j];
    
    short president = 1, mate = 0;
    for (short i = 0; i < n; ++i) { // 확인할 학생 
        short cnt = 0;
        bool* known = new bool[n]{};
        for (short j = 0; j < 5; ++j) // 학년 
            for (short k = 0; k < n; ++k) // 학생
                if (i != k && stu[i][j] == stu[k][j] && !known[k])
                    ++cnt, known[k] = true;
        if (cnt > mate)
            president = i+1, mate = cnt;
    }

    cout << president;    
}