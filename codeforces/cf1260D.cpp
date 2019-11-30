#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const int INF = 1e9;

int n, m, k, t;
int a[N];

struct Node
{
    int l, r, d;
    friend bool operator < (const Node &x, const Node &y) {
        return x.l < y.l;
    }
    friend istream &operator >> (istream &is, Node &x) {
        return is >> x.l >> x.r >> x.d;
    }
} b[N];

inline bool check(int mid)
{
    int now = n+1;
    for (int i = 0, pb = 1, pp; i <= n; ++i) {
        pp = i;
        while (pb <= k && b[pb].l == i) {
            if (b[pb].d > a[mid]) pp = max(pp, b[pb].r);
            ++pb;
        }
        now += 2*(pp-i);
        if (now > t) return false;
    }
    return now <= t;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k >> t;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> b[i];
    }
    a[0] = INF;
    sort(a+1, a+m+1);
    reverse(a+1, a+m+1);
    sort(b+1, b+k+1);
    int l = 0, r = m;
    while (l < r) {
        int mid = (l+r+1)>>1;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l << endl;
    return 0;
}

