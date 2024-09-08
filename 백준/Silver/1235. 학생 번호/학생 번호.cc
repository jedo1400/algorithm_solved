#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;
    vector<string> students(n);

    for (auto &i : students) // 0~n-1
        cin >> i;
    
    const short len = students[0].length();
    short i;
    for (i = 0; i < len; ++i) { // 모든 학번의 길이가 같음

        bool flag = 0;
        for (short j = 0; j < n && !flag; ++j)
            for (short k = 0; k < n && !flag; ++k)
                if (j != k && students[j].substr(len-1-i) == students[k].substr(len-1-i))
                    flag = 1;
        
        if (!flag)
            break;
    }

    cout << i+1;
}