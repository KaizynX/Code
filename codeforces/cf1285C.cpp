#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const long long INF = 1e18;

long long x, a = INF, b = INF;
vector<long long> v;

void dfs(int cur, long long aa, long long bb)
{
    if (cur >= (int)v.size()) {
        if (max(aa, bb) < max(a, b)) {
            a = aa;
            b = bb;
        }
        return;
    }
    dfs(cur+1, aa, bb*v[cur]);
    dfs(cur+1, aa*v[cur], bb);
}

int main()
{
    cin >> x;
    for (long long i = 2; i*i <= x; ++i) {
        if (x%i) continue;
        long long k = 1;
        while (x%i == 0) x /= i, k *= i;
        v.emplace_back(k);
    }
    if (x > 1) v.emplace_back(x);
    dfs(0, 1, 1);
    cout << a << " " << b << endl;
    return 0;
}
