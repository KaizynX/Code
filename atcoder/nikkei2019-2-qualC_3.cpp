#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, m;
int bb[N], d[N<<1], lb[N<<1], rb[N<<1];
map<int, set<int>> mp;

struct Node 
{
    int a, b;
} p[N];

inline bool cmpa(const Node &x, const Node &y) { return x.a < y.a; }
inline bool cmpb(const Node &x, const Node &y) { return x.b < y.b; }

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i].a, d[i] = p[i].a;
    for (int i = 1; i <= n; ++i) cin >> p[i].b, d[n+i] = p[i].b;
    sort(d+1, d+n*2+1);
    m = unique(d+1, d+n*2+1)-d-1;
    for (int i = 1; i <= n; ++i) {
        p[i].a = lower_bound(d+1, d+m+1, p[i].a)-d;
        p[i].b = lower_bound(d+1, d+m+1, p[i].b)-d;
    }
    for (int i = 1; i <= m; ++i) {
        lb[i] = m+1;
        rb[i] = 0;
    }
    sort(p+1, p+n+1, cmpb);
    for (int i = 1; i <= n; ++i) {
        bb[i] = p[i].b;
        mp[p[i].a].insert(i);
        lb[p[i].b] = min(lb[p[i].b], i);
        rb[p[i].b] = max(rb[p[i].b], i);
    }
    sort(p+1, p+n+1, cmpa);
    for (int i = 1; i <= n; ++i) {
        if (p[i].a > bb[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (p[i+1].a <= bb[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        auto &mmp = mp[p[i].a];
        auto tmp = mmp.lower_bound(lb[p[i].b]);
        if (tmp != mmp.end() && *tmp <= rb[p[i].b]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
