/*
 * @Author: Kaizyn
 * @Date: 2020-03-19 23:08:26
 * @LastEditTime: 2020-03-20 00:25:49
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

inline int manacher(const char *str, char *buf, int *p)
{
    int str_len = strlen(str), buf_len = 2;
    buf[0] = buf[1] = '#';
    for(int i = 0; i < str_len; ++i)
        buf[buf_len++] = str[i], buf[buf_len++] = '#';
 
    int mx = 0, id, ans = 0;
    for(int i = 1; i < buf_len; ++i)
    {
        if(i <= mx) p[i] = min(p[id*2-i], mx-i);
        else p[i] = 1;
        while(buf[i-p[i]] == buf[i+p[i]]) p[i]++;
        if(i+p[i] > mx) mx = i+p[i], id = i;
        ans = max(ans, p[i]-1);
    }
    return ans;
}

int n;
int p[N];
char s[N], buf[N];

inline bool check(int l, int r)
{
    // l *= 2; r *= 2;
    // int mid = (l+r)/2;
    return p[l+r]-1 >= r-l+1;
}

inline void solve()
{
    // cin >> s;
    // n = s.size();
    // manacher(s.c_str(), buf, p);
    scanf("%s", s);
    n = strlen(s);
    manacher(s, buf, p);
    if (check(1, n)) { printf("%s\n", s); return; }
    #ifdef DEBUG
    for (int i = 0; i <= n*2+1; ++i)
        cout << i << " \n"[i==n*2+1];
    for (int i = 0; i <= n*2+1; ++i)
        cout << buf[i] << " \n"[i==n*2+1];
    for (int i = 0; i <= n*2+1; ++i)
        cout << p[i] << " \n"[i==n*2+1];
    #endif
    int resi, resj, res = 0;
    // prefix or suffix
    for (int i = 1; i <= n; ++i) {
        if (check(1, i) && i > res) {
            res = i;
            resi = i;
            resj = n+1;
        }
        if (check(i, n) && n-i+1 > res) {
            res = n-i+1;
            resi = 0;
            resj = i;
        }
    }
    // prefix + suffix
    int l = 0, r = n+1;
    while (l+1 <= r-1 && s[l+1-1] == s[r-1-1]) ++l, --r;
    // s[1,l] === s[r, n]
    for (int i = l+1; i < r; ++i) {
        if (check(l+1, i) && i+l > res) {
            res = i+l;
            resi = i;
            resj = r;
        }
        if (check(i, r-1) && l+n-i+1 > res) {
            res = l+n-i+1;
            resi = l;
            resj = i;
        }
    }

    // string str;
    // for (int i = 1; i <= resi; ++i) str += s[i-1];
    // for (int i = resj; i <= n; ++i) str += s[i-1];
    // cout << str << endl;
    // cout << s.substr(0, resi)+s.substr(resj-1) << endl;
    for (int i = 1; i <= resi; ++i) putchar(s[i-1]);
    for (int i = resj; i <= n; ++i) putchar(s[i-1]);
    putchar('\n');
}

signed main()
{
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    scanf("%d", &T);
    // cin >> T;
    while (T--) solve();
    return 0;
}