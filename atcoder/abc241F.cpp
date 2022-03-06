/*
 * @Author: Kaizyn
 * @Date: 2022-02-26 20:57:21
 * @LastEditTime: 2022-02-26 21:40:04
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 4e5 + 7;
const int dir[] = {0,-1,0,1,0};

int n, H, W;
int sx, gx, sy, gy;
int x[N], y[N], dis[N];
set<pair<int, int>> stones;
map<pair<int, int>, int> mp;
map<int, set<int>> stx, sty;
vector<int> e[N];


int magic(int x, int y) {
  pii p = {x, y};
  if (mp.count(p)) return mp[p];
  #ifdef DEBUG
  cout << "magic:" << x << ' ' << y << '\n';
  #endif
  return mp[p] = mp.size();
}

void add_edge(int x, int y) {
  if (x == y) return;
  #ifdef DEBUG
  cout << "add_edge:" << x << ' ' << y << '\n';
  #endif
  e[x].emplace_back(y);
}

void connect(int x, int y) {
  int id = magic(x, y);
  set<int> &xs = stx[x];
  auto it = xs.upper_bound(y);
  if (it != xs.end()) {
    add_edge(id, magic(x, *it - 1));
  }
  if (it != xs.begin()) {
    --it;
    add_edge(id, magic(x, *it + 1));
    ++it;
  }
  set<int> &ys = sty[y];
  it = ys.upper_bound(x);
  if (it != ys.end()) {
    add_edge(id, magic(*it - 1, y));
  }
  if (it != ys.begin()) {
    --it;
    add_edge(id, magic(*it + 1, y));
    ++it;
  }
}

inline void solve() {
  cin >> H >> W >> n >> sx >> sy >> gx >> gy;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
    stx[x[i]].insert(y[i]);
    sty[y[i]].insert(x[i]);
    stones.insert({x[i], y[i]});
  }
  for (int i = 1; i <= n; ++i) {
    for (int d = 0; d < 4; ++d) {
      int nx = x[i] + dir[d];
      int ny = y[i] + dir[d + 1];
      if (nx < 1 || ny < 1 || nx > H || ny > W) continue;
      if (stones.count({nx, ny})) continue;
      connect(nx, ny);
    }
  }
  int s = magic(sx, sy);
  connect(sx, sy);

  priority_queue<pii, vector<pii>, greater<pii>> q;
  memset(dis, 0x3f, sizeof dis);
  dis[s] = 0;
  q.push({0, s});
  while (q.size()) {
    int d = q.top().first;
    int u = q.top().second;
    q.pop();
    if (d > dis[u]) continue;
    for (int v : e[u]) {
      if (dis[u] + 1 < dis[v]) {
        dis[v] = dis[u] + 1;
        q.push({dis[v], v});
      }
    }
  }
  #ifdef DEBUG
  orz(s);
  orzarr(dis, mp.size());
  #endif
  if (mp.count({gx, gy}) == 0) {
    cout << "-1\n";
  } else {
    int ans = dis[magic(gx, gy)];
    if (ans >= 0x3f3f3f3f) ans = -1;
    cout << ans << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}