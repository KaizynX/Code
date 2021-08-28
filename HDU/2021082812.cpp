/*
 * @Author: Kaizyn
 * @Date: 2021-08-28 12:35:14
 * @LastEditTime: 2021-08-28 13:00:40
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
const int N = 2e6+7;
const int M = 1e5+7;
typedef unsigned long long ull;

int n, m;
int p[M], vis[N];
ull f[N], qv[N];
int qt[N], head, tail;

template <typename T>
void update(T &x, T y) {
  if (y < x) x = y;
}

void print() {
  #ifdef DEBUG
  orzarr(f+1, n);
  #endif
  ull ans = 0, base = 1;
  for (int i = n; i; --i, base *= 23333) {
    if (~f[i]) ans += f[i]*base;
  }
  cout << ans << '\n';
}

bool spj() {
  ll mul = 1;
  for (int i = 1; i <= m; ++i) {
    mul *= p[i];
    #ifndef DEBUG
    if (mul > n) return false;
    #endif
  }
  for (int i = 1; i <= n; ++i) {
    if (i%mul == 0) {
      f[i] = -1;
      continue;
    }
    f[i] = INF;
    for (int j = 1, k; j <= m; ++j) {
      k = i-i%p[j];
      if (~f[k]) update(f[i], f[k]+1);
    }
  }
  print();
  return true;
}

inline void solve() {
  // scanf("%d%d", &n, &m);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> p[i]; //scanf("%d", p+i);
  #ifdef DEBUG
  spj();
  #else
  if (spj()) return;
  #endif
  memset(vis+1, 0, sizeof(int)*n);
  vis[0] = *max_element(p+1, p+m+1);
  for (int i = 1; i <= m; ++i) {
    for (int j = p[i]; j <= n; j += p[i]) {
      vis[j] = max(vis[j], p[i]);
    }
  }
  head = tail = 0;
  qv[tail] = 0; qt[tail] = vis[0]; ++tail;
  for (int i = 1; i <= n; ++i) {
    while (head < tail && qt[head] <= i) ++head;
    f[i] = qv[head]+1;
    if (!vis[i]) continue;
    while (head < tail && qv[tail-1] > f[i]) --tail;
    qv[tail] = f[i]; qt[tail] = i+vis[i]; ++tail;
  }
  print();
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // scanf("%d", &T);
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}