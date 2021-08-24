/*
 * @Author: Kaizyn
 * @Date: 2021-08-24 12:58:15
 * @LastEditTime: 2021-08-24 14:24:55
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;

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
int a[N];
string s;
multiset<ll> st;
ll cnt[N], val[N];
vector<ll> add[N], del[N];
using Qs = __gnu_pbds ::priority_queue<int, greater<int>, pairing_heap_tag>;
using Qb = __gnu_pbds ::priority_queue<int, less<int>, pairing_heap_tag>;
Qs qs[N<<1];
Qb qb[N<<1];

template <typename T>
void update(T &q, int l1, int l2) {
  if (q.size() < 2u) return;
  ll x = q.top(); q.pop();
  ll y = q.top(); q.push(x);
  add[l1].emplace_back(x*y);
  del[l2].emplace_back(x*y);
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
      last = extend(s[i]-C);
      qs[last].push(a[i]);
      qb[last].push(a[i]);
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
      ll num = qs[i].size();
      num = num*(num-1)/2;
      cnt[len[i]] += num;
      cnt[len[j]] -= num;
      #ifdef DEBUG
      printf("i=%d,len[i]=%d,len[j]=%d\n", i, len[i], len[j]);
      orzeach(qs[i]);
      orzeach(qb[i]);
      #endif
      update(qs[i], len[i], len[j]);
      update(qb[i], len[i], len[j]);
      qs[j].join(qs[i]);
      qb[j].join(qb[i]);
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
    st.insert(a[i]);
  }
  int tmp = val[0] = *st.rbegin();
  st.erase(--st.end());
  val[0] *= *st.rbegin();
  st.insert(tmp);
  tmp = *st.begin();
  st.erase(st.begin());
  val[0] = max(val[0], 1ll**st.begin()*tmp);
  st.clear();

  reverse(s.begin(), s.end());
  reverse(a, a+n);
  sam.insert(s);
  sam.build();
  for (int i = n; i; --i) {
    cnt[i] += cnt[i+1];
    for (int j : del[i]) st.erase(st.find(j));
    for (int j : add[i]) st.insert(j);
    if (st.size()) val[i] = *st.rbegin();
  }
  cnt[0] = n*(n-1ll)/2;
  for (int i = 0; i < n; ++i) {
    cout << cnt[i] << ' ' << val[i] << '\n';
  }
  return 0;
}