#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    string result;
    for (short i = 0; i < 50; ++i)
        result.append("z");

    for (int i = 1; i < str.length(); ++i)
        for (int j = 1; j < str.length(); ++j)
            if (i+j < str.length()) {
                string head_body_tail[3] = { str.substr(0, i), str.substr(i, str.length()-j-i), str.substr(str.length()-j) };

                for (short i = 0; i < 3; ++i)
                    reverse(head_body_tail[i].begin(), head_body_tail[i].end());
                
                string tmp = head_body_tail[0] + head_body_tail[1] + head_body_tail[2];

                if (tmp < result)
                    result = tmp;

            }

    cout << result;
}