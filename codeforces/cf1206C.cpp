#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;

int n;
int a[kN<<1];

int main()
{
    cin >> n;
    // n <<= 1;
    long long sum = 1ll*n*(1+n*2);
    if (sum%2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
        if (i&1) {
            a[i] = i*2-1;
            a[i+n] = i*2;
        } else {
            a[i] = i*2;
            a[i+n] = i*2-1;
        }
    }
    /*
    for (int i = 1; i <= n/2; ++i) {
        a[i] = i*2-1;
    }
    for (int i = n/2+1; i <= n; ++i) {
        a[i] = i*2;
    }
    for (int i = n+1; i <= n*2; ++i) {
        a[i] =  a[i-n]&1 ? a[i-n]+1 : a[i-n]-1;
    }
    */
    for (int i = 1; i <= n*2; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
