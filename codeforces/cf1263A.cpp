#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int T, a[3];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        for (int i = 0; i < 3; ++i) cin >> a[i];
        sort(a, a+3);
        if (a[0]+a[1] >= a[2]) cout << (a[0]+a[1]+a[2])/2 << endl;
        else cout << a[0]+a[1] << endl;
        /*
        int res = a[1];
        a[2] -= a[1];
        res += min(a[0], a[2]);
        cout << res << endl;
        */
    }
    return 0;
}
