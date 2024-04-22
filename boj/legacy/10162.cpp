#include <cstdio>

int main() {
    int sec, current_weight, index[3] = { 0, 0, 0 };
    scanf("%d", &sec);
    if (sec % 10 != 0) {
        printf("-1");
        return 0;
    } for (int i = 2; i >= 0; i--)
        while (sec >= (current_weight = (i == 0) ? 10 : ((i == 1) ? 60 : 300))) {
            sec -= current_weight;
            index[i]++;
        }
    printf("%d %d %d", index[2], index[1], index[0]);
    return 0;
}