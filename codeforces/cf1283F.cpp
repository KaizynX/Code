#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;
int a[N], du[N], res[N];

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> q;

int main()
{
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        ++du[a[i]] ;
    }
    for (int i = 1; i <= n; ++i) {
        if (du[i]) continue;
        q.push({i, i});
    }
    for (int i = n-1; i; --i) {
        if (!q.size()) {
            cout << -1 << endl;
            return 0;
        }
        pii cur = q.top();
        q.pop();
        res[i] = cur.second;
        if (--du[a[i]] == 0) {
            cur.second = a[i];
            cur.first = max(cur.first, a[i]);
            q.push(cur);
        }
    }
    cout << a[1] << endl;
    for (int i = 1; i < n; ++i) {
        cout << a[i] << " " << res[i] << endl;
    }
    return 0;
}
