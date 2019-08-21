#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int MAXN = 1e5+7;
const long long INF = 1e18;

int T, n, num;
long long res = INF;

struct Node
{
    long long x, y;
    Node () {}
    Node (long long _x, long long _y) : x(_x), y(_y) {}
} a[MAXN];

void dfs(int cur, long long maxa, long long maxb)
{
    if (cur > n) {
        if (maxa == -1 || maxb == -1) return;
        // res = min(res, abs(maxa-maxb));
        if (abs(maxa-maxb) < res) {
            res = abs(maxa-maxb);
            cout << " " << maxa << " " << maxb << endl;
        }
        return;
    }
    dfs(cur+1, max(maxa, a[cur].x), maxb);
    dfs(cur+1, maxa, max(maxb, a[cur].y));
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld%lld", &a[i].x, &a[i].y);
        }
        dfs(1, -1, -1);
        printf("%lld\n", res);
    }
    return 0;
}
