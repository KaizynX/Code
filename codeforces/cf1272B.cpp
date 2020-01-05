#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int T;
int cnt[128];
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        cnt['L'] = cnt['R'] = cnt['U'] = cnt['D'] = 0;
        for (char c : s) ++cnt[c];
        int lr = min(cnt['L'], cnt['R']),
            ud = min(cnt['U'], cnt['D']);
        if (!lr && !ud) {
            puts("0");
            putchar('\n');
        }else if (!lr) {
            puts("2");
            puts("UD");
        } else if (!ud) {
            puts("2");
            puts("LR");
        } else {
            cout << lr*2+ud*2 << endl;
            for(int i = 1; i <= lr; ++i) putchar('L');
            for(int i = 1; i <= ud; ++i) putchar('U');
            for(int i = 1; i <= lr; ++i) putchar('R');
            for(int i = 1; i <= ud; ++i) putchar('D');
            putchar('\n');
        }
    }
    return 0;
}

