#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;

int n, m, num_fa;
int fa[kN], num[kN];
long long res, all_comb;

inline void init() {
    num_fa = n;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        num[i] = 1;
    }
}

int getf(int s) { return fa[s] == s ? s : fa[s] = getf(fa[s]); }

inline void connect(int x, int y)
{
    int fx = getf(x), fy = getf(y);
    if (fx == fy) return;

    long long sum_of_two = num[fx]+num[fy], comb_of_two = 1ll*num[fx]*num[fy],
              mul_x = 1ll*num[fx]*(n-num[fx]), mul_y = 1ll*num[fy]*(n-num[fy]),
              cnt = (all_comb - (mul_x + mul_y)*2 + comb_of_two*2)/2;
    all_comb -= comb_of_two*2;
    res -= cnt*comb_of_two;
    // connect to fx
    --num_fa;
    fa[fy] = fx;
    num[fx] += num[fy];
}

inline long long C(int n) // C_n^4
{
    int tmp[4] = { n, n-1, n-2, n-3 };
    if (n&1) {
        tmp[1] /= 2;
        tmp[3] /= 2;
    } else {
        tmp[0] /= 2;
        tmp[2] /= 2;
    }
    tmp[n%3] /= 3;
    for (int i = 0; i < 4; ++i)
        if (tmp[i]%2 == 0) {
            tmp[i] /= 2;
            break;
        }
    long long mul = 1;
    for (int i = 0; i < 4; ++i)
        mul *= tmp[i];
    return mul;
}

int main()
{
    scanf("%d%d", &n, &m);
    if (n < 4) {
        for (int i = 0; i <= m; ++i)
            printf("0\n");
        return 0;
    }
    res = C(n);
    all_comb = 1ll*n*(n-1);
    printf("%lld\n", res);
    init();
    for (int i = 1, x, y; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        if (num_fa >= 4) connect(x, y);
        printf("%lld\n", res);
    }
    return 0;
}
