#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int q, n;
int cnt[2][26], tot[2];
string s[2];

int main()
{
    cin >> q;
    while (q--) {
        cin >> n;
        int flag = 0;
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < 2; ++i) {
            cin >> s[i];
            for (int j = 0; j < n; ++j)
                ++cnt[i][s[i][j]-'a'];
        }
        flag = 1;
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] != cnt[1][i]) {
                flag = 0;
                break;
            }
        }
        if (!flag) {
            cout << "NO" << endl;
            continue;
        }
        flag = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] > 1 || cnt[1][i] > 1) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
            continue;
        }

        memset(cnt, 0, sizeof cnt);
        tot[0] = tot[1] = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = s[i][j]-'a'+1; k < 26; ++k)
                    tot[i] += cnt[i][k];
                ++cnt[i][s[i][j]-'a'];
            }
        }
        cout << (tot[0]%2 == tot[1]%2 ? "YES" : "NO") << endl;
    }
    return 0;
}
