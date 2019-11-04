#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int INF = 1e9;

int n, res;
int bac[N];

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
        res = max(a[i].r-a[i].l+1, res);
    }
    sort(a+1, a+n+1);
    bac[n+1] = INF;
    for (int i = n; i; --i) {
        bac[i] = min(bac[i+1], a[i].r);
    }

    for (int i = 1, pre = INF; i < n; ++i) {
        pre = min(pre, a[i].r);
        int lef = max(0, pre-a[i].l+1),
            rig = max(0, bac[i+1]-a[n].l+1);
#ifdef DEBUG
        cout << lef << " " << rig << endl;
#endif
        res = max(res, lef+rig);
    }
    cout << res << endl;
    return 0;
}
