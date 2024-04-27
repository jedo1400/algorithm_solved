#include <cstdio>

int main() {
    short k, d, a;
    scanf("%hd/%hd/%hd", &k, &d, &a);
    printf(k+a < d || !d ? "hasu" : "gosu");
}