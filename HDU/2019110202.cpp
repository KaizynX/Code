#include <bits/stdc++.h>

using namespace std;

int t, n;
string str;
vector<string> res;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> str;
        str = "c"+str;
        res.clear();
        int mx = 0;
        for (int i = 1, cnt = 1; i <= n; ++i) {
            if (str[i] == str[i-1]) ++cnt;
            if (str[i] != str[i-1] || i == n) {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }
        for (int i = 1, cnt = 1; i <= n; ++i) {
            if (str[i] == str[i-1]) ++cnt;
            if (str[i] != str[i-1] || i == n) {
                if (cnt == mx) {
                    string tmp = "";
                    for (int j = 0; j < cnt; ++j)
                        tmp += str[mx == 1 ? i : i-1];
                    res.push_back(tmp);
                }
                cnt = 1;
            }
        }
        cout << res.size() << endl;
        for (string s : res) cout << s << endl;
    }
    return 0;
}