/*
 * @Author: Kaizyn
 * @Date: 2020-05-23 13:23:54
 * @LastEditTime: 2020-05-23 13:32:00
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

int n, k;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> k;
  string s = string(n, 'z');
  s[0] = 'b';
  for (int i = 1; i < k; ++i) s[i] = 'a';
  cout << s << endl;
  return 0;
}