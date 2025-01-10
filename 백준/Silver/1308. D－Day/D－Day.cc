#include <iostream>

using namespace std;

bool isYunnnyeon(int y) {
    return !(y % 4) && y % 100 || !(y % 400);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    struct date { int year, month, day; bool yunn_nyeon; };
    int cal[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    date before, after;

    cin >> before.year >> before.month >> before.day
        >> after.year >> after.month >> after.day;
    
    before.yunn_nyeon = isYunnnyeon(before.year)
    , after.yunn_nyeon = isYunnnyeon(after.year);

    int bt = before.day, at = after.day;
    for (int i = 1; i < before.year; ++i) bt += 365 + isYunnnyeon(i);
    for (int i = 1; i < after.year; ++i) at += 365 + isYunnnyeon(i);

    for (int i = 1; i < before.month; ++i) bt += cal[i] + (i == 2 && before.yunn_nyeon);
    for (int i = 1; i < after.month; ++i) at += cal[i] + (i == 2 && after.yunn_nyeon);

    if (after.year-before.year > 1000 || after.year-before.year >= 1000 && after.month >= before.month && after.day >= before.day)
        cout << "gg";
    else
        cout << "D-" << at-bt;
}