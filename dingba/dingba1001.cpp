#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n;
int a[N];

int main()
{
    while (cin >> a[1] >> a[2] >> n) {
        for (int i = 3; i <= n; ++i)
            a[i] = abs(a[i-1]-a[i-2]);
        cout << a[n] << endl;
    }
    return 0;
}
