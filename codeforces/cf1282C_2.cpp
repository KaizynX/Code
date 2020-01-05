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
    d[n+1] = T;
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
        for (int i = 1, j = 1; i <= m; ++i) {
            cnt[0][i] = cnt[0][i-1];
            cnt[1][i] = cnt[1][i-1];
            while (j <= n && a[j].tim == i) {
                ++cnt[a[j].dif][i];
                ++j;
            }
        }
#ifdef DEBUG
        for (int i = 1; i <= m; ++i)
            printf("(%d %d) ", cnt[0][i], cnt[1][i]);
        putchar('\n');
#endif
        int res = 0;
        for (int i = 0; i <= num[0]; ++i) {
            int l = 0, r = num[1];
            while (l < r) {
                int mid = (l+r+1)>>1;
                if (check(i, mid)) l = mid;
                else r = mid-1;
            }
            if (check(i, l)) res = max(res, i+l);
        }
        cout << res << endl;
    }
    return 0;
}
