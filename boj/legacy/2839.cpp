#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    short kg, _5kg_to_3kg = SHRT_MAX, smallest = SHRT_MAX;
    cin >> kg;
    if ((kg%5)%3 == 0)
        _5kg_to_3kg = (kg/5)+((kg%5)/3);
    else
        for (short i = kg/5; i >= 0; i--)
            for (short j = 0; i*5+j*3 <= kg; j++)
                if (i*5+j*3 == kg && smallest > i+j)
                    smallest = i+j;
    if (smallest != SHRT_MAX || _5kg_to_3kg != SHRT_MAX)
        cout << (_5kg_to_3kg > smallest ? smallest : _5kg_to_3kg);
    else
        cout << -1;
}