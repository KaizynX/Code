/*
 * @Author: Kaizyn
 * @Date: 2020-10-17 21:01:31
 * @LastEditTime: 2020-10-17 21:17:17
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5+7;

int n;
string s;

bool check_circle() {
  int flag = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '<') flag = 0;
  }
  if (flag) return true;
  flag = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '>') flag = 0;
  }
  return flag;
}

inline int solve() {
  cin >> n >> s;
  if (check_circle()) return n;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '-' || s[(i+1)%n] == '-') ++res;
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}