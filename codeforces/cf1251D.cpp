#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const int INF = 1e9;

int t, n;
long long s;

struct Node
{
    int l, r;
    friend bool operator < (const Node &x, const Node &y) {
        return x.l < y.l;
    }
} a[N];

inline bool check(int mid)
{
    // get (n+1)/2 num >= mid
    int cnt = 0;
    long long ss = s;
    for (int i = n; i; --i) {
        if (cnt <= n/2 && a[i].r >= mid) {
            ss -= max(a[i].l, mid);
            if (ss < 0) return false;
            ++cnt;
        } else {
            ss -= a[i].l;
            if (ss < 0) return false;
        }
    }
    return cnt > n/2;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        int l = INF, r = 0, mid;
        scanf("%d%I64d", &n, &s);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &a[i].l, &a[i].r);
            l = min(l, a[i].l);
            r = max(r, a[i].r);
        }
        sort(a+1, a+n+1);
        while (l < r) {
            mid = (l+r+1)>>1;
            if (check(mid)) l = mid;
            else r = mid-1;
        }
        printf("%d\n", l);
    }
    return 0;
}
