/*
 * @Author: Kaizyn
 * @Date: 2020-06-23 22:01:44
 * @LastEditTime: 2020-06-23 22:27:15
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n, k;
int a[N], w[N];
vector<int> v;

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= k; ++i) {
    cin >> w[i];
  }
  sort(a+1, a+n+1);
  sort(w+1, w+k+1);
  reverse(w+1, w+k+1);
  long long res = 0;
  for (int i = 1, j = 1; i <= k; ++i) {
    v.clear();
    v.emplace_back(a[n-k+i]);
    while ((int)v.size() < w[i]) v.emplace_back(a[j++]);
    // sort(v.begin(), v.end());
    // res += v.front()+v.back();
    res += a[n-k+i]+*min_element(v.begin(), v.end());
  }
  cout << res << endl;
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