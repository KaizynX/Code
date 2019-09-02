#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+7;
const int INF = 1e9;

int n, w, l;
int a[MAXN];
long long col[MAXN];

int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        priority_queue<pair<int, int> > q;
        cin >> l;
        for (int j = 1; j <= l; ++j) {
            cin >> a[j];
        }
        for (int j = 1; j <= w; ++j) {
            if (j <= l) q.push({a[j], j});
            int st = max(1, j-(w-l)), ed = min(l, j);
            pair<int, int> cur = q.top();
            while (cur.second < st) {
                q.pop();
                if (!q.size()) break;
                cur = q.top();
            }
            int tmp = cur.first;
            if (j-(w-l) < 1 || j > l) tmp = max(tmp, 0);
            col[j] += tmp;
        }
    }
    for (int i = 1; i <= w; ++i) {
        cout << col[i] << " ";
    }
    cout << endl;
    return 0;
}
