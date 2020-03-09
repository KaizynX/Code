#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;

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
        int flag = 1;
        for (int i = 1, t = 0, l = m, r = m; i <= n; ++i) {
            int d = a[i].t-t;
            l -= d;
            r += d;
            if (l > a[i].r || r < a[i].l) { flag = 0; break; }
            l = max(l, a[i].l);
            r = min(r, a[i].r);
            t = a[i].t;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}

