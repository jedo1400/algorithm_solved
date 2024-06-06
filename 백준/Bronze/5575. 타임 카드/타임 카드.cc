#include <iostream>

using namespace std;

struct work {
    short sh, sm, ss
        , eh, em, es;
};

int time_to_sec(const short &h, const short &m, const short &s) {
    return (int)h*3600 + m*60 + s;
}

int main() {
    work work;
    
    for (short i = 0; i < 3; ++i) {
        cin >> work.sh >> work.sm >> work.ss >> work.eh >> work.em >> work.es;
        int sec = time_to_sec(work.eh, work.em, work.es) - time_to_sec(work.sh, work.sm, work.ss);

        cout << sec/3600 << ' ';
        sec %= 3600;
        cout << sec/60 << ' ';
        sec %= 60;
        cout << sec << '\n';
    }
}