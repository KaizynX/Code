/*
 * @Author: Kaizyn
 * @Date: 2020-04-20 23:12:34
 * @LastEditTime: 2020-04-21 14:05:17
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e4+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;
vector<int> e[N];
int cnt[N];

int _dfn, _col, _top;
int dfn[N], low[N], ins[N], col[N], sta[N];

struct Stack_Node {
    int u;
    int edge_info;
    int state;
} tarjan_stack[N];

void tarjan(const int &u) {
    static int stack_top;
    stack_top = 0;
    tarjan_stack[++stack_top] = {u, 0, 0};
    while (stack_top) {
        bool flag = false;
        int &u = tarjan_stack[stack_top].u;
        auto &i = tarjan_stack[stack_top].edge_info;
        switch (tarjan_stack[stack_top].state) {
        case 0 :
        tarjan_stack[stack_top].state = 1;
        flag = false;
            dfn[u] = low[u] = ++_dfn;
            ins[u] = 1;
            sta[++_top] = u;
            for (; i < (int)e[u].size(); ++i) {
#define v e[u][i]
                if (!dfn[v]) {
                    tarjan_stack[++stack_top] = {v, 0, 0};
        flag = true;
                    break;
        case 1 :
        flag = false;
                    low[u] = min(low[u], low[v]);
                } else if (ins[v]) {
                    low[u] = min(low[u], low[v]);
                }
#undef v
            }
        if (flag) break;
            if (dfn[u] == low[u]) {
                ++_col;
                do {
                    col[sta[_top]] = _col;
                    ins[sta[_top]] = 0;
                } while (sta[_top--] != u);
            }
        --stack_top;
        }
    }
}

signed main()
{
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
        ++cnt[col[i]];
        #ifdef DEBUG
        cout << col[i] << " \n"[i==n];
        #endif
    }
    int res = 0;
    for (int i = 1; i <= _col; ++i) {
        res += cnt[i] > 1;
    }
    cout << res << endl;
    return 0;
}