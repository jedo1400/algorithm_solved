#include <iostream>
#include <string>

using namespace std;

int main() {
    bool FBI = 0;
    string tmp;
    for (short i = 1; i <= 5; ++i) {
        cin >> tmp;
        if (tmp.find("FBI") != string::npos) {
            cout << i << ' ';
            FBI = 1;
        }
    }
    if (!FBI)
        cout << "HE GOT AWAY!";
}