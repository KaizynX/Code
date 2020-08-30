/*
 * @Author: Kaizyn
 * @Date: 2020-08-23 12:40:06
 * @LastEditTime: 2020-08-23 16:24:06
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
const int N = 1e6+7;

int n;
long long res[N];

template <typename T>
T exgcd(const T a, const T b, T &x, T &y) {
  if (!b) { x = 1; y = 0; return a; }
  T d = exgcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

template <typename T>
inline T mul_inverse(const T &a, const T &mo = MOD) {
  T x, y;
  exgcd(a, mo, x, y);
  return (x%mo+mo)%mo;
}

inline void init() {
  res[1] = 6; res[2] = 30;
  for (int i = 3; i <= 1000000; ++i) {
    res[i] = (res[i-1]*(i+1)%MOD*(7*i-4)+res[i-2]*8*(i-2)%MOD*(i-2))%MOD;
    res[i] = res[i]*mul_inverse(i*(i+1ll))%MOD;
  }
}

signed main() {
  init();
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n) cout << res[n] << endl;
  return 0;
}