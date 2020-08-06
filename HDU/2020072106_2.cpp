/*
 * @Author: Kaizyn
 * @Date: 2020-07-21 11:53:48
 * @LastEditTime: 2020-07-21 13:48:07
 */ 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

// #define DEBUG

using namespace std;
using namespace __gnu_pbds;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

/*
tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t; //红黑树
t.insert({x,i+1}); //----------------- 插入x，用独特的正整数i+1标注（因为erase太辣鸡）
t.erase(t.lower_bound({x,0})); //----- 删除x（删除单个元素）
t.order_of_key({x,0})+1; //----------- x的排名（小于x的元素个数+1）
t.find_by_order(x-1)->first; //------- 排名为x的元素（第x小的数）
prev(t.lower_bound({x,0}))->first; //- x的前驱（小于x且最大）
t.lower_bound({x+1,0})->first; //----- x的后继（大于x且最小）
t.join(t2); //------------------------ 将t2并入t，t2清空，前提是取值范围不相交
t.split(v,t2); //--------------------- 小于等于v的元素属于t，其余的属于t2
*/

int n, m, q, sqr;
int a[N], tag[N], deg[N], eu[N], ev[N];
vector<int> hve[N], lte[N];
unordered_map<int, int> cnt[N];
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> t[N]; //红黑树

inline int query(const int &u) {
  int l = 0, r = 1e9, mid;
  while (l < r) {
    mid = (l+r)>>1;
    if ((int)t[u].order_of_key(mid+1) == mid+1) l = mid+1;
    else r = mid;
  }
  return l;
}

inline void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", eu+i, ev+i);
    ++deg[eu[i]]; ++deg[ev[i]];
    if (++cnt[eu[i]][a[ev[i]]] == 1) t[eu[i]].insert(a[ev[i]]);
    if (++cnt[ev[i]][a[eu[i]]] == 1) t[ev[i]].insert(a[eu[i]]);
  }
  sqr = sqrt(1.5*m);
  for (int i = 1; i <= n; ++i) tag[i] = deg[i] >= sqr;
  for (int i = 1; i <= m; ++i) {
    if (tag[eu[i]]) hve[ev[i]].emplace_back(eu[i]);
    else lte[ev[i]].emplace_back(eu[i]);
    if (tag[ev[i]]) hve[eu[i]].emplace_back(ev[i]);
    else lte[eu[i]].emplace_back(ev[i]);
  }
  scanf("%d", &q);
  for (int i = 1, op, u, x; i <= q; ++i) {
    scanf("%d %d", &op, &u);
    if (op == 1) {
      scanf("%d", &x);
      for (const int &v : hve[u]) { // modify heavy point
        if (--cnt[v][a[u]] == 0) t[v].erase(a[u]);
        if (++cnt[v][x] == 1) t[v].insert(x);
      }
      a[u] = x;
    } else {
      if (!tag[u]) { // light point rebuild
        t[u].clear();
        cnt[u].clear();
        for (const int &v : hve[u]) {
          if (++cnt[u][a[v]] == 1) t[u].insert(a[v]);
        }
        for (const int &v : lte[u]) {
          if (++cnt[u][a[v]] == 1) t[u].insert(a[v]);
        }
      }
      printf("%d\n", query(u));
    }
  }
  // clear
  for (int i = 1; i <= n; ++i) {
    vector<int>().swap(hve[i]);
    vector<int>().swap(lte[i]);
    cnt[i].clear();
    t[i].clear();
    deg[i] = 0;
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}