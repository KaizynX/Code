/*
 * @Author: Kaizyn
 * @Date: 2020-05-20 21:21:24
 * @LastEditTime: 2020-05-21 14:21:46
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n, m;
map<pair<long, long>, int> mp;
int cnt[N][2];
long long pw2[N];

inline int get_id(const long long &a, const long long &b) {
  if (mp.count({a, b})) return mp[{a, b}];
  else return mp[{a, b}] = ++m;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  int o = 0;
  long long a, b, g;
  for (int i = 1; i <= n; ++i) {
    cin >> a >> b;
    if (a == 0 && b == 0) {
      ++o;
      continue;
    } else if (a == 0) {
      ++cnt[get_id(0, 1)][0];
    } else if (b == 0) {
      ++cnt[get_id(0, 1)][1];
    } else {
      g = __gcd(abs(a), abs(b));
      a /= g; b /= g;
      if (a < 0) a = -a, b = -b;
      int id = b > 0 ? get_id(a, b) : get_id(-b, a);
      ++cnt[id][b > 0 ? 1 : 0];
    }
  }
  pw2[0] = 1;
  for (int i = 1; i <= n; ++i) pw2[i] = pw2[i-1]*2%MOD;
  long long res = 1;
  for (int i = 1; i <= m; ++i) {
    (res *= pw2[cnt[i][0]]+pw2[cnt[i][1]]-1) %= MOD;
  }
  --res; // choose none
  res += o;
  cout << (res+MOD)%MOD << endl;
  return 0;
}