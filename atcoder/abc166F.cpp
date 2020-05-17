/*
 * @Author: Kaizyn
 * @Date: 2020-05-07 10:19:05
 * @LastEditTime: 2020-05-07 12:45:57
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;

int n;
long long a[3];
string s[N], res;

int main()
{
    cin >> n >> a[0] >> a[1] >> a[2];
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) {
        int x = s[i][0]-'A', y = s[i][1]-'A';
        if (a[x]+a[y] == 0) return cout << "No\n", 0;
        if (a[y] == 0) swap(x, y);
        if (a[x] && a[y] && i < n && s[i] != s[i+1]) {
            if (s[i+1][0]-'A' == y || s[i+1][1]-'A' == y) swap(x, y);
        }
        ++a[x]; --a[y];
        res += char(x+'A'); res += '\n';
    }
    cout << "Yes\n" << res;
    return 0;
}