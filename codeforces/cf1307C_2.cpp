#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const double err = 1e-9;
const int INF = 1e9;
typedef pair<int, int> pii;

string s;
int cnt[26];
long long num[26][26];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    int n = s.length();
    cnt[s[0]-'a'] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 26; ++j)
            num[s[i]-'a'][j] += cnt[j];
        ++cnt[s[i]-'a'];
    }
    long long res = 0;
    for (int i = 0; i < 26; ++i) res = max(res, 1ll*cnt[i]);
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            res = max(res, num[i][j]);
    cout << res << endl;
    return 0;
}

