/*
 * @Author: Kaizyn
 * @Date: 2020-09-06 22:28:59
 * @LastEditTime: 2020-09-06 22:49:22
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

int n, k;
string s;
int cnt[3];

void add(char &c, int t) {
  if (c == '?') cnt[2] += t;
  else cnt[c-'0'] += t;
}

inline bool solve() {
  cin >> n >> k >> s;
  memset(cnt, 0, sizeof cnt);
  for (int i = k; i < n; ++i) {
    if (s[i] == '?' && s[i-k] == '?') continue;
    else if (s[i] == '?') s[i] = s[i-k];
    else if (s[i-k] == '?') s[i-k] = s[i];
    else if (s[i] != s[i-k]) return false;
  }
  for (int i = n-1; i >= k; --i) {
    if (s[i] == '?' && s[i-k] == '?') continue;
    else if (s[i] == '?') s[i] = s[i-k];
    else if (s[i-k] == '?') s[i-k] = s[i];
    else if (s[i] != s[i-k]) return false;
  }
  for (int i = 0; i < k; ++i) add(s[i], 1);
  if (cnt[0] <= k/2 && cnt[0]+cnt[2] >= k/2) return true;
  if (cnt[1] <= k/2 && cnt[1]+cnt[2] >= k/2) return true;
  return false;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}