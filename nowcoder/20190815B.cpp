#include <bits/stdc++.h>

using namespace std;

const int P = 1e9+7;

int b, c, lim, T;

int main()
{
    scanf("%d%d", &T, &lim);
    while (T--) {
    scanf("%d%d", &b, &c);
    for (int x = 0; x < lim; ++x)
        for (int y = 0; y < lim; ++y) {
            if ((x+y)%P == b && 1ll*x*y%P == c) {
                printf("%d %d\n", x, y);
                break;
            }
        }
    }
    return 0;
}
