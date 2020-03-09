#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

struct Node
{
    int c, t;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.c < n2.c;
    }
};

int n;
Node a[N];
priority_queue<int> q;

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].c;
    for (int i = 1; i <= n; ++i) cin >> a[i].t;

    sort(a+1, a+n+1);
    long long sum = 0, res = 0;
    for (int i = 0, j = 1; j <= n || q.size(); ++i) {
        res += sum;
        if (q.empty()) i = a[j].c;
        while (j <= n && a[j].c == i) {
            q.push(a[j].t);
            sum += a[j].t;
            ++j;
        }
        int cur = q.top();
        q.pop();
        sum -= cur;
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}