#include <bits/stdc++.h>

using namespace std;

const int kN = 1e2+7;
const int INF = 1e8;
typedef unsigned long long ull;

int T, n;
int a[kN];

int main()
{
    scanf("%d", &T);
    while (T--) {
        int flag = 0, res = INF;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            if (a[i]%10) {
                flag = 1;
            } else {
                a[i] /= 10;
            }
        }
        if (flag) {
            printf("-1\n");
            return 0;
        }
        ull init = 1, s1, s2, s5, g;
        for (int i2 = 0; i2 <= 8; ++i2) {
            s2 = init;
            for (int j = 1; j <= i2; ++j) s2 |= s2<<2;
            for (int i1 = 0; i1 <= 2; ++i1) {
                s1 = s2;
                for (int j = 1; j <= i1; ++j) s1 |= s1<<1;
                for (int i5 = 0, nows; i5 <= 2; ++i5) {
                    s5 = s1;
                    for (int j = 1; j <= i5; ++j) s5 |= s5<<5;
                    nows = 0;
                    for (int i = 1, nowi; i <= n; ++i) {
                        nowi = INF;
                        g = 1<<(a[i]%10);
                        if (s5&g) nowi = min(nowi, i2+i1+i5+a[i]/10);
                        for (int j = 1; j <= min(a[i]/10, 3); ++j) {
                            g <<= 10;
                            if (s5&g) nowi = min(nowi, i2+i1+i5+a[i]/10-j);
                        }
                        nows = max(nows, nowi);
                        if (nowi == INF) break;
                    }
#ifdef DEBUG
                    if (nows != INF)
                        printf("%d %d %d %d\n", i2, i1, i5, nows);
#endif
                    res = min(res, nows);
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
