#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, n;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> s;
        int cnt = 0;
        string res;
        res += s[0];
        for (int i = 1; i < n; ++i) {
            if (s[i] == 'b' && s[i-1] == 'b')
                ++cnt;
        }
        for (int i = 1, t = 0; i < n; ++i) {
            if (s[i] == 'b' && s[i-1] == 'b') {
                if (++t <= (cnt+1)/2) res += "{b";
                else res += "}b";
            } else {
                res += s[i];
            }
        }
        if (cnt&1) res += '}';
        cout << res << endl;
    }
    return 0;
}
