/*
 * @Author: Kaizyn
 * @Date: 2020-08-23 16:25:30
 * @LastEditTime: 2020-08-23 16:27:25
 */
#include <set>
#include <map>
#include <list>
#include <queue>
#include <cmath>
#include <ctime>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
//#include<chrono>
//#include<unordered_set>
//#include<unordered_map>

// #define DEBUG
using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

int n;
int a[N][N];
string str;

inline void solve() {
  for (int i = 0; i < n; ++i) {
    cin >> str;
    for (int j = 0; j < n; ++j) {
      a[i][j] = str[j]-'0';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n) solve();
  return 0;
}