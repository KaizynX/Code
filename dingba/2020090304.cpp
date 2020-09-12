/*
 * @Author: Kaizyn
 * @Date: 2020-09-03 19:03:01
 * @LastEditTime: 2020-09-03 19:20:42
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1<<20;

int n;
int a[20];
string s;
int dp[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for (int b = 0; b < 1<<20; ++b) {
    dp[b] = INF;
    for (n = 0; 1<<n <= b; ++n) a[n] = (b>>n)&1;
    for (int i = 1, cnt = 1, c; i < n; ++i) {
      if (a[i] != a[i-1]) cnt = 1;
      else ++cnt;
      if (cnt >= 3) {
        c = (b&((1<<(i-cnt))-1))|(b>>(i+1)<<(i-cnt));
        dp[b] = min(dp[b], dp[c]+1);
      }
      if (cnt == n) dp[b] = 1;
    }
  }
  cin >> n >> s;
  int x = 0;
  for (int i = 0; i < n; ++i) x = x*2+s[i]-'0';
  if (dp[x] >= INF) return cout << "No" << endl, 0;
  cout << "Yes" << endl << dp[x] << endl;
  return 0;
}