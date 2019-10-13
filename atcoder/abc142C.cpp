#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;
int a[N], b[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cout << b[i] << " \n"[i==n];
    }
    return 0;
}
