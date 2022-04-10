/*
 * @Author: Kaizyn
 * @Date: 2022-04-04 16:03:09
 * @LastEditTime: 2022-04-04 18:14:27
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
const int N = 20;
using uint = uint32_t;

ll pw10[N];

vector<int> magic(ll x) {
  if (x == 0) return vector<int>{0};
  vector<int> res;
  while (x) {
    res.emplace_back(x % 10);
    x /= 10;
  }
  return res;
}

int cmp(int x, int y) {
  if (x < y) return 0;
  if (x == y) return 1;
  return 2;
}

ll calc(int len, vector<int> &vec, int num) {
  if ((int)vec.size() < len) return 0;
  ll suf = 0, pre = 1, ans = 0;
  int cnt = 0, flag = 1;
  for (int i = (int)vec.size() - 1; i >= len; --i) {
    suf = suf * 10 + vec[i];
  }
  for (int i = 0; i < (int)vec.size(); ++i) {
    if (cmp(vec[i], num) != 1) flag = cmp(vec[i], num);
    cnt += vec[i] == num;
    if (i - len >= 0) cnt -= vec[i - len] == num;
    if (i < len - 1) continue;

    if (cnt == len) { // ==
      ans += max(0ll, suf - (num == 0))* pw10[i - len + 1] + pre;
    } else if (flag == 0) { // vec < num
      ans += max(0ll, suf - (num == 0))* pw10[i - len + 1];
    } else { // vec > num
      ans += (suf + (num != 0)) * pw10[i - len + 1];
    }

    suf /= 10;
    pre += vec[i - len + 1] * pw10[i - len + 1];
  }
  return ans;
}

int check(ll x) {
  if (x == 0) return 1;
  int cur = 0, ans = 0, last = -1;
  while (x) {
    int y = x % 10;
    x /= 10;
    if (y == last) {
      ++cur;
      ans = max(ans, cur);
    } else {
      last = y;
      cur = 1;
    }
  }
  return ans;
}

ll ffff(ll val, ll vi, ll vj, int len) {
  ll vv = val;
  for(int i=0;i<len+len;i++)vv/=10;
  for (int i = 0; i < len; ++i)  {
    vv = vv * 10 + vi;
  }
  for (int i = 0; i < len; ++i)  {
    vv = vv * 10 + vj;
  }
  return vv;
}

inline void solve() {
  ll lv, rv;
  cin >> lv >> rv;
  if (rv - lv <= 1000) {
    map<int, int> mp;
    for (ll i = lv; i <= rv; ++i) {
      ++mp[check(i)];
    }
    cout << mp.rbegin()->first << ' ' << mp.rbegin()->second << '\n';
    return;
  }
  auto L = magic(lv);
  auto R = magic(rv);
  int spj = 0, spjn = 0;
  if (L.size() == R.size()) {
    int sz = L.size(), cur = 0, last = -1;
    while (spjn < sz && L[sz - spjn - 1] == R[sz - spjn - 1]) {
      if (L[sz - spjn - 1] == last) {
        ++cur;
      } else {
        cur = 1;
        last = L[sz - spjn - 1];
      }
      spj = max(spj, cur);
      ++spjn;
    }
  }
  --lv;
  L = magic(lv);
  for (int len = R.size(); len; --len) {
    ll ans = 0;
    for (int i = 0; i < 10; ++i) {
      ans += calc(len, R, i) - calc(len, L, i);
      #ifdef DEBUG
      printf("calc(%d,%lld,%d)=%lld\n", len, rv, i, calc(len, R, i));
      printf("calc(%d,%lld,%d)=%lld\n", len, lv, i, calc(len, L, i));
      #endif
    }
    if (ans) {
      if (len <= spj) {
        ans = rv - lv;
      } else if (L.size() == R.size() && L.size() >= len + len) {
        for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j) if (i != j) {
          int num=ffff(lv, i, j, len);
          if(num>lv&&num<=rv)ans--;
        }
      }
      cout << len << ' ' << ans << '\n';
      break;
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  pw10[0] = 1;
  for (int i = 1; i <= 18; ++i) pw10[i] = pw10[i - 1] * 10;
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
// 12 19
// 1190 1200
// 11119990 11120000