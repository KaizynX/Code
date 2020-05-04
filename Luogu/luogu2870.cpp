/*
 * @Author: Kaizyn
 * @Date: 2020-05-03 14:16:19
 * @LastEditTime: 2020-05-03 14:24:49
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
char s[N];
int sa[N], rk[N<<1], oldrk[N<<1], id[N], px[N], cnt[N];
// s start from 1
inline void SA(const char *s) {
#define cmp(x, y, w) oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w]
    int n = strlen(s + 1), m = 256;
    for (int i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n; i; --i) sa[cnt[rk[i]]--] = i;
    for (int w = 1, p, i; w < n; w <<= 1, m = p) {
        for (p = 0, i = n; i > n - w; --i) id[++p] = i;
        for (int i = 1; i <= n; ++i)
            if (sa[i] > w)
                id[++p] = sa[i] - w;
        memset(cnt, 0, sizeof(int) * (m + 1));
        for (int i = 1; i <= n; ++i) ++cnt[px[i] = rk[id[i]]];
        for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (int i = n; i; --i) sa[cnt[px[i]]--] = id[i];
        memcpy(oldrk + 1, rk + 1, sizeof(int) * n);
        for (p = 0, i = 1; i <= n; ++i) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    }
#undef cmp
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[2*n-i+1] = s[i];
    }
    s[2*n+1] = '\0';
    SA(s);
    int l = 1, r = n, t = 0;
    while (l <= r) {
        if (rk[l] <= rk[2*n-r+1]) {
            cout << s[l++];
        } else {
            cout << s[r--];
        }
        if (++t == 80) {
            cout << endl;
            t = 0;
        }
    }
    return 0;
}