#include <iostream>

using namespace std;

int main() {
    short n, m = -1;
    while (!cin.eof()) {    //EOF를 만날때까지 무한 입력
        if (m != -1)
            cout << m << endl;
        m = 0;
        for (short i = 0; i < 2; ++i) {
            cin >> n;
            m += n;
        }
    }
}