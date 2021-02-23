/*
 * @Author: Kaizyn
 * @Date: 2021-02-21 15:57:57
 * @LastEditTime: 2021-02-21 16:18:30
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
// const int N = ;

inline long long BSGS(long long a, long long x, long long m) { // a^n = x
  static map<long long, int> mmp;
  mmp.clear();
  long long t = sqrt(m)+1, b = 1, c = 1, res;
  for(int i = 0; i < t; ++i, b = b*a%m)
    mmp[x*b%m] = i;
  for(int i = 0; i <= t; ++i, c = c*b%m) { // b = a^t
    if(mmp.count(c)) {
      res = t*i-mmp[c];
      if(res > 0) return res;
    }
  }
  return -1;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  // b^l%p = n
  int p, b, n;
  cin >> p >> b >> n;
  int l = BSGS(b, n, p);
  if (~l) cout << l << '\n';
  else cout << "no solution\n";
  return 0;
}