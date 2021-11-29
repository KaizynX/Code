/*
 * @Author: Kaizyn
 * @Date: 2021-11-26 20:23:14
 * @LastEditTime: 2021-11-26 20:53:57
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
const int N = 1e5+7;
#ifdef DEBUG
const int A = 100;
#else
const int A = 2e7;
#endif

struct Euler {
  vector<int> prime, check;
  int& operator [](const int &i) { return check[i]; }
  void init(int n) {
    prime.clear();
    check = vector<int>(n+1);
    check[1] = false;
    for (int i = 2; i <= n; ++i) {
      if (!check[i]) prime.emplace_back(i), check[i] = i;
      for (const int &j : prime) {
        if (i*j > n) break;
        check[i*j] = j;
        if (i%j == 0) break;
      }
    }
  }
} E;

int n;
int a[A+1], vis[A+1], t[A+1];
ll dp[A+1];
vector<int> fac;

void get_fac(int x) {
  fac = vector<int>(1, 1);
  vector<int> tmp;
  while (E[x]) {
    tmp = fac;
    for (int y = E[x]; x%y == 0; x /= y) {
      for (int &i : tmp) i *= y;
      fac.insert(fac.end(), tmp.begin(), tmp.end());
    }
  }
}

template <typename T>
void MAX(T &x, const T &y) {
  if (y > x) x = y;
}

inline void solve() {
  cin >> n;
  for (int i = 1, b; i <= n; ++i) {
    cin >> b;
    ++a[b];
  }
  ll ans = 0;
  for (int i = A; i; --i) if (t[i]+a[i]) {
    get_fac(i);
    if (a[i]) for (int &j : fac) t[j] += a[i];
    dp[i] += (ll)t[i]*i;
    for (int &j : fac) MAX(dp[j], dp[i]-(ll)t[i]*j);
    MAX(ans, dp[i]);
  }
  #ifdef DEBUG
  orzarr(t, 7);
  orzarr(dp, 7);
  #endif
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  E.init(A);
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}