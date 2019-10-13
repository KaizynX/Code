#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2+7;
const int INF = 1e9;

int n, res;
string str;
int s[MAXN], a[MAXN], b[MAXN];

int main()
{
    cin >> n >> str;
    for (int i = 0; i < str.length(); ++i) {
        s[i+1] = str[i]-'0';
        res += s[i+1];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int t = 1, now = res; t <= 10000; ++t) {
        for (int i = 1; i <= n; ++i) {
            if (t == b[i]) {
                now += (s[i] ? -1 : 1);
                s[i] ^= 1;
                b[i] += a[i];
            }
        }
        res = max(res, now);
    }
    cout << res << endl;
    return 0;
}
