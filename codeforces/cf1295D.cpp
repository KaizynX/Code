#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;

int T;
long long a, m;
vector<long long> v;
vector<pair<long long, int>> mul;

void dfs(int u, long long val, int cnt)
{
    if (u >= (int)v.size()) {
        mul.emplace_back(val, cnt);
        return;
    }
    dfs(u+1, val, cnt);
    dfs(u+1, val*v[u], cnt+1);
}

inline long long calc(long long x)
{
    long long res = 0;
    for (auto p : mul) {
        res += (p.second&1 ? -1 : 1)*x/p.first;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        v.clear();
        mul.clear();
        cin >> a >> m;
        long long g = __gcd(a, m);
        long long add = m/g-(m%g == 0); // add*g < m
        a /= g; m /= g;
        long long sz = a+add;
        for (long long i = 2; i*i <= m; ++i) {
            if (m%i) continue;
            v.emplace_back(i);
            while (m%i == 0) m /= i;
        }
        if (m > 1) v.emplace_back(m);
        dfs(0, 1, 0);
#ifdef DEBUG
        cout << g << " " << a << " " << sz << endl;
        for (auto p : mul) cout << "(" << p.first << ", " << p.second << ") ";
        cout << endl << calc(sz) << " " << calc(a-1) << endl;
#endif
        cout << calc(sz)-calc(a-1) << endl;
    }
    return 0;
}
