/*
 * @Author: Kaizyn
 * @Date: 2020-05-17 14:59:50
 * @LastEditTime: 2020-05-17 15:17:47
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

signed main() {
  freopen("I_large.txt", "r", stdin);
  freopen("20200517I.cpp", "w", stdout);
  int a, b, c;
  while (scanf("%d %d %d", &a, &b, &c) == 3) {
    printf("int f%d(){return dp[%d]==-1?dp[%d]=(f%d()+f%d())&1:dp[%d];}\n",a,a,a,b,c,a);
  }
  return 0;
}