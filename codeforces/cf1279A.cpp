#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T;
int a[5];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        for (int i = 0; i < 3; ++i) cin >> a[i];
        sort(a, a+3);
        if (a[0]+a[1]+1 < a[2]) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
