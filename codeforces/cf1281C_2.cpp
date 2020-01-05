#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;

int T, x;
string s;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> x >> s;
        long long n = s.length();
        for (int i = 0; i < x; ++i) {
            n = (n-1)*(s[i]-'0')%MOD;
            if (n == 0) break;
            if ((int)s.length() < x) {
                string tmp = s.substr(i+1);
                for (int j = 1; j < s[i]-'0'; ++j)
                    s += tmp;
            }
        }
        cout << (n+x)%MOD << endl;
    }
    return 0;
}
