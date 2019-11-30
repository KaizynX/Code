#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n;
int dp[N], last[N];

struct Node
{
    int w, s, id;
    friend bool operator < (const Node &x, const Node &y) {
        return x.w < y.w && x.s > y.s;
    }
    friend istream &operator >> (istream &is, Node &x) {
        return is >> x.w >> x.s;
    }
} a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> a[++n]) a[n].id = n;
    sort(a+1, a+n+1, [](const Node &x, const Node &y){ return x.s > y.s; });
    int resi = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1; last[i] = 0;
        for (int j = 1; j < i; ++j) {
            if (a[j] < a[i] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
                last[i] = j;
            }
        }
        if (dp[i] > dp[resi]) resi = i;
    }
    cout << dp[resi] << endl;
    vector<int> res;
    for (int cur = resi; cur; cur = last[cur]) res.emplace_back(a[cur].id);
    reverse(res.begin(), res.end());
    for (int i : res) cout << i << endl;
    return 0;
}
