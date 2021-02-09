/*
 * @Author: Kaizyn
 * @Date: 2021-01-11 11:08:24
 * @LastEditTime: 2021-01-11 15:56:41
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e6+7;
#define log(x) (31-__builtin_clz(x))

int n, k;
int vis[N<<1];
string s;

string magic(int x, int len) {
  string r;
  while (x) {
    r += x%2+'0';
    x >>= 1;
  }
  while ((int)r.size() < len) r += '0';
  reverse(r.begin(), r.end());
  return r;
}

inline void solve() {
  cin >> n >> k >> s;
  int z = n-k+1, kk = 0, zero = 0, val = 0;
  while (1<<kk <= z) ++kk;
  kk = min(kk, k);
  // kk > 0
  memset(vis, 0, sizeof(int)*(1<<kk));
  for (int i = 0; i < k-kk-1; ++i) {
    zero += s[i] == '0';
  }
  for (int i = k-kk; i < k-1; ++i) {
    val = val*2+s[i]-'0';
  }
  val <<= 1;
  for (int i = 0; i <= n-k; ++i) {
    val += s[i+k-1]-'0';
    if (k > kk) zero += s[i+k-kk-1] == '0';
    if (!zero) vis[val] = 1;
    if (k > kk) zero -= s[i] == '0';
    val -= (s[i+k-kk]-'0')<<(kk-1);
    val <<= 1;
  }
  for (int i = 0; i < 1<<kk; ++i) {
    if (!vis[((1<<kk)-1)^i]) {
      cout << "YES" << endl;
      cout << string(k-kk, '0') << magic(i, kk) << endl;
          // << setfill('0') << setw(kk) << i << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}