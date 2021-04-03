/*
 * @Author: Kaizyn
 * @Date: 2021-04-03 22:13:15
 * @LastEditTime: 2021-04-03 22:48:18
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n;
vector<int> p;
string s, a, b;

inline bool check(string &str) {
  int t = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == '(') ++t;
    else --t;
    if (t < 0) return false;
  }
  return true;
}

inline bool solve() {
  cin >> n >> s;
  p.clear();
  a = b = s;
  int t = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    if (s[i]-'0') {
      p.emplace_back(i);
      a[i] = b[i] = '(';
    } else {
      ++j;
      if (j&1) {
        a[i] = '(';
        b[i] = ')';
      } else {
        a[i] = ')';
        b[i] = '(';
      }
    }
    if (a[i] == '(') ++t;
    else --t;
  }
  #ifdef DEBUG
  cout << a << '\n' << b << '\n';
  #endif
  while (t > 0 && p.size()) {
    int i = p.back();
    p.pop_back();
    a[i] = b[i] = ')';
    t -= 2;
  }
  #ifdef DEBUG
  cout << a << '\n' << b << '\n';
  #endif
  if (check(a) && check(b)) return true;
  else return false;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    if (solve()) {
      cout << "YES\n";
      cout << a << '\n' << b << '\n';
    } else {
      cout << "NO\n";
    }
    // cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}