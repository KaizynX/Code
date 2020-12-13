/*
 * @Author: Kaizyn
 * @Date: 2020-12-12 00:14:14
 * @LastEditTime: 2020-12-12 16:11:04
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

int n, op;
int a[N], path[N];
long long dp[N];
char o[N];

void print() {
  for (int i = 1; i < n; ++i) cout << a[i] << o[i];
  cout << a[n] << endl;
}

int ci(char &c) {
  if (c == '*') return 1;
  if (c == '+') return 2;
  if (c == '-') return 4;
  return 0;
}

char ic(int x) {
  if (x == 1) return '*';
  if (x == 2) return '+';
  if (x == 4) return '-';
  return '?';
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  string s;
  cin >> s;
  op = 0;
  for (char &c : s) op |= ci(c);
  if (op == 6) op = 2;
  if (__builtin_popcount(op) == 1) {
    for (int i = 1; i < n; ++i) o[i] = ic(op);
  } else if (op == 5) {
    for (int i = 1; i <= n; ++i) {
      o[i] = '*';
      if (!a[i]) o[i-1] = '-';
    }
  } else { // +*
    a[n+1] = 0;
    vector<int> pos, num;
    for (int R = 1, L = 0, l, r; R <= n+1; ++R) if (!a[R]) {
      o[R-1] = o[R] = '+';
      l = L+1; r = R-1; L = R;
      while (l <= r && a[l] == 1) o[l-1] = o[l] = '+', ++l;
      while (l <= r && a[r] == 1) o[r-1] = o[r] = '+', --r;
      if (l > r) continue;
      pos.clear(); num.clear();
      long long mul = 1;
      for (int i = l, one = 0; i <= r; ++i) {
        if (a[i] == 1) {
          ++one;
        } else {
          num.emplace_back(one);
          pos.emplace_back(i);
          if ((mul *= a[i]) > 1e16) break;
          one = 0;
        }
      }
      if (mul > 1e16) {
        for (int i = l; i < r; ++i) o[i] = '*';
        continue;
      }
      dp[0] = path[0] = 0;
      for (int i = 1; i <= (int)pos.size(); ++i) {
        mul = 1;
        dp[i] = 0;
        for (int j = i-1; j >= 0; --j) { // +[j+1, i](*)+
          mul *= a[pos[j]];
          if (dp[i] < dp[j]+num[j]+mul) {
            dp[i] = dp[j]+num[j]+mul;
            path[i] = j;
          }
        }
      }
      for (int i = pos.size(), j, k; i; i = j) {
        j = path[i];
        k = j ? pos[j-1]+1 : l;
        o[k-1] = '+';
        while (k < pos[i-1] && a[k] == 1) o[k] = '+', ++k;
        while (k < pos[i-1]) o[k] = '*', ++k;
      }
    }
  }
  print();
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
/*
3
4 1 2
+-*

5
4 1 1 1 2
+-*

11
3 1 1 1 1 3 1 1 1 1 3
+-*
*/
