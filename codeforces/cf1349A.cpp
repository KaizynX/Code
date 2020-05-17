/*
 * @Author: Kaizyn
 * @Date: 2020-05-12 20:33:08
 * @LastEditTime: 2020-05-12 20:55:41
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n;
int a[N];
map<int, multiset<int>> mp;
map<int, int> cnt;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD)
{
    long long res = 1, x = a;
    for (H i = p; i; i >>= 1, x = x*x%mo)
        if (i&1) res = res*x%mo;
    return static_cast<T>(res);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    #ifdef DEBUG
    cout << i << endl;
    #endif
    for (int j = 2; j*j <= a[i]; ++j) {
      if (a[i]%j) continue;
      int k = 0;
      while (a[i]%j == 0) a[i] /= j, ++k;
      mp[j].insert(k);
      if (mp[j].size() > 2) mp[j].erase(--mp[j].end());
      ++cnt[j];
      #ifdef DEBUG
      cout << j << " " << k << endl;
      #endif
    }
    if (a[i] > 1) {
      int j = a[i];
      mp[j].insert(1);
      if (mp[j].size() > 2) mp[j].erase(--mp[j].end());
      ++cnt[j];
      #ifdef DEBUG
      cout << j << " " << 1 << endl;
      #endif
    }
  }
  #ifdef DEBUG
  cout << "***\n";
  #endif
  long long res = 1;
  for (auto &p : mp) {
    if (cnt[p.first] < n-1) continue;
    auto &st = p.second;
    int k = 0;
    if (cnt[p.first] == n-1) k = *st.begin();
    else k = *(++st.begin());
    res *= qpow(p.first, k);
    #ifdef DEBUG
    cout << p.first << " " << k << endl;
    #endif
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}