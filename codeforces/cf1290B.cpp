#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

string s;
int q, l, r, n;
int pre[N][26], bac[N][26], cnt[N][26], now[26];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s >> q;
    n = s.length();
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            pre[i][j] = pre[i-1][j];
            cnt[i][j] = cnt[i-1][j];
        }
        pre[i][s[i-1]-'a'] = i;
        ++cnt[i][s[i-1]-'a'];
    }
    for (int j = 0; j < 26; ++j)
        bac[n+1][j] = n+1;
    for (int i = n; i; --i) {
        for (int j = 0; j < 26; ++j)
            bac[i][j] = bac[i+1][j];
        bac[i][s[i-1]-'a'] = i;
    }
    while (q--) {
        cin >> l >> r;
        if (l == r) { cout << "Yes\n"; continue; }
        int flag = 0;
        for (int i = 0; i < 26; ++i)
            if ((now[i] = cnt[r][i]-cnt[l-1][i]) == r-l+1)
                flag = 1;
        if (flag) { cout << "No\n"; continue; }
        if (s[l-1] != s[r-1]) { cout << "Yes\n"; continue; }
        int p = l, c;
        for (int i = 0; i < 26; ++i) {
            if (i != s[r-1]-'a' && pre[r][i] > p) {
                p = pre[r][i];
                c = i;
            }
        }
        if (now[s[r-1]-'a']+now[c] == r-l+1) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}
