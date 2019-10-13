#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, k;
long long now, res;
int vis[N], cnt[N], ck;

struct Node
{
    int t, d = 0, id = 0;
    bool operator < (const Node &cp) const {
        return d > cp.d;
    }
} a[N], b[N];

priority_queue<Node> q;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].t >> a[i].d;
        b[i].t = i;
        a[i].id = i;
        // b[a[i].t].d = max(b[a[i].t].v, a[i].d);
        if (b[a[i].t].d < a[i].d) {
            b[a[i].t].d = a[i].d;
            b[a[i].t].id = i;
        }
    }
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    for (int i = 1; i <= k; ++i) {
        if (!b[i].id) break;
        q.push(b[i]);
        if (!cnt[b[i].t]) ++ck;
        ++cnt[b[i].t];
        vis[b[i].id] = 1;
        now += b[i].d;
    }
    int pos = 1;
    while ((int)q.size() < k) {
        if (!vis[a[pos].id]) {
            q.push(a[pos]);
            if (!cnt[a[pos].t]) ++ck;
            ++cnt[a[pos].t];
            vis[a[pos].id] = 1;
            now += a[pos].d;
        }
        ++pos;
    }
    now += 1ll*ck*ck;
    res = now;

    while (pos <= n && q.top().d < a[pos].d) {
        if (vis[a[pos].id]) {
            ++pos;
            continue;
        }
        Node cur = q.top();
        q.pop();
        q.push(a[pos]);
        now -= cur.d;
        if (--cnt[cur.t] == 0) {
            now -= 1ll*ck*ck;
            --ck;
            now += 1ll*ck*ck;
        }
        now += a[pos].d;
        if (!cnt[a[pos].t]) {
            now -= 1ll*ck*ck;
            ++ck;
            now += 1ll*ck*ck;
        }
        ++pos;
        res = max(res, now);
    }
    cout << res << endl;
    return 0;
}
