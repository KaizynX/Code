/*
 * @Author: Kaizyn
 * @Date: 2020-05-15 14:35:48
 * @LastEditTime: 2020-05-15 19:29:46
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
const int K = 16;

int k;
long long a, b, s;
long long f[N][K];
long long pw[12][K];
map<long long, vector<int>> mp[K];

inline void init() {
  for (int i = 1; i <= 9; ++i) {
    pw[i][0] = 1;
    for (int j = 1; j <= 15; ++j) pw[i][j] = pw[i][j-1]*i;
  }
  for (k = 1; k <= 15; ++k) {
    for (int i = 0; i < 100000; ++i) {
      for (int x = i; x; x /= 10) f[i][k] += pw[x%10][k];
      mp[k][f[i][k]].emplace_back(i);
    }
  }
}

inline long long calc(const long long &v) {
  long long res = 0;
  for (int i = 0; i < v/100000; ++i) {
    res += mp[k].count(s-f[i][k]) ? mp[k][s-f[i][k]].size() : 0;
  }
  if (!mp[k].count(s-f[v/100000][k])) return res;
  vector<int> &vec = mp[k][s-f[v/100000][k]];
  return res+upper_bound(vec.begin(), vec.end(), v%100000)-vec.begin();
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  init();
  while (cin >> a >> b >> k >> s) {
    cout << calc(b)-calc(a-1) << endl;
  }
  return 0;
}