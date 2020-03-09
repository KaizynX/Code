#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

struct Node
{
    int x, h;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.x < n2.x;
    }
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.x >> nd.h;
    }
} b[N];

int n, d, a;
int del[N], hhh[N];

inline int getpos(const long long &x)
{
    int l = 1, r = n;
    while (l < r) {
        int mid = (l+r)>>1;
        if (b[mid].x <= x) l = mid+1;
        else r = mid;
    }
    return b[l].x > x ? l : n+1;
}

inline void solve()
{
    cin >> n >> d >> a;
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    sort(b+1, b+n+1);
    long long res = 0;
    for (int i = 1, j = 1, now = 0, t, k; i <= n; ++i) {
        while (j <= i) now -= del[j++]*a;
        if (now >= b[i].h) continue;
        t = (b[i].h-now)/a+((b[i].h-now)%a != 0);
        res += t;
        now += t*a;
        del[getpos(1ll*b[i].x+d+d)] += t;
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}