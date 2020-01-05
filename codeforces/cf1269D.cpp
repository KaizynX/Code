#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    reverse(a+1, a+n+1);
    long long res = 0;
    for (int i = 1, h = 0; i <= n; ++i) {
        if (i == n) {
            res += (a[i]-h)/2;
        } else if ((a[i]-h)&1) {
            res += (a[i]-h)/2+h/2+1;
            ++h;
        } else {
            res += (a[i]-h)/2+h/2;
            h = max(0, h-1);
        }
    }
    cout << res << endl;
    return 0;
}
