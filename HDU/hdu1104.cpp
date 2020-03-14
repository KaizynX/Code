/*
 * @Author: Kaizyn
 * @Date: 2020-03-13 10:44:45
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-13 11:41:30
 * @FilePath: \Code\HDU\hdu1104.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const char s[] = "+-*%";

int n, k, m;

struct Node
{
    int vk, vm;
    Node(){}
    Node(const int &x) {
        vk = ((x%k)+k)%k;
        vm = ((x%m)+m)%m;
    }
    Node(const int &_vk, const int &_vm) : vk(_vk), vm(_vm) {}
    Node operator + (const int &x) { return Node((vk+x)%k, (vm+x)%m); }
    Node operator - (const int &x) { return Node(((vk-x)%k+k)%k, ((vm-x)%m+m)%m); }
    Node operator * (const int &x) { return Node(vk*x%k, vm*x%m); }
    Node operator % (const int &x) { return Node(vm, vm); }
    bool operator == (const Node &x) { return vk == x.vk; }
    bool operator == (const int &x) { return vk == (x%k+k)%k; }
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.vk == n2.vk ? n1.vm < n2.vm : n1.vk < n2.vk;
    }
} val[N];

map<Node, int> vis; 
int ope[N], pre[N];

void print(const int &u)
{
    string res;
    for (int i = u; i; i = pre[i]) {
        res += s[ope[i]];
    }
    cout << res.size() << endl;
    reverse(res.begin(), res.end());
    cout << res << endl;
}

inline void solve()
{
    queue<int> q;
    vis.clear();
    int tot = 0, u;
    val[0] = n;
    vis[val[0]] = 1;
    q.push(0);
    function<void(Node, int)> add = [&](const Node &x, const int &y) {
        if (vis.count(x)) return;
        ++tot;
        val[tot] = x;
        ope[tot] = y;
        pre[tot] = u;
        vis[x] = 1;
        q.push(tot);
    };
    while (q.size()) {
        u = q.front();
        q.pop();
        if (val[u] == n+1) {
            print(u);
            return;
        }
        add(val[u]+m, 0);
        add(val[u]-m, 1);
        add(val[u]*m, 2);
        add(val[u]%m, 3);
    }
    cout << 0 << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> k >> m && n|k|m) {
        solve();
    }
    return 0;
}