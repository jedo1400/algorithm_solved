#include <cstdio>
#include <cmath>

int main() {
    short n;
    scanf("%hd", &n);

    char f[4], r[5];
    
    for (short i = 0; i < n; ++i) {
        short worth[2]{0,};
        scanf("%3s-%4s", f, r);
        
        for (short j = 0; j < 3; ++j)
            worth[0] += (f[j]-65) * pow(26, 2-j);
    
        for (short j = 0; j < 4; ++j)
            worth[1] += (r[j]-48) * pow(10, 3-j);
        printf("%s\n", abs(worth[0]-worth[1]) <= 100 ? "nice" : "not nice");
    }
}
