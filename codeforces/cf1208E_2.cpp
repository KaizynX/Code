#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+7;
const int INF = 1e9;

int n, w, l;
int pre[MAXN], nex[MAXN], cnt[MAXN];
long long col[MAXN];

struct Node
{
    int v, i, d;
} a[MAXN];

inline bool cmpv(const Node &x, const Node &y) { return x.v < y.v; }
inline bool cmpi(const Node &x, const Node &y) { return x.i < y.i; }

inline void insert(int x)
{
    ;
}

int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> l;
        for (int j = 1; j <= l; ++j) {
            cin >> a[j].v;
            a[j].i = j;
        }
        sort(a.begin(), a.end(), cmpv);
        a[1].d = 1;
        for (int j = 2; j <= l; ++j) {
            a[i].d = (a[i].v == a[i-1].v ? a[i-1].d : a[i-1].d+1);
        }
        sort(a.begin(), a.end(), cmpi);
        for (int j = 1; j <= w; ++j) {
            int st = max(1, j-(w-l)), ed = min(l, j);
            if (j-(w-l) < 1 || j > l) tmp = max(tmp, 0);
            col[j] += tmp;
        }
    }
    for (int i = 1; i <= w; ++i) {
        cout << col[i] << " ";
    }
    cout << endl;
    return 0;
}
