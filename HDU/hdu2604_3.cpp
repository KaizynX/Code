#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;
const int M = 40;

struct Node
{
    int id, n, m;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.m < n2.m;
    }
};

vector<int> res;
vector<Node> q;
// dp[i][j][k] at pos i, i is j, i-1 is k (0-f, 1-m)
int dp[N][2][2], f[N];


inline void init(int k)
{
    f[0] = 0;
    f[1] = 2%k;
    f[2] = 4%k;
    dp[2][0][0] = dp[2][0][1] = dp[2][1][0] = dp[2][1][1] = 1%k;
    for (int i = 3; i <= 1e6; ++i) {
        dp[i][0][0] = dp[i-1][0][1];
        dp[i][0][1] = dp[i-1][1][1];
        dp[i][1][0] = (dp[i-1][0][0]+dp[i-1][0][1])%k;
        dp[i][1][1] = (dp[i-1][1][0]+dp[i-1][1][1])%k;
        f[i] = (dp[i][0][0]+dp[i][0][1]+dp[i][1][0]+dp[i][1][1])%k;
    }
}

int main()
{
    int a, b;
    while (cin >> a >> b)
        q.push_back({(int)q.size(), a, b});
    res.resize(q.size());
    sort(q.begin(), q.end());
    for (int k = 1, i = 0; k <= 30; ++k) {
        init(k);
        while (i < (int)q.size() && q[i].m == k) {
            res[q[i].id] = f[q[i].n];
            ++i;
        }
    }
    for (int i : res) cout << i << endl;
    return 0;
}
