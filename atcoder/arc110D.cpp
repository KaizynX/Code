/*
 * @Author: Kaizyn
 * @Date: 2020-12-05 20:58:54
 * @LastEditTime: 2020-12-05 21:52:14
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 2e3+7;

namespace BigFac {
#define lon long long
lon a[110]={1,682498929,491101308,76479948,723816384,67347853,27368307,
625544428,199888908,888050723,927880474,281863274,661224977,623534362,
970055531,261384175,195888993,66404266,547665832,109838563,933245637,
724691727,368925948,268838846,136026497,112390913,135498044,217544623,
419363534,500780548,668123525,128487469,30977140,522049725,309058615,
386027524,189239124,148528617,940567523,917084264,429277690,996164327,
358655417,568392357,780072518,462639908,275105629,909210595,99199382,
703397904,733333339,97830135,608823837,256141983,141827977,696628828,
637939935,811575797,848924691,131772368,724464507,272814771,326159309,
456152084,903466878,92255682,769795511,373745190,606241871,825871994,
957939114,435887178,852304035,663307737,375297772,217598709,624148346,
671734977,624500515,748510389,203191898,423951674,629786193,672850561,
814362881,823845496,116667533,256473217,627655552,245795606,586445753,
172114298,193781724,778983779,83868974,315103615,965785236,492741665,
377329025,847549272,698611116};
lon calc(lon n, lon p = MOD) {
  lon now=n/10000000;
  lon ans=a[now];
  for(lon i=now*10000000+1;i<=n;i++)
    ans=ans*i%p;
  return ans%p;
}
}

struct Combination {
  int fac[N], inv[N];
  void init(const int &n) {
    fac[0] = inv[0] = fac[1] = inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      fac[i] = 1ll*fac[i-1]*i%MOD;
      inv[i] = 1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    for (int i = 2; i <= n; ++i) {
      inv[i] = 1ll*inv[i]*inv[i-1]%MOD;
    }
  }
  int A(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[p-q]%MOD : 0;
  }
  int C(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[q]%MOD*inv[p-q]%MOD : 0;
  }
};

template <typename T>
T exgcd(const T a, const T b, T &x, T &y) {
  if (!b) return x = 1, y = 0, a;
  T d = exgcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

template <typename T>
inline T mul_inverse(const T &a, const T &mo = MOD) {
  T x, y;
  exgcd(a, mo, x, y);
  return (x%mo+mo)%mo;
}

int n, m;
int a[N];
long long f[N];
Combination comb;

long long C(int n, int m) {
  /*
  long long res = 1, fac = 1;
  for (int i = 1; i <= n; ++i) {
    (fac *= i) %= MOD;
    if (i == m) (res *= mul_inverse(fac)) %= MOD;
    if (i == n-m) (res *= mul_inverse(fac)) %= MOD;
  }
  return res*fac%MOD;
  */
  if (m > n) return 0;
  return BigFac::calc(n)*mul_inverse(BigFac::calc(m)*BigFac::calc(n-m)%MOD)%MOD;
}

inline void solve() {
  cin >> n >> m;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  // cout << comb.C(m+n, sum+n) << endl;
  cout << C(m+n, sum+n) << endl;
}

signed main() {
  comb.init(2e3);
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}