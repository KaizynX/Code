#include <bits/stdc++.h>

using namespace std;

const int N = 2e4+7;

int n, res;
int a[N], f[N];

int main()
{
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i]%2 != 0) f[i] = 1;
        a[i] = static_cast<int>(floor(a[i]/2.0));
        sum += a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (f[i] && sum < 0) {
            ++a[i];
            ++sum;
        }
        cout << a[i] << endl;
    }
    return 0;
}
