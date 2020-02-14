#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int T, n, x;
int s[N], t[N];
string str;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> x >> str;
        memset(t, 0, sizeof(int)*(n+3));
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i-1]+(str[i-1] == '1');
            ++t[s[i]];
        }
        if (x < 0 || (x <= s[n] && !t[x])) {
            cout << 0 << endl;
            continue;
        }
        if (x == 0 && s[n] == 0) {
            cout << -1 << endl;
            continue;
        }
        if (x < s[n]) {
            cout << t[x] << endl;
            continue;
        }
        x %= s[n];
        t[0] += t[s[n]];
        cout << t[x] << endl;
    }
    return 0;
}
