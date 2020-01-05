#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, T;
string s;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        int a = 0, b = 0, c = 0;
        cin >> s;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (s[i] == 'a') ++a;
            if (s[i] == 'b') ++b;
            if (s[i] == '?') ++c;
        }
        if (s.length()%2 || min(a, b)+c < max(a, b)) {
            cout << -1 << endl;
            continue;
        }
        string res;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (s[i] == '?') {
                if (a < (int)s.length()/2) res += 'a', ++a;
                else res += 'b', ++b;
            } else {
                res += s[i];
            }
        }
        cout << res << endl;
    }
    return 0;
}
