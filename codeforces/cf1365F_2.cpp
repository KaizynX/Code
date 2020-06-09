/*
 * @Author: Kaizyn
 * @Date: 2020-06-08 00:18:33
 * @LastEditTime: 2020-06-08 00:22:26
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e2+7;

int n;
int a[N], b[N], c[N];
map<pii, int> mp;

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];

  if (n%2 && a[n/2+1] != b[n/2+1]) return false;
  mp.clear();
  for (int i = 1; i <= n/2; ++i) {
    if (a[i] > a[n-i+1]) swap(a[i], a[n-i+1]);
    if (b[i] > b[n-i+1]) swap(b[i], b[n-i+1]);
    ++mp[{a[i], a[n-i+1]}];
    --mp[{b[i], b[n-i+1]}];
  }
  for (const auto &p : mp) if (p.second != 0) return false;
  return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << endl;
  }
  return 0;
}