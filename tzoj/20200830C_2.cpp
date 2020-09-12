/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 13:30:48
 * @LastEditTime: 2020-08-30 16:45:31
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

int n, a, b;
char s[N];

inline void solve() {
  if (n) {
    char c = getchar();
    n = 0;
    while ((c = getchar()) != '\n') ++n;
    printf("%d\n", n);
    /*
    gets(s);
    int cnt = 0;
    for (int i = 0; s[i]; ++i) {
      // if (s[i] != ' ') ++cnt;
      if (s[i] >= 'a' && s[i] <= 'z') ++cnt;
      if (s[i] >= 'A' && s[i] <= 'Z') ++cnt;
    }
    printf("%d\n", cnt);
    */
  } else {
    scanf("%d %d", &a, &b);
    printf("%.2f\n", 1.0*a/b);
  }
}

signed main() {
  while (scanf("%d", &n) == 1) solve();
  return 0;
}