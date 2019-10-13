#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int a[4];

int main()
{
    for (int i = 0; i < 4; ++i) cin >> a[i];
    sort(a, a+4);
    if (a[1]+a[2]+a[0] == a[3] || a[0]+a[3] == a[1]+a[2])
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
