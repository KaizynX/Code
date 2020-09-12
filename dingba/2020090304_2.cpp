/*
 * @Author: Kaizyn
 * @Date: 2020-09-03 19:03:01
 * @LastEditTime: 2020-09-03 19:38:14
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
string s;
map<string, int> dp;

int dfs(string str) {
  // cout << str << endl;
  if (str.size() < 3) return INF;
  if (dp.count(str)) return dp[str];
  int res = INF, cnt = 1, len = (int)str.size();
  for (int i = 1; i < len-1; ++i) {
    if (str[i] == str[i-1]) ++cnt;
    else cnt = 1;
    if (cnt >= 3) res = min(res, dfs(str.substr(0, i-cnt+1)+str.substr(i+1))+1);
  }
  if (str[len-1] == str[len-2]) ++cnt;
  else cnt = 1;
  if (cnt == len) return 1;
  else if (cnt >= 3) res = min(res, dfs(str.substr(0, len-cnt))+1);
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> s;
  int res = dfs(s);
  if (res >= INF) cout << "No" << endl;
  else cout << "Yes\n" << res << endl;
  return 0;
}