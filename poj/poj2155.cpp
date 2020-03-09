#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3+7;

template <typename T>
struct BIT_2D
{
    int n, m;
    T tr[N][N];
    BIT_2D() { memset(tr, 0, sizeof tr); }
    void init(const int &_n, const int &_m) {
        n = _n; m = _m;
        // memset(tr, 0, sizeof tr);
        for (int i = 1; i <= n; ++i)
            memset(tr[i], 0, sizeof(int)*(m+1));
    }
    void add(const int &x, const int &y, const T &k) {
        add(x, y, x, y, k);
    }
    void add(int r1, int c1, int r2, int c2, const T &k) {
        if (r1 > r2) swap(r1, r2);
        if (c1 > c2) swap(c1, c2);
        _add(r1, c1, k); _add(r2+1, c2+1, k);
        _add(r1, c2+1, -k); _add(r2+1, c1, -k);
    }
    T query(const int &x, const int &y) {
        T res = 0;
        for (int i = x; i; i -= i&-i)
            for (int j = y; j; j -= j&-j)
                res += tr[i][j];
        return res;
    }
    void _add(const int &x, const int &y, const T &k) {
        for (int i = x; i <= n; i += i&-i)
            for (int j = y; j <= m; j += j&-j)
                tr[i][j] += k;
    }
};

BIT_2D<int> BIT;

inline void solve()
{
    char op;
    int n, m, r1, c1, r2, c2;
    cin >> n >> m;
    BIT.init(n, n);
    while (m--) {
        cin >> op >> r1 >> c1;
        if (op == 'C') {
            cin >> r2 >> c2;
            BIT.add(r1, c1, r2, c2, 1);
        } else {
            cout << BIT.query(r1, c1)%2 << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve();
        if (i < T) cout << endl;
    }
    return 0;
}
