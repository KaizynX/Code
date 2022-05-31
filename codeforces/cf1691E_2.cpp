#include <bits/stdc++.h>

// #define DEBUG

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

using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 1e5 + 7;
const int M = 4e5 + 7;

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
int sigle_red[M];
DSU dsu;
set<int> old, yong;
vector<int> l[2], r[2], dis;
vector<int> add[2][M], del[2][M];

inline void solve() {
  cin >> n;
  for (int i = 1, c, L, R; i <= n; ++i) {
    cin >> c >> L >> R;
    dis.emplace_back(L);
    dis.emplace_back(R);
    l[c].emplace_back(L);
    r[c].emplace_back(R);
  }
  sort(dis.begin(), dis.end());
  dis.erase(unique(dis.begin(), dis.end()), dis.end());
  m = dis.size();
  for (int _ : {0, 1}) {
    for (uint i = 0; i < l[_].size(); ++i) {
      int &x = l[_][i];
      x = lower_bound(dis.begin(), dis.end(), x) - dis.begin() + 1;
      add[_][x].emplace_back(i);
    }
    for (uint i = 0; i < r[_].size(); ++i) {
      int &x = r[_][i];
      x = lower_bound(dis.begin(), dis.end(), x) - dis.begin() + 1;
      del[_][x].emplace_back(i);
    }
  }
  int ans = l[1].size();
  for (uint i = 0; i < l[1].size(); ++i) {
    ++sigle_red[l[1][i]];
    --sigle_red[r[1][i]];
  }
  for (int i = 1; i <= m; ++i) {
    sigle_red[i] += sigle_red[i - 1];
  }
  for (int i = 1; i <= m; ++i) {
    sigle_red[i] += sigle_red[i - 1];
  }
  for (uint i = 0; i < l[0].size(); ++i) {
    if (sigle_red[r[0][i] - 1] - sigle_red[l[0][i] - 1] == 0) {
      #ifdef DEBUG
      cerr << "sigle_red!\n";
      orz(i);
      orz(l[0][i]);
      orz(r[0][i]);
      #endif
      ++ans;
    }
  }
  #ifdef DEBUG
  orz(ans);
  orzarr(sigle_red + 1, m);
  #endif
  dsu.init(l[1].size());
  old.clear();
  yong.clear();
  for (int cnt0 = 0, i = 1; i <= m; ++i) {
    cnt0 += (int)add[0][i].size() - (int)del[0][i].size();
    for (int x : add[1][i]) {
      yong.insert(x);
    }
    for (int x : del[1][i]) {
      if (old.count(x)) old.erase(x);
      else yong.erase(x);
    }
    if (cnt0 > 0 && yong.size()) {
      if (old.empty()) {
        old.insert(*yong.begin());
        yong.erase(yong.begin());
      }
      while (yong.size()) {
        dsu.merge(*yong.begin(), *old.begin());
        old.insert(*yong.begin());
        yong.erase(yong.begin());
        --ans;
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i : {0, 1}) {
      l[i].clear();
      r[i].clear();
      for (int j = 1; j <= m; ++j) {
        sigle_red[j] = 0;
        add[i][j].clear();
        del[i][j].clear();
      }
    }
    dis.clear();
  }
  return 0;
}