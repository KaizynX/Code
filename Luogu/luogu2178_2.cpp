/*
 * @Author: Kaizyn
 * @Date: 2021-08-24 13:55:11
 * @LastEditTime: 2021-08-24 14:21:51
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
const int N = 3e5+7;

int n;
int a[N], vis[N];
string s;
ll cnt[N], val[N];
multiset<int> st[N<<1];

void my_merge(multiset<int> &s1, multiset<int> &s2) {
  if (s1.size() < s2.size()) swap(s1, s2);
  s1.insert(s2.begin(), s2.end());
  s2.clear();
}

ll query(multiset<int> &st) {
  ll ans = 0;
  int x = *st.begin();
  st.erase(st.begin());
  ans = 1ll*x**st.begin();
  st.insert(x);

  x = *st.rbegin();
  st.erase(--st.end());
  ans = max(ans, 1ll*x**st.rbegin());
  st.insert(x);
  return ans;
}

void update(int i, ll x) {
  if (!vis[i] || x > val[i]) val[i] = x;
  vis[i] = 1;
}

struct SAM { // root 0
  static const int A = 26;
  static const int M = N<<1;
  static const char C = 'a';
  int sz, last, len[M], link[M], nex[M][A], tag[M];
  void init() {
    memset(nex, 0, sizeof(int)*A*sz);
    link[0] = -1; sz = 1; last = 0;
  }
  int extend(int c) {
    int cur = sz++, p = last;
    len[cur] = len[last]+1;
    for (; ~p && !nex[p][c]; p = link[p]) nex[p][c] = cur;
    if (p == -1) return link[cur] = 0, cur;
    int q = nex[p][c];
    if (len[p]+1 == len[q]) return link[cur] = q, cur;
    int clone = sz++;
    memcpy(nex[clone], nex[q], sizeof nex[q]);
    link[clone] = link[q];
    len[clone] = len[p]+1;
    for (; ~p && nex[p][c] == q; p = link[p]) nex[p][c] = clone;
    link[q] = link[cur] = clone;
    return cur;
  }
  void insert(const string &s) {
    init();
    for (int i = 0; i < (int)s.size(); ++i) {
      st[last = extend(s[i]-C)].insert(a[i]);
    }
  }
  void build() { // topo on parent tree
    static int t[M], rk[M];
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
    for (int _ = sz-1, i, j; _; --_) { // assert(rk[0] == 0);
      i = rk[_];
      j = link[i];
      ll num = st[i].size();
      num = num*(num-1)/2;
      cnt[len[i]] += num;
      cnt[len[j]] -= num;
      if (st[i].size() >= 2u) update(len[i], query(st[i]));
      my_merge(st[j], st[i]);
      if (vis[len[i]]) update(len[j], val[len[i]]);
    }
  }
} sam;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    st[0].insert(a[i]);
  }
  val[0] = query(st[0]);
  reverse(s.begin(), s.end());
  reverse(a, a+n);
  sam.insert(s);
  sam.build();
  st[0].clear();
  for (int i = n-1; i; --i) {
    cnt[i] += cnt[i+1];
    if (vis[i+1]) update(i, val[i+1]);
  }
  cnt[0] = n*(n-1ll)/2;
  for (int i = 0; i < n; ++i) {
    cout << cnt[i] << ' ' << val[i] << '\n';
  }
  return 0;
}