#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

struct BinaryIndexedTree
{
    typedef int T;
    int n;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    void init(int sz) { n = sz; clear(); }
    void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} BIT;

struct Node
{
    int a, b, c, id, num;
    friend bool operator < (const Node &n1, const Node &n2) {
        if (n1.a != n2.a) return n1.a < n2.a;
        if (n1.b != n2.b) return n1.b < n2.b;
        return n1.c < n2.c;
    }
    friend bool operator == (const Node &n1, const Node &n2) {
        return n1.a == n2.a && n1.b == n2.b && n1.c == n2.c;
    }
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.a >> nd.b >> nd.c;
    }
} p[N], q[N], tmp[N];

int n, m, k;
int res[N];

void cdq(const int &l, const int &r)
{
    if (l >= r) return;
    int mid = (l+r)>>1;
    cdq(l, mid); cdq(mid+1, r);
    int i = l, j = mid+1;
    while (i <= mid && j <= r) {
        if (a[i])
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        p[i].id = i;
        p[i].num = 1;
    }
    sort(p+1, p+n+1);
    for (int i = 1; i <= n; ++i) {
        if (p[i] == p[i-1]) ++q[m].num;
        else q[++m] = p[i];
    }
    cdq(1, n);
    for (int i = 1, j = 0; i <= n; ++i) {
        if (p[i] == p[i-1]) res[p[i].id] = res[p[j].id];
        else ++j;
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " \n"[i==n];
    }
    return 0;
}