#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, n;
string str;

int main()
{
    cin >> T;
    while (T--) {
        cin >> str;
        int now = 0, res = 0;
        for (char c : str) {
            if (c == '1') ++now;
            else --now;
            res = max(now, res);
        }
        cout << res << endl;
    }
    return 0;
}
