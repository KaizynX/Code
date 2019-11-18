#include <bits/stdc++.h>

using namespace std;

int n, a, b, c, d;
map<int, int> aa, bb, cc, dd;

void f(int x, map<int, int> &mp)
{
    mp.clear();
    for (int i = 2, k; i*i <= x; ++i) {
        if (x%i) continue;
        for ( k = 0; x%i == 0; ++k, x /= i);
        mp.insert({i, k});
    }
    if (x > 1) mp.insert({x, 1});
}

int main()
{
    cin >> n;
    while (n--) {
        // gcd(x, a) = c
        // lcm(x, b) = d
        cin >> a >> c >> b >> d;
        f(a, aa); f(b, bb); f(c, cc); f(d, dd);
        int l, r, v;
        long long res = 1;
        for (auto p : dd) {
            v = p.first;
            l = cc[v];
            r = dd[v];
            if (bb[v] > dd[v] || aa[v] < cc[v]) { res = 0; break; }
            if (bb[v] < dd[v]) l = dd[v];
            if (aa[v] > cc[v]) r = cc[v];
            if (l > r) { res = 0; break; }
            res *= (r-l+1);
        }
        if (a%c || d%b || d%c) res = 0;
        cout << res << endl;
    }
    return 0;
}
