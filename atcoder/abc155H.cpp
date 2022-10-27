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

using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;
const int M = N << 1;

ll n;
int m, Q, block;
ll D[N], L[N], R[N], K[N];
ll has[N], bsum[N], btime[N], bk[N];
vector<ll> dis;

/*
struct FenKuai {
  typedef long long T;
  int t; // 每组大小
  static const int NN = static_cast<int>(sqrt(N))+7;
  T a[N], sum[NN], add[NN];
  FenKuai() {
    memset(a, 0, sizeof a);
    memset(sum, 0, sizeof sum);
    memset(add, 0, sizeof add);
  }
  void init() {
    t = static_cast<int>(sqrt(n)+0.5);
    for (int i = 0; i < n; ++i) sum[i/t] += a[i];
  }
  void update(int x, T k) { a[x] += k; sum[x/t] += k; }
  void update(int x, int y, T k) {
    for ( ; x <= y && x%t; ++x) a[x] += k, sum[x/t] += k;
    for ( ; x+t-1 <= y; x += t) sum[x/t] += k*t, add[x/t] += k;
    for ( ; x <= y; ++x) a[x] += k, sum[x/t] += k;
  }
  T query(int x) { return a[x]+add[x/t]; }
  T query(int x, int y) {
    T res = 0;
    for ( ; x <= y && x%t; ++x) res += a[x]+add[x/t];
    for ( ; x+t-1 <= y; x += t) res += sum[x/t];
    for ( ; x <= y; ++x) res += a[x]+add[x/t];
    return res;
  }
};
*/

int lb(ll x) {
  return lower_bound(dis.begin(), dis.end(), x) - dis.begin() + 1;
}

ll calc_sum(ll l, ll r) {
  return (l + r) * (r - l + 1) / 2 % MOD;
}

inline void solve() {
  cin >> n >> Q;
  for (int i = 1; i <= Q; ++i) {
    cin >> D[i] >> L[i] >> R[i];
    D[i] %= MOD;
    ++R[i];
    dis.emplace_back(L[i]);
    dis.emplace_back(R[i]);
  }
  sort(dis.begin(), dis.end());
  dis.erase(unique(dis.begin(), dis.end()), dis.end());
  m = dis.size() - 1;
  block = sqrt(m) + 1;
  for (int i = 1; i <= m; ++i) {
    K[i] = calc_sum(dis[i - 1], dis[i] - 1);
    (bk[i / block] += K[i]) %= MOD;
  }
  for (int i = 1; i <= Q; ++i) {
    L[i] = lb(L[i]);
    R[i] = lb(R[i]) - 1;
    int p = L[i];
    ll ans = 0;
    for ( ; p <= R[i] && p % block; ++p) {
      ans += has[p] + (D[i] - btime[p]) * K[p] % MOD;
      bsum[p / block] -= has[p];
      has[p] = -(D[i] - btime[p]) * K[p] % MOD;
      bsum[p / block] += has[p];
    }
    for (int b; p + block - 1 <= R[i]; p += block) {
      b = p / block;
      ans += bsum[b] + (D[i] - btime[b]) % MOD * bk[p] % MOD;
      bsum[b] = 0;
      btime[b] = D[i];
    }
    for ( ; p <= R[i]; ++p) {
      ans += has[p] + (D[i] - btime[p]) % MOD * K[p] % MOD;
      has[p] = -(D[i] - btime[p]) * K[p] % MOD;
    }
    cout << (ans % MOD + MOD) % MOD << '\n';
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