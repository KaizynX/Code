#include <bits/stdc++.h>

using namespace std;

const int N = 5e4+7;

struct Node
{
    int sup, loy, abi, rep = -1;
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.sup >> nd.loy >> nd.abi;
    }
} a[N];

inline void solve()
{
    int n, q, x;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) cin >> a[i], a[i].rep = -1;
    for (int i = n-1, sup; i; --i) {
        sup = a[i].sup;
        if (a[i].abi < a[sup].abi) continue;
        if (a[sup].rep == -1 || a[i].loy > a[a[sup].rep].loy)
            a[sup].rep = i;
    }
    while (q--) {
        cin >> x;
        cout << a[x].rep << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
