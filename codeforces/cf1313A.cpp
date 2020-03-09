#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T;
int a[5];

int main()
{
    cin >> T;
    while (T--) {
        int res = 0;
        for (int i = 1; i <= 3; ++i) cin >> a[i];
        sort(a+1, a+4);
        reverse(a+1, a+4);
        for (int i = 1; i <= 3; ++i) {
            if (a[i]) {
                --a[i];
                ++res;
            }
        }
        if (a[1] && a[2]) ++res, --a[1], --a[2];
        if (a[1] && a[3]) ++res, --a[1], --a[3];
        if (a[2] && a[3]) ++res, --a[2], --a[3];
        if (a[1] && a[2] && a[3]) ++res;
        cout << res << endl;
    }
    return 0;
}