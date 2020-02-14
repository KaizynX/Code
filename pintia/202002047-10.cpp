#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int l, r;
int vis[N];
map<int, int> mp;

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
        res += x%10*x%10;
        x /= 10;
    }
    return res;
}

inline int check(int x)
{
    mp.clear();
    while (x != 1) {
        if (mp.count(x)) return 0;
        mp[x] = 1;
        x = calc(x);
        if (x >= l && x <= r) return 0;
    }
    return mp.size();
}

int main()
{
    cin >> l >> r;
    int flag = 0;
    for (int i = l, tmp; i <= r; ++i) {
        tmp = check(i);
        if (tmp) cout << i << " " << (1+is_prime(i))*tmp << endl, flag = 1;
    }
    if (!flag) cout << "SAD" << endl;
    return 0;
}
