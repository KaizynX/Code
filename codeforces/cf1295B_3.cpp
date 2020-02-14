#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;

int T, n, x;
int s[N];
string str;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> x >> str;
        int res = x == 0, flag = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i-1]+(str[i-1] == '1' ? -1 : 1);
        }
        for (int i = 1; i <= n; ++i) {
            if (s[n] == 0 && s[i] == x) flag = 1;
            if ((s[n] < 0 && x <= s[i] && (x-s[i])%s[n] == 0) || 
                (s[n] > 0 && x >= s[i] && (x-s[i])%s[n] == 0)) ++res;
        }
        if (flag) cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}
