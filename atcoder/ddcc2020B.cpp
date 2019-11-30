#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;
int a[N];
long long s[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i-1]+a[i];
    }
    long long res = s[n];
    for (int i = 1; i <= n; ++i) {
        res = min(res, abs(s[n]-s[i]-s[i]));
    }
    cout << res << endl;
    return 0;
}

