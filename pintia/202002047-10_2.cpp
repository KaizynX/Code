#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int l, r;
int vis[N], res[N];
map<int, int> mp;
vector<int> v;

inline bool is_prime(const int &x)
{
    if (x < 2) return false;
    for (int i = 2; i*i <= x; ++i)
        if (x%i == 0) return false;
    return true;
}

inline int calc(int x)
{
    int res = 0;
    while (x) {
        res += (x%10)*(x%10);
        x /= 10;
    }
    return res;
}

inline int check(int x)
{
    mp.clear();
    v.clear();
    while (x != 1) {
        if (mp.count(x)) return 0;
        mp[x] = 1;
        v.emplace_back(x);
        x = calc(x);
    }
    for (unsigned i = 1; i < v.size(); ++i) vis[v[i]] = 1;
    return mp.size();
}

int main()
{
    cin >> l >> r;
    int flag = 0;
    for (int i = l; i <= r; ++i) {
        res[i] = (1+is_prime(i))*check(i);
    }
    for (int i = l; i <= r; ++i) {
        if (vis[i] || !res[i]) continue;
        cout << i << " " << res[i] << endl;
        flag = 1;
    }
    if (!flag) cout << "SAD" << endl;
    return 0;
}
