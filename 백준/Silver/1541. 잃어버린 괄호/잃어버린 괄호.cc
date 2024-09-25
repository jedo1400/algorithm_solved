#include <iostream>
#include <string>

using namespace std;

int main() {
    string exp;
    cin >> exp;
    exp += '+';
    
    int result{}, tmp{};
    bool flag{};
    char opc_before = '+';
    string opr;
    for (auto &i : exp) {
        if (i >= 48)
            opr += i;
        else {
            if (i == '-') {
                if (flag) // - ~~ -
                    result += -1 * (tmp + stoi(opr)), tmp = 0;
                else // -
                    flag = 1, result += stoi(opr);
            }

            else {
                if (flag) // - ~~ +
                    tmp += stoi(opr);
                else
                    result += stoi(opr) * (opc_before == '-' ? -1 : 1);
            }

            opr.clear();
            opc_before = i;
        }
    }

    cout << result - tmp;
}
