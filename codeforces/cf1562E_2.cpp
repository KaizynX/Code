/*
 * @Author: Kaizyn
 * @Date: 2021-08-26 23:35:28
 * @LastEditTime: 2021-08-27 00:37:47
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
const int N = 5e3+7;

int n;
int dp[N][N];
char s[N];
int mx[26];

template <typename T>
void update(T &x, T y) {
  if (x < y) x = y;
}

struct TireTree {
  static const int SZ = 26;
  struct Node {
    Node *nex[SZ];
    #ifdef DEBUG
    // ~Node() { printf("~Node(%d,%d)\n", val, mxv); }
    #endif
    int val, mxv;
  } *root;
  TireTree() { init(); }
  void erase(Node *&rt) {
    if (!rt) return;
    for (int i = 0; i < SZ; ++i) erase(rt->nex[i]);
    delete rt;
    rt = nullptr;
  }
  void init() { erase(root); root = new Node(); }
  void insert(int st) {
    Node *cur = root;
    int i, c, mx = 0;
    for (i = st; i <= n; ++i) {
      c = s[i]-'a';
      int k = -1;
      for (int j = c; j >= 0; --j) {
        if (cur->nex[j]) {
          k = j;
          break;
        }
      }
      if (k == -1) break;
      cur = cur->nex[k];
      if (k < c) update(mx, cur->mxv);
      update(dp[st][i], max(mx, cur->val));
    }
    for ( ; i <= n; ++i) update(dp[st][i], mx);
    mx = *max_element(dp[st]+i, dp[st]+n+1);
    cur = root;
    for (i = st; i <= n; ++i) {
      c = s[i]-'a';
      for (int j = c+1; j < 26; ++j) {
        if (cur->nex[j] && cur->nex[j]->mxv <= mx) {
          erase(cur->nex[j]);
        }
      }
      if (!cur->nex[c]) cur->nex[c] = new Node();
      cur = cur->nex[c];
      cur->val = dp[st][i];
      cur->mxv = mx;
    }
  }
} tree[26];

void init() {
  for (int i = 0; i < 26; ++i) {
    tree[i].init();
    mx[i] = 0;
  }
}

inline void solve() {
  init();
  cin >> n >> (s+1);
  for (int i = 1, c; i <= n; ++i) {
    c = s[i]-'a';
    int mxv = *max_element(mx, mx+c);
    #ifdef DEBUG
    // orz(mxv);
    // orzarr(mx, 26);
    #endif
    for (int j = i; j <= n; ++j) dp[i][j] = mxv+j-i+1;
    tree[c].insert(i);
    update(mx[c], *max_element(dp[i]+i, dp[i]+n+1));
  }
  cout << *max_element(mx, mx+26) << '\n';
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