/*
 * @Author: Kaizyn
 * @Date: 2021-10-04 12:25:00
 * @LastEditTime: 2021-10-04 12:27:29
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};

int n, m;
int a[N], vis[N];
vector<int> ans;
DSU dsu;

inline bool check(int x) {
  if (x >= n || a[x] == -1 || vis[x]) return false;
  int y = a[x]%n, z = dsu[y];
  if (y <= x) return z == x;
  else return z == n && dsu[0] == x;
}

inline void solve() {
  ans.clear();
  priority_queue<pii, vector<pii>, greater<pii>> q;
  m = 0;
  cin >> n;
  dsu.init(n);
  for (int i = 0; i < n; ++i) {
    vis[i] = 0;
    cin >> a[i];
    if (a[i] == -1) continue;
    ++m;
    if (a[i]%n == i) {
      q.push(pii{a[i], i});
      vis[i] = 1;
    }
  }
  while (q.size()) {
    int u = q.top().second;
    q.pop();
    dsu.merge(u, u+1);
    ans.emplace_back(a[u]);
    int v = dsu[u];
    if (v == n) v = dsu[0];
    if (check(v)) {
      q.push(pii{a[v], v});
      vis[v] = 1;
    }
  }
  if ((int)ans.size() != m) return cout << "-1\n", void();
  for (int i : ans) cout << i << ' ';
  cout << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}