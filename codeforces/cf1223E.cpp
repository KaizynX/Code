#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 5e5+7;

int q, k, n, tot;
int v[N<<1], w[N<<1], fir[N], nex[N<<1];
typedef pair<long long, long long> pll;

inline void add_edge(int x, int y, int z)
{
    v[++tot] = y; w[tot] = z; nex[tot] = fir[x]; fir[x] = tot;
}

inline void init()
{
    tot = 0;
    for (int i = 1; i <= n; ++i) fir[i] = 0;
}

inline bool cmp(pll &a, pll &b)
{
    return a.first-a.second > b.first-b.second;
}

// k-1, k
inline pll tree_dp(int cur, int last)
{
    long long sum = 0;
    vector<pll> vec;
    for (int i = fir[cur]; i; i = nex[i]) {
        if (v[i] == last) continue;
        pll tmp = tree_dp(v[i], cur);
        tmp.first += w[i];
        if (tmp.first <= tmp.second) {
            sum += tmp.second;
        } else {
            vec.push_back(tmp);
        }
    }
    pll res = { sum, sum };
    sort(vec.begin(), vec.end(), cmp);
    // reverse(vec.begin(), vec.end());
    for (int i = 0; i < (int)vec.size(); ++i) {
        res.first += (i < k-1 ? vec[i].first : vec[i].second);
        res.second += (i < k ? vec[i].first : vec[i].second);
    }
#ifdef DEBUG
    printf("%d : %I64d %I64d\n", cur, res.first, res.second);
#endif
    return res;
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &n, &k);
        init();
        for (int i = 1, x, y, z; i < n; ++i) {
            scanf("%d %d %d", &x, &y, &z);
            add_edge(x, y, z);
            add_edge(y, x, z);
        }
        pll res = tree_dp(1, 0);
        printf("%I64d\n", max(res.first, res.second));
    }
    return 0;
}
