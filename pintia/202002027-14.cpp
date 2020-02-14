#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
const int INF = 0x3f3f3f3f;

int n, k, s, t, tot;
int a[N], num[N], nex[N];
string str;
map<string, int> mp;
typedef pair<int, int> pii;
vector<pii> e[N];

struct Node
{
    int dis, cnt, kill;
    Node(){}
    Node(int _d = INF, int _c = 0, int _k = 0) : dis(_d), cnt(_c), kill(_k) {}
    friend bool operator < (const Node &n1, const Node &n2) {
        if (n1.dis != n2.dis) return n1.dis < n2.dis;
        if (n1.cnt != n2.cnt) return n1.cnt > n2.cnt;
        return n1.kill > n2.kill;
    }
    friend bool operator == (const Node &n1, const Node &n2) {
        return n1.dis == n2.dis && n1.cnt == n2.cnt && n1.kill == n2.kill;
    }
    friend Node operator + (const Node &n1, const Node &n2) {
        Node res;
        res.dis = n1.dis+n2.dis;
        res.cnt =;
    }
} d[N];

inline int get_id(const string &sss)
{
    if (mp.count(str)) return mp[sss];
    else return mp[sss] = ++tot;
}

inline dijskra()
{
    typedef pair<Node, int> pni;
    priority_queue<pni, vector<pni>, greater<pni>> q;
    //priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push({t, Node(0, 1, a[t])});
    d[t] = Node(0, 1, a[t]);
    num[t] = 1;
    while (q.size()) {
        pni u = q.top();
        q.pop();
        if (u.second == s) break;
        if (d[u.second] < u.first) continue;
        for (pii v : e[u]) {
            if (d[v.second] < u.second)
        }
    }
}

int main()
{
    cin >> n >> k;
    cin >> str; s = get_id(str);
    cin >> str; t = get_id(str);
    for (int i = 1, tmp; i <= n; ++i) {
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
    return 0;
}
