/*
 * @Author: Kaizyn
 * @Date: 2020-03-17 15:19:46
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-17 15:38:23
 * @FilePath: \Code\atcoder\panasonic2020E_3.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e3+7;

char a[N], b[N], c[N];
bool buf[3][N<<2];
bool *ab = buf[0]+(N<<1), *ac = buf[1]+(N<<1), *bc = buf[2]+(N<<1);

bool cmp(const char &c1, const char &c2)
{
    return c1 == '?' || c2 == '?' || c1 == c2;
}

signed main()
{
    scanf("%s %s %s", a, b, c);
    int la = strlen(a), lb = strlen(b), lc = strlen(c), res = la+lb+lc;
    for (int i = 0; i < la; ++i) for (int j = 0; j < lb; ++j) ab[i-j] |= !cmp(a[i], b[j]);
    for (int i = 0; i < la; ++i) for (int j = 0; j < lc; ++j) ac[i-j] |= !cmp(a[i], c[j]);
    for (int i = 0; i < lb; ++i) for (int j = 0; j < lc; ++j) bc[i-j] |= !cmp(b[i], c[j]);
    for (int i = -(lb+lc); i <= la+max(lb, lc); ++i) {
        for (int j = -(lb+lc); j <= la+max(lb, lc); ++j) {
            if (!ab[i] && !ac[j] && !bc[j-i]) {
                int l = min({0, i, j}),
                    r = max({la, i+lb, j+lc});
                res = min(res, r-l);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}