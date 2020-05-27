/*
 * @Author: Kaizyn
 * @Date: 2020-05-23 19:56:18
 * @LastEditTime: 2020-05-23 21:13:14
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 1e18;

long long n, a, b, c, d;
map<long long, long long> mp;

inline void update(const long long &x, const long long &y) {
  if (mp.count(x)) mp[x] = min(mp[x], y);
  else mp.insert({x, y});
}

inline void solve() {
  mp.clear();
  cin >> n >> a >> b >> c >> d;
  mp[n] = 0;
  while (mp.size()) {
    auto p = *(--mp.end());
    long long x = p.first, y = p.second;
    if (x == 0) return cout << y << endl, void();
    update(x/2, y+a+(x%2)*d);
    update(x/2+1, y+a+(2-x%2)*d);
    update(x/3, y+b+(x%3)*d);
    update(x/3+1, y+b+(3-x%3)*d);
    update(x/5, y+c+(x%5)*d);
    update(x/5+1, y+c+(5-x%5)*d);
    if (x < INF/d) update(0, y+x*d);
    mp.erase(--mp.end());
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}