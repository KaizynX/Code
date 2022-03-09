/*
 * @Author: Kaizyn
 * @Date: 2022-03-09 16:18:17
 * @LastEditTime: 2022-03-09 16:42:36
 */
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

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;
constexpr int FUCK = 2022;

int n, m;
int idx[N], re_idx[N];
char str[N];

struct TireTree {
  static const int NN = 2e5+7;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], cnt;
  vector<int> has[N];
  unordered_set<int> has_set[NN];
  unordered_map<int, int> changes;
  TireTree(char _beg = 'a') : beg(_beg) {}
  void insert(const char *s, int id) {
    int len = strlen(s), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
      has[p].emplace_back(id);
      has_set[p].insert(id);
    }
  }
  void rebuild() {
    for (int i = 1; i <= n; ++i) re_idx[idx[i]] = i;
    iota(idx + 1, idx + n + 1, 1);
    for (int i = 1; i <= cnt; ++i) {
      vector<int> tmp(has[i].size());
      for (unsigned j = 0; j < has[i].size(); ++j) {
        tmp[j] = re_idx[has[i][j]];
      }
      sort(tmp.begin(), tmp.end()); // HERE IS log !!!
      swap(tmp, has[i]);
      has_set[i].clear();
      has_set[i].insert(has[i].begin(), has[i].end());
    }
    changes.clear();
  }
  void update(int x, int y) {
    swap(idx[x], idx[y]);
    int px = changes.count(x) ? changes[x] : x;
    int py = changes.count(y) ? changes[y] : y;
    if (x == py) changes.erase(x);
    else changes[x] = py;
    if (y == px) changes.erase(y);
    else changes[y] = px;
    if (changes.size() > FUCK) rebuild();
  }
  int query(const char *s, int len, int l, int r) {
    if (len == 0) return r - l + 1;
    int p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) return 0;
      p = nex[p][c];
    }
    #ifdef DEBUG
    printf("query():p=%d\n", p);
    orzeach(has[p]);
    orzeach(changes);
    #endif
    int ans = upper_bound(has[p].begin(), has[p].end(), r)
            - lower_bound(has[p].begin(), has[p].end(), l);
    for (const auto &pr : changes) {
      int x = pr.first, y = pr.second;
      if (x < l || x > r) continue;
      ans += (int)has_set[p].count(y) - (int)has_set[p].count(x);
    }
    return ans;
  }
} tree;

inline void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", str);
    tree.insert(str, i);
    idx[i] = i;
  }
  for (int _ = m, op, k, l, r; _; --_) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &l, &r);
      tree.update(l, r);
    } else {
      scanf("%s%d%d%d", str, &k, &l, &r);
      printf("%d\n", tree.query(str, k, l, r));
    }
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