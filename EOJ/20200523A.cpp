/*
 * @Author: Kaizyn
 * @Date: 2020-05-23 12:27:51
 * @LastEditTime: 2020-05-23 13:18:30
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 20;

int n, m;
int a[N][N];
string s;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  memset(a, -1, sizeof a);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    a[s[0]-'A'+1][s[1]-'0'] = 1;
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> s;
    a[s[0]-'A'+1][s[1]-'0'] = 0;
  }
  cout << (n > m ? "Cuber QQ" : "Quber CC") << endl;
  return 0;
}