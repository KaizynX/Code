#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 12;
const int T = 10;
const int INF = 1e3;

int l, r, mid;
int n[N], v[N], a[N];
vector<int> tmp, id[N];
vector<vector<int>> c;

void build(int s, int last)
{
    int flag = 1;
    for (int i = last; i < N; ++i) {
        if (s&(1<<i)) {
            flag = 0;
            tmp.push_back(i);
            build(s&a[i], i+1);
            tmp.pop_back();
        }
    }
    if (flag && tmp.size() >= 4) {
        c.push_back(tmp);
    }
}

inline void init()
{
    for (int i = 0; i < N; ++i) {
        a[i] = (1<<N)-1;
        a[i] ^= 1<<i;
        if (i%3 == 2) {
            a[i] ^= 1<<((i+3)%N);
            a[i] ^= 1<<((i+3-1)%N);
            a[i] ^= 1<<((i+6-1)%N);
            a[i] ^= 1<<((i+6-2)%N);
            a[i] ^= 1<<((i+9)%N);
            a[i] ^= 1<<((i+9-1)%N);
        } else if (i%3 == 0) {
            a[i] ^= 1<<((i+9+1)%N);
            a[i] ^= 1<<((i+6+2)%N);
        } else if (i%3 == 1) {
            a[i] ^= 1<<((i+3)%N);
            a[i] ^= 1<<((i+3-1)%N);
            a[i] ^= 1<<((i+3+1)%N);
            a[i] ^= 1<<((i+6+1)%N);
            a[i] ^= 1<<((i+9)%N);
            a[i] ^= 1<<((i+9+1)%N);
        }
    }
    build((1<<N)-1, 0);
}

void brute(int t, int last)
{
    if (t >= T) {
        int res = 0;
        for (int i = 0; i < N; ++i) res = max(res, n[i]);
        return res <= mid;
    }

    int mx = 0;
    for (int i = 0; i < N; ++i) {
        if (n[i]-v[i]*(T-t) > mid)
            return false;
        if (n[i] > n[mx]) mx = i;
    }

    for (int i = last; i < (int)c.size(); ++i) {
        for (int j : c[i]) n[j] -= v[j];
        brute(t+1, i);
        for (int j : c[i]) n[j] += v[j];
    }
}

int main()
{
    init();
    for (int i = 0; i < N; ++i) cin >> n[i], r = max(r, n[i]);
    for (int i = 0; i < N; ++i) cin >> v[i];
    while (l < r) {
        mid = (l+r)>>1;
        if (dfs(0, 0)) r = mid;
        else l = mid+1;
    }
    cout << l << endl;
    return 0;
}
