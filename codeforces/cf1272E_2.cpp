#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;
int a[N], res[N];
vector<int> e[N];
queue<int> q;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i-a[i] >= 1) e[i-a[i]].emplace_back(i);
        if (i+a[i] <= n) e[i+a[i]].emplace_back(i);
    }
    memset(res, -1, sizeof res);
    for (int i = 1; i <= n; ++i) {
        if ((i-a[i] >= 1 && (a[i]&1)^(a[i-a[i]]&1)) || 
            (i+a[i] <= n && (a[i]&1)^(a[i+a[i]]&1)))
            res[i] = 1, q.push(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : e[u]) {
            if (res[v] == -1) {
                res[v] = res[u]+1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << res[i] << " \n"[i==n];
    return 0;
}

