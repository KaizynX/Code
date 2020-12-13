#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n;
int s1[N];
char s2[N];

signed main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> s1[i];
  for (int i = 1; i < n; ++i) cin >> s2[i];
  for (int i = n-1; i; --i) {
    if (s2[i] == '+') {
      s1[i] = s1[i]+s1[i+1];
    } else if (s2[i] == '-') {
      s1[i] = s1[i]-s1[i+1];
    } else if (s2[i] == '*') {
      s1[i] = s1[i]*s1[i+1];
    } else {
      if (s1[i+1] == 0) {
        cout << "ERROR: " << s1[i] << "/0\n"; 
        return 0;
      }
      s1[i] = s1[i]/s1[i+1];
    }
  }
  cout << s1[1] << endl;
  return 0;
}