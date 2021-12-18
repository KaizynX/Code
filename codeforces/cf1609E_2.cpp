/*
 * @Author: Kaizyn
 * @Date: 2021-12-02 20:30:01
 * @LastEditTime: 2021-12-02 21:18:54
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
const int N = 1e5+7;

int n, q;
string s;
int to[1<<5][1<<5];
vector<string> bits[1<<5], sss = {"a", "b", "c", "ab", "bc"};

template <typename T>
void MIN(T &x, const T &y) {
  if (y < x) x = y;
}

void init() {
  for (int i = 0; i < 1<<5; ++i) {
    bits[i] = {""};
    for (int j = 0; j < 5; ++j) if ((i>>j)&1) {
      bits[i].emplace_back(sss[j]);
    }
  }
  auto get_mask = [&](int i, int j) {
    int k = 0;
    for (string &pre : bits[i]) {
      for (string &suf : bits[j]) {
        string str = pre+suf;
        str.erase(unique(str.begin(), str.end()), str.end());
        if (str == "abc") return -1;
        for (int id = 0; id < 5; ++id) {
          if (str.find(sss[id]) != str.npos) k |= 1<<id;
        }
      }
    }
    return k;
  };
  for (int i = 0; i < 1<<5; ++i) {
    for (int j = 0; j < 1<<5; ++j) {
      to[i][j] = get_mask(i, j);
    }
  }
}

struct Node {
  int dp[1<<5];
  Node () { memset(dp, 0x3f, sizeof dp); }
  Node& operator = (const char c) {
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 1;
    dp[1<<(c-'a')] = 0;
    return *this;
  }
  Node operator + (const Node &rhs) const {
    Node res;
    for (int i = 0; i < 1<<5; ++i) if (dp[i] < INF) {
      for (int j = 0; j < 1<<5; ++j) if (rhs.dp[j] < INF) {
        if (~to[i][j]) MIN(res.dp[to[i][j]], dp[i]+rhs.dp[j]);
      }
    }
    return res;
  }
} tr[N<<2];

void push_up(int i) {
  tr[i] = tr[i<<1]+tr[i<<1|1];
}

void build(int l = 1, int r = n, int i = 1) {
  if (l == r) return tr[i] = s[l-1], void();
  int mid = (l+r)/2;
  build(l, mid, i<<1);
  build(mid+1, r, i<<1|1);
  push_up(i);
}

void update(int x, char ch, int l = 1, int r = n, int i = 1) {
  if (l == r) return tr[i] = ch, void();
  int mid = (l+r)/2;
  if (x <= mid) update(x, ch, l, mid, i<<1);
  else update(x, ch, mid+1, r, i<<1|1);
  push_up(i);
}

int query() {
  return *min_element(tr[1].dp, tr[1].dp+(1<<5));
}

inline void solve() {
  cin >> n >> q >> s;
  build();
  for (int i = 1, x; i <= q; ++i) {
    char ch;
    cin >> x >> ch;
    update(x, ch);
    cout << query() << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  init();
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}