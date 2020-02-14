#include <bits/stdc++.h>

using namespace std;

int alpha, number;

int main()
{
    int x;
    while (scanf("%x", &x) == 1) {
        if (x >= 'a' && x <= 'z' || x >= 'A' && x <'Z') ++alpha;
        if (x >= '0' && x <= '9') ++number;
    }
    printf("%d %d\n", alpha, number);
    return 0;
}
