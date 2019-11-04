#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;
const int INF = 1e9;

int n, res;

struct Node
{
    int l, r;
    friend bool operator < (const Node &x, const Node &y) { return x.l < y.l; }
} a[N];


int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].l >> a[i].r;
    }
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    int rr = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i].r < a[rr].r) rr = i;
    }
    if (1 == rr) {
        for (int i = 2; i <= n; ++i) {
            res = max(res, a[i].r-a[i].l+1);
        }
        res += a[1].r-a[1].l+1;
        cout << res << endl;
        return 0;
    }
    int minr = a[1].r;
    for (int i = 2; i <= n; ++i) {
        if (i == rr) continue;
        res = max(res, max(0, a[rr].r-max(a[i].l, a[rr].l)+1)+max(0, minr-a[1].l+1));
        res = max(res, max(0, a[rr].r-a[1].l+1)+a[i].r-a[i].l+1);
        minr = min(minr, a[i].r);
    }
    res = max(res, max(0, minr-a[1].l+1)+a[rr].r-a[rr].l+1);
    cout << res << endl;
    return 0;
}
