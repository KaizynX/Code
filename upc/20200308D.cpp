/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 18:40:03
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 18:54:11
 * @FilePath: \Code\upc\20200308D.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

inline void GetNext(char *s, int *_nex)
{
    int len = strlen(s);
    int a = 0, p = 0;
    _nex[0] = len;
    for (int i = 1; i < len; ++i) {
        if (i >= p || i+_nex[i-a] >= p) {
            if (i > p) p = i;
            while (p < len && s[p] == s[p-i]) ++p;
            a = i;
            _nex[i] = p-i;
        } else {
            _nex[i] = _nex[i-a];
        }
    }
}

int n;
char s[N];
int nex[N], vis[N];

inline bool check(const int &x)
{
    for (int i = x, j = nex[x-1], now = 0; i <= n; i += x) {
        now += j;
        if (nex[i-1] != now) return false;
    }
    return true;
}

inline void solve()
{
    scanf("%s", s);
    n = strlen(s);
    GetNext(s, nex);
    reverse(nex, nex+n);
    #ifdef DEBUG
    for (int i = 0; i < n; ++i) cout << nex[i] << " \n"[i==n-1];
    #endif
    for (int i = 1; i < n; ++i) {
        if (nex[i-1] == i && n%i == 0) {
            if (check(i)) {
                for (int j = 0; j < i; ++j) putchar(s[j]);
                putchar('\n');
                return;
            }
        }
    }
    puts("-1");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}