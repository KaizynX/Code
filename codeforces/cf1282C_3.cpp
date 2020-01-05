#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;

int testcase, n, m, T, t[2];
int d[N], cnt[2][N], num[2];

struct Node
{
    int dif, tim;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.tim < n2.tim;
    }
} a[N];

inline void discrete()
{
    d[n+1] = T+1;
    sort(d+1, d+n+2);
    m = unique(d+1, d+n+2)-d-1;
    for (int i = 1; i <= n; ++i)
        a[i].tim = lower_bound(d+1, d+m+1, a[i].tim)-d;
}

inline bool check(int i, int mid)
{
    long long now = 1ll*t[0]*i+1ll*t[1]*mid;
    if (now > T) return false;
    int pos = upper_bound(d+1, d+m+1, now)-d-1;
    // d[pos] <= now < d[pos+1]
    return i >= cnt[0][pos] && mid >= cnt[1][pos];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        cin >> n >> T >> t[0] >> t[1];
        // the number of problem a|b
        num[0] = num[1] = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i].dif, ++num[a[i].dif];
        for (int i = 1; i <= n; ++i) cin >> a[i].tim, d[i] = a[i].tim;
        discrete();
        sort(a+1, a+n+1);
        // cnt[][i] at time i , the number of probelm a|b you must write 
        int res = 0;
        for (int i = 0, j = 1; i < m; ++i) {
            if (i) {
                cnt[0][i] = cnt[0][i-1];
                cnt[1][i] = cnt[1][i-1];
                while (j <= n && a[j].tim == i) {
                    ++cnt[a[j].dif][i];
                    ++j;
                }
            }
            if (1ll*cnt[0][i]*t[0]+1ll*cnt[1][i]*t[1] >= d[i+1]) continue;
            int now = cnt[0][i]*t[0]+cnt[1][i]*t[1];
            int tmp = cnt[0][i]+cnt[1][i];
            int aaa = min((d[i+1]-now-1)/t[0], num[0]-cnt[0][i]);
            tmp += aaa;
            now += aaa*t[0];
            int bbb = min((d[i+1]-now-1)/t[1], num[1]-cnt[1][i]);
            tmp += bbb;
            res = max(res, tmp);
        }
        cout << res << endl;
    }
    return 0;
}

