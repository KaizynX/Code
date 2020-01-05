#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;
const int M = 3e4+7;

int n, m, t, top;
int h[N];
pair<int, int> stk[N];

struct Node
{
    int x, y;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.x == n2.x ? n1.y < n2.y : n1.x < n2.x;
    }
    friend istream &operator >> (istream &is, Node &node) {
        return is >> node.x >> node.y;
    }
} a[M];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> t;
    for (int i = 1; i <= t; ++i)
        cin >> a[i];
    sort(a+1, a+t+1);

    int res = 0;
    for (int i = 1, it = 1; i <= n; ++i) {
        top = 0;
        for (int j = 1; j <= m; ++j) {
            if (it <= t && a[it].x == i && a[it].y == j) {
                h[j] = 0;
                ++it;
            } else {
                ++h[j];
            }
            while (top && stk[top].first >= h[j]) --top;
            res = max(res, h[j]*(j-stk[top].second));
            stk[++top] = {h[j], j};
        }
        while (top) {
            res = max(res, stk[top].first*(m-stk[top].second+1));
            --top;
        }
    }
    cout << res << endl;
    return 0;
}
