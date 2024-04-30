#include <iostream>

using namespace std;

int main() {
    int man = 0, min = 0, score;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 4; ++j) {
            cin >> score;
            (!i ? min : man) += score;
        }
    cout << (man > min ? man : min); 
}