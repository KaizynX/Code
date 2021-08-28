/*
 * @Author: Kaizyn
 * @Date: 2021-08-27 09:02:17
 * @LastEditTime: 2021-08-27 09:11:47
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
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e3+7;

int n;
char s[N];
int dp[N][N];

template <typename T>
void update(T &x, T y) {
  if (x < y) x = y;
}

struct TireTree {
  static const int SZ = 26;
  static const char beg = 'a';
  struct Node {
    Node *nex[SZ];
    #ifdef DEBUG
    // ~Node() { printf("~Node(%d,%d)\n", val, mxv); }
    #endif
    int val, mxv;
  } *root;
  TireTree() { init(); }
  void init() { erase(root); root = new Node(); }
  void erase(Node *&rt) {
    if (!rt) return;
    for (int i = 0; i < SZ; ++i) erase(rt->nex[i]);
    delete rt;
    rt = nullptr;
  }
  void insert(int st) {
    int i, mx = 0, c;
    Node *cur = root;
    for (i = st; i <= n; ++i) {
      c = s[i]-beg;
      for (int j = 0; j < c; ++j) if (cur->nex[j]) {
        update(mx, cur->nex[j]->mxv);
      }
      if (!cur->nex[c]) break;
      cur = cur->nex[c];
      dp[st][i] = max(cur->val, ++mx);
    }
    for (; i <= n; ++i) dp[st][i] = ++mx;
    cur = root;
    mx = *max_element(dp[st]+st, dp[st]+n+1);
    for (i = st; i <= n; ++i) {
      c = s[i]-beg;
      if (!cur->nex[c]) cur->nex[c] = new Node();
      cur = cur->nex[c];
      update(cur->val, dp[st][i]);
      update(cur->mxv, mx);
    }
  }
} tree;

inline void solve() {
  tree.init();
  cin >> n >> (s+1);
  for (int i = 1; i <= n; ++i) tree.insert(i);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    #ifdef DEBUG
    orzarr(dp[i]+1, n);
    #endif
    update(ans, *max_element(dp[i]+i, dp[i]+n+1));
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
  }
  return 0;
}