#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;
const double err = 1e-9;
typedef pair<int, int> pii;

int testcase = 1;
int n, m;

struct Node
{
    int t, l, r;
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.t >> nd.l >> nd.r;
    }
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.t < n2.t;
    }
} a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        // sort(a+1, a+n+1);
        int flag = 1;
        long long ll = m, lr = m;
        for (int i = 1, j, lt = 0, nl, nr; i <= n; i = j) {
            nl = a[i].l; nr = a[i].r;
            for (j = i+1; j <= n && a[i].t == a[j].t; ++j) {
                nl = max(nl, a[i].l);
                nr = min(nr, a[i].r);
            }
            int d = a[i].t-lt;
            ll -= d;
            lr += d;
#ifdef DEBUG
            printf("[%lld %lld] [%d %d]\n", ll, lr, nl, nr);
#endif
            if (nl > nr || ll > nr || lr < nl) { flag = 0; break; }
            ll = max(ll, 1ll*nl);
            lr = min(lr, 1ll*nr);
            lt = a[i].t;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}

