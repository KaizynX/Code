/*
 * @Author: Kaizyn
 * @Date: 2020-08-12 22:31:58
 * @LastEditTime: 2020-08-13 00:26:25
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e5+7;
const int K = 10;

int n, m, k, cur, res;
vector<pii> e[N];
vector<int> deg[K];
int L[N*30],R[N*30],fa[N*30],dep[N*30],num[N*30];
int root[N*30];
namespace Persistant_Union_Set
{
#define Mid ((l+r)>>1)
#define lson L[rt],l,Mid
#define rson R[rt],Mid+1,r
    int cnt;
    void build(int &rt,int l,int r)
    {
        rt=++cnt;
        if(l==r){fa[rt]=l;num[rt]=1;return ;}
        build(lson);build(rson);
    }
    void merge(int last,int &rt,int l,int r,int pos,int Fa)
    {
        rt=++cnt;L[rt]=L[last],R[rt]=R[last];
        if(l==r)
        {
            fa[rt]=Fa;
            dep[rt]=dep[last];
            return ;
        }
        if(pos<=Mid)merge(L[last],lson,pos,Fa);
        else merge(R[last],rson,pos,Fa);
    }
    void update(int rt,int l,int r,int pos)
    {
        if(l==r){dep[rt]++;return ;}
        if(pos<=Mid)update(lson,pos);
        else update(rson,pos);
    }
    int query(int rt,int l,int r,int pos)
    {
        if(l==r)return rt;
        if(pos<=Mid)return query(lson,pos);
        else return query(rson,pos);
    }
    int find(int rt,int pos)
    {
        int now=query(rt,1,n,pos);
        if(fa[now]==pos)return now;
        return find(rt,fa[now]);
    }
#undef Mid
#undef lson
#undef rson
}
using namespace Persistant_Union_Set;

void dfs(const int &d, const int &s) {
  if (d > k) return res += s == n, void();
  int now_pus = cur;
  for (int c = 0; c < d; ++c) {
    #ifdef DEBUG
    cout << d << " " << c << endl;
    #endif
    // back
    int sum = s;
    cur = now_pus;
    for (const int &u : deg[d]) {
      // merge
      ++cur;
      root[cur] = root[cur-1];
      int v = e[u][c].second;
      int posu = find(root[cur], u), posv = find(root[cur], v);
      if (fa[posu] != fa[posv]) {
        if (dep[posu] > dep[posv]) swap(posu, posv);
        merge(root[cur-1], root[cur], 1, n, fa[posu], fa[posv]);
        if (dep[posu] == dep[posv]) update(root[cur], 1, n, fa[posv]);
      } else {
        sum += dep[query(cur-1, 1, n, v)]+1;
        #ifdef DEBUG
        cout << u << " " << v << " " << dep[query(cur-1, 1, n, v)] << endl;
        #endif
      }
    }
    dfs(d+1, sum);
  }
}

inline void solve() {
  cin >> n >> m >> k;
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(w, v);
  }
  for (int i = 1; i <= n; ++i) {
    sort(e[i].begin(), e[i].end());
    deg[e[i].size()].emplace_back(i);
  }
  build(root[0], 1, n);
  dfs(1, 0);
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}