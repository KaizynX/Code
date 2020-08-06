/*
 * @Author: Kaizyn
 * @Date: 2020-07-19 18:30:41
 * @LastEditTime: 2020-07-19 18:40:34
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;
const string S = "abacaba";

int n;
int f[N], suf_sum[N];
string s;

inline void solve() {
  cin >> n >> s;
  memset(f, 0, sizeof(int)*n);
  for (int i = n-7; i >= 0; --i) {
    f[i] = s.substr(i, 7) == S;
    suf_sum[i] = suf_sum[i+1]+f[i];
  }
  if (suf_sum[0] > 1) return cout << "No" << endl, void();
  for (int i = 0; i+6 < n; ++i) {
    int flag = 1;
    for (int j = 0; j < 7; ++j) {
      if (s[i+j] == '?' || s[i+j] == S[j]) continue;
      flag = 0;
      break;
    }
    if (flag && suf_sum[i+1] == 0) {
      cout << "Yes" << endl;
      for (int j = 0; j < i; ++j) cout << (s[j] == '?' ? 'z' : s[j]);
      cout << S;
      for (int j = i+7; j < n; ++j) cout << (s[j] == '?' ? 'z' : s[j]);
      cout << endl;
      return;
    }
  }
  cout << "No" << endl;
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