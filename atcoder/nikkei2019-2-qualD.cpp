#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

struct Node
{
    int l, r;
    long long c;
    friend bool operator < (const Node &x, const Node &y) {
        if (x.c != y.c) return x.c < y.c;
        return x.r > y.r;
    }
} a[N];

int n, m;
long long dis[N];
set<Node> s;

bool cmpl(const Node &x, const Node &y) { return x.l < y.l; }

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].c;
    }
    sort(a+1, a+m+1, cmpl);
    memset(dis, -1, sizeof dis);
    dis[1] = 0;
    for (int i = 1, p = 1; i <= n; ++i) {
        while (s.size() && s.begin()->r < i) s.erase(s.begin());
        if (i > 1) {
            if (s.empty()) break;
            dis[i] = s.begin()->c;
        }
        for ( ;p <= m && a[p].l <= i; ++p) {
            a[p].c += dis[i];
            while (s.size() && s.rbegin()->c >= a[p].c && s.rbegin()->r <= a[p].r)
                s.erase((--s.end()));
            if (s.size() && s.rbegin()-> c <= a[p].c && s.rbegin()->r >= a[p].r)
                continue;
            s.insert(a[p]);
        }
    }
    cout << dis[n] << endl;
    return 0;
}
