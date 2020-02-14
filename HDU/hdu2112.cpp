#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
const int INF = 1e9;

int n, s, t, m;
int dis[N];
string str;
map<string, int> name;
typedef pair<int, int> pii;
vector<pii> e[N];

inline void init()
{
    name.clear();
    m = 0;
    for (int i = 1; i <= 150; ++i) {
        vector<pii>().swap(e[i]);
        dis[i] = INF;
    }
}

inline int id(const string &sss)
{
    if (name.find(sss) == name.end()) return name[sss] = ++m;
    else return name[sss];
}

inline int dijskra()
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    dis[s] = 0;
    while (q.size()) {
        pii u = q.top();
        q.pop();
        // cout << u.first << " " << u.second << endl;
        if (u.first > dis[u.second]) continue;
        if (u.second == t) return u.first;
        for (pii v : e[u.second]) {
            int d = u.first+v.first;
            if (d >= dis[v.second]) continue;
            dis[v.second] = d;
            q.push({d, v.second});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n && n != -1) {
        init();
        cin >> str; s = id(str);
        cin >> str; t = id(str);
        for (int i = 1, u, v, w; i <= n; ++i) {
            cin >> str;
            u = id(str);
            cin >> str;
            v = id(str);
            cin >> w;
            e[u].emplace_back(w, v);
            e[v].emplace_back(w, u);
        }
        cout << dijskra() << endl;
    }
    return 0;
}
