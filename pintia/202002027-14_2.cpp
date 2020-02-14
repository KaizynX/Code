#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
const int INF = 0x3f3f3f3f;

int n, k, s, t, tot;
int a[N], cnt[N], dis[N], num[N], kil[N], nex[N], vis[N];
string mmp[N];
map<string, int> mp;
typedef pair<int, int> pii;
vector<pii> e[N];

inline int get_id(const string &sss)
{
    if (mp.count(sss)) return mp[sss];
    else {
        mmp[++tot] = sss;
        return mp[sss] = tot;
    }
}

inline void dijskra()
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    memset(dis, 0x3f, sizeof dis);
    q.push({0, t});
    dis[t] = 0;
    num[t] = 1;
    kil[t] = a[t];
    cnt[t] = 1;
    while (q.size()) {
        pii u = q.top();
        q.pop();
        if (u.second == s) break;
        if (vis[u.second]) continue;
        vis[u.second] = 1;
        // cout << u.first << " " << u.second << endl; ////////
        for (pii v : e[u.second]) {
            int tmp = v.first+u.first;
            if (tmp < dis[v.second]) {
                cnt[v.second] = cnt[u.second];
                dis[v.second] = tmp;
                num[v.second] = num[u.second]+1;
                kil[v.second] = kil[u.second]+a[v.second];
                nex[v.second] = u.second;
                q.push({tmp, v.second});
            } else if (tmp == dis[v.second]) {
                ++cnt[v.second];
                tmp = num[u.second]+1;
                if (tmp > num[v.second]) {
                    num[v.second] = tmp;
                    kil[v.second] = kil[u.second]+a[v.second];
                    nex[v.second] = u.second;
                } else if (tmp == num[v.second]) {
                    tmp = kil[u.second]+a[v.second];
                    if (tmp > kil[v.second]) {
                        kil[v.second] = tmp;
                        nex[v.second] = u.second;
                    }
                }
            }
        }
    }
}

void print()
{
    for (int cur = s; cur != t; cur = nex[cur])
        cout << mmp[cur] << "->";
    cout << mmp[t] << endl;
}

int main()
{
    string str;
    cin >> n >> k;
    cin >> str; s = get_id(str);
    cin >> str; t = get_id(str);
    for (int i = 1, tmp; i < n; ++i) {
        cin >> str >> tmp;
        a[get_id(str)] = tmp;
    }
    for (int i = 1, u, v, w; i <= k; ++i) {
        cin >> str; u = get_id(str);
        cin >> str; v = get_id(str);
        cin >> w;
        e[u].emplace_back(w, v);
        e[v].emplace_back(w, u);
    }
    dijskra();
    print();
    cout << cnt[s] << " " << dis[s] << " " << kil[s] << endl;
    return 0;
}
