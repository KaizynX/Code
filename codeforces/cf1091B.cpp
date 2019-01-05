#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;

int n, tot;
int x[Maxn], y[Maxn], a[Maxn], b[Maxn];
int vis[Maxn];

struct Node
{
    int i, j;
    pair<int, int> v;
    Node(){}
    Node(int i, int j, int x, int y):i(i), j(j) { v = make_pair(x, y); }
    bool operator < (const Node &b) const { return v < b.v; }
} c[Maxn*Maxn];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            c[++tot] = Node(i, j, x[i]+a[j], y[i]+b[j]);
    sort(c+1, c+tot+1);
    int cur = 1;
    return 0;
}
