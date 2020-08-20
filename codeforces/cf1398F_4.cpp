/*
 * @Author: Kaizyn
 * @Date: 2020-08-15 11:19:25
 * @LastEditTime: 2020-08-15 11:57:21
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
int sum[2][N], nex[N], res[N];
char s[N];
vector<int> vl[N];

void update(const int &p) {
  for (int i = p; nex[i] > p && i >= 0; --i) nex[i] = p;
}

signed main() {
  scanf("%d%s", &n, s);
  sum[0][n] = sum[1][n] = 0;
  memset(nex, 0x3f, sizeof nex);
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == '?') {
      sum[0][i] = sum[0][i+1]+1;
      sum[1][i] = sum[1][i+1]+1;
    } else if (s[i] == '1') {
      sum[0][i] = 0;
      sum[1][i] = sum[1][i+1]+1;
    } else if (s[i] == '0') {
      sum[0][i] = sum[0][i+1]+1;
      sum[1][i] = 0;
    }
    vl[sum[1][i]].emplace_back(i);
    vl[sum[0][i]].emplace_back(i);
  }
  for (int len = n; len; --len) {
    int i = 0;
    // sort(vl[len].begin(), vl[len].end());
    reverse(vl[len].begin(), vl[len].end());
    for (const int &p : vl[len]) update(p);
    while (nex[i] < n) {
      i = nex[i]+len;
      ++res[len];
      // if (i >= n) break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", res[i], " \n"[i == n]);
  }
  return 0;
}