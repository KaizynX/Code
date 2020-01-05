#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3+7;

int n, m, r;
long long dp[N];

struct Node
{
    int s, t, w;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.t < n2.t;
    }
    friend istream &operator >> (istream &is, Node &node) {
        return is >> node.s >> node.t >> node.w;
    }
} a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> m >> r) {
        long long res = 0;
        for (int i = 1; i <= m; ++i) cin >> a[i];
        sort(a+1, a+m+1);
        for (int i = 1; i <= m; ++i) {
            dp[i] = a[i].w;
            for (int j = 1; j < i; ++j) {
                if (a[j].t+r <= a[i].s) {
                    dp[i] = max(dp[i], dp[j]+a[i].w);
                }
            }
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
    return 0;
}
