#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int t, n;
string str;
vector<string> res;

int main()
{
    cin >> t;
    while (t--) {
        res.clear();
        cin >> n >> str;
        for (int i = 1, cnt = 1; i < n; ++i) {
            if (str[i] == str[i-1]) ++cnt;
            if (str[i] != str[i-1] || i == n-1) {
                if (cnt > 1) {
                    string tmp = "";
                    for (int j = 0; j < cnt; ++j) tmp += str[i-1];
                    res.push_back(tmp);
                    // res.push_back(string(str[i-1], cnt));
                }
                cnt = 1;
            }
        }
        cout << res.size() << endl;
        for (string s : res) cout << s << endl;
    }
    return 0;
}