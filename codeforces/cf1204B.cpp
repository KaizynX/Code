#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+7;

int n, l ,r, sum = 1;
int a[MAXN];

int main()
{
    cin >> n >> l >> r;
    a[1] = 1;
    for (int i = 2; i <= r+1; ++i) {
        if (i == l+1) {
            cout << sum+(n-l) << " ";
        }
        if (i > r) break;
        a[i] = a[i-1]*2;
        sum += a[i];
    }
    cout << sum+a[r]*(n-r) << endl;
    return 0;
}
