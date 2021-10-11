/*
 * @Author: Kaizyn
 * @Date: 2021-10-10 12:54:00
 * @LastEditTime: 2021-10-10 13:32:20
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
const int N = 5e5+7;
#define int ll

int n, m;
int a[N];
vector<ll> va[N];
ll s[N];
map<ll, int> fir, mp;

ll Mod(ll x, ll mod) {
  mod = abs(mod);
  x%=mod;
  if (x < 0) x += mod;
  return x;
}

int magic(ll x) {
  if (mp.count(x)) return mp[x];
  return mp[x] = mp.size();
}

inline void solve() {
  fir.clear();
  mp.clear();
  // scanf("%d%d", &n, &m);
  scanf("%lld%lld", &n, &m);
  for (int i = 0; i < n; ++i) {
    // scanf("%d", a+i+1);
    scanf("%lld", a+i+1);
    s[i+1] = s[i]+a[i+1];
    if (!fir.count(s[i])) fir[s[i]] = i;
  }
  if (s[n] == 0) {
    ll x;
    for (int i = 1; i <= m; ++i) {
      scanf("%lld", &x);
      // printf("%d\n", fir.count(x) ? fir[x] : -1);
      printf("%lld\n", fir.count(x) ? fir[x] : -1);
    }
    return;
  }
  for (int i = 0; i < n; ++i) {
    va[magic(Mod(s[i], s[n]))].emplace_back(s[i]);
  }
  for (int i = 0; i < n; ++i) {
    sort(va[i].begin(), va[i].end());
    va[i].erase(unique(va[i].begin(), va[i].end()), va[i].end());
  }
  ll x, y, ans;
  for (int i = 1; i <= m; ++i) {
    scanf("%lld", &x);
    y = Mod(x, s[n]);
    if (!mp.count(y)) {
      ans = -1;
    } else {
      y = mp[y];
      if (s[n] > 0) {
        auto it = upper_bound(va[y].begin(), va[y].end(), x);
        if (it == va[y].begin()) {
          ans = -1;
        } else {
          --it;
          ans = fir[*it]+(x-*it)/s[n]*n;
        }
      } else {
        auto it = lower_bound(va[y].begin(), va[y].end(), x); 
        if (it == va[y].end()) {
          ans = -1;
        } else {
          ans = fir[*it]+(x-*it)/s[n]*n;
        }
      }
    }
    printf("%lld\n", ans);
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // scanf("%d", &T);
  scanf("%lld", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 0; i < n; ++i) va[i].clear();
  }
  return 0;
}