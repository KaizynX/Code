#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

int n, m, res = 2;
string str;
vector<int> cnt;
vector<vector<int>> mp, s, t;

int main()
{
    cin >> n >> m;
    cnt.insert(cnt.end(), n+m, 0);
    for (int i = 0, tmp; i < n; ++i) {
        cin >> str;
        s.push_back(vector<int>{});
        t.push_back(vector<int>{});
        mp.push_back(vector<int>{});
        for (int j = 0; j < m; ++j) {
            if (str[j] == '#') {
                mp[i].push_back(0);
            } else {
                mp[i].push_back(1);
            }

            if (mp[i][j] == 0) tmp = 0;
            else if (i == 0 && j == 0) tmp = 1;
            else if (i == 0) tmp = s[i][j-1];
            else if (j == 0) tmp = s[i-1][j];
            else tmp = s[i-1][j]|s[i][j-1];
            s[i].push_back(tmp);
            t[i].push_back(0);
        }
    }
    if (!s[n-1][m-1]) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1 || m == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = n-1, tmp; i >= 0; --i) {
        for (int j = m-1; j >= 0; --j) {
            if (mp[i][j] == 0) tmp = 0;
            else if (i == n-1 && j == m-1) tmp = 1;
            else if (i == n-1) tmp = t[i][j+1];
            else if (j == m-1) tmp = t[i+1][j];
            else tmp = t[i][j+1]|t[i+1][j];
            t[i][j] = tmp;
            cnt[i+j] += t[i][j]&s[i][j];
        }
    }
    for (int step = 1; step < n+m-2; ++step) {
        if (cnt[step] == 1) {
            res = 1;
            break;
        }
    }
    cout << res << endl;
    return 0;
}
