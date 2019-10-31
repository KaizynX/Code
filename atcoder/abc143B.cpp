#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, sum, res;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; ++i) {
        res += a[i]*(sum-a[i]);
    }
    cout << res/2 << endl;
    return 0;
}
