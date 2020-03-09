#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const double err = 1e-9;
const int INF = 1e9;
typedef pair<int, int> pii;

string s;
int cnt[N][26];
long long num[26][26];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    int n = s.length();
    cnt[0][s[0]-'a'] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            num[s[i]-'a'][j] += cnt[i-1][j];
            cnt[i][j] = cnt[i-1][j];
        }
        ++cnt[i][s[i]-'a'];
    }
    long long res = 0;
    for (int i = 0; i < 26; ++i) res = max(res, 1ll*cnt[n-1][i]);
    for (int i = 1; i < n; ++i)
        res = max(res, num[s[i]-'a'][s[i-1]-'a']);
    cout << res << endl;
    return 0;
}

