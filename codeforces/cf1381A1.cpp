/*
 * @Author: Kaizyn
 * @Date: 2020-07-21 22:16:31
 * @LastEditTime: 2020-07-21 22:46:47
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
string s;
int a[N], b[N];
vector<int> res;

inline void rev(const int &p) {
  reverse(a+1, a+p+1);
  for (int i = 0; i <= p; ++i) {
    a[i] ^= 1;
  }
}

inline void solve() {
  res.clear();
  cin >> n;
  cin >> s;
  for (int i = 1; i <= n; ++i) a[i] = s[i-1]-'0';
  cin >> s;
  for (int i = 1; i <= n; ++i) b[i] = s[i-1]-'0';

  for (int i = n; i > 1; --i) {
    if (a[i] == b[i]) continue;
    if (a[1] == a[i]) {
      res.emplace_back(i);
      rev(i);
    } else {
      res.emplace_back(1);
      a[0] ^= 1;
      res.emplace_back(i);
      rev(i);
    }
  }
  if (a[1] != b[1]) res.emplace_back(1);
  cout << res.size();
  for (const int &i : res) cout << " " << i;
  cout << endl;
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