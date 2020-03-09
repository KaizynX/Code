#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

string s;
int cnt[256];

int main()
{
    while (cin >> s) {
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < (int)s.length(); ++i) ++cnt[s[i]];
        int a = cnt['2'], b = cnt['8'], c = min(a, b);
        cout << c-(a <= c) << endl << "Happy Birthday!" << endl;
    }
    return 0;
}
