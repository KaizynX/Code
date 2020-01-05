#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int T, n;
int a[N];

inline bool check()
{
    for (int i = 2; i <= n; ++i)
        if (a[i] < a[i-1]) return false;
    return true;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int l = 1, r = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i+1] && l != r) break;
            if (a[i] > a[i+1]) {
                if (l == r) l = i;
                r = i+1;
            }
        }
        reverse(a+l, a+r+1);
        if (check()) {
            cout << "YES" << endl;
            cout << l << " " << r << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

