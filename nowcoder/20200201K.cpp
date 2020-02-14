#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1, j = n, k = 0; i <= j; ++i, --j) {
        a[i] = ++k;
        if (i != j) a[j] = ++k;
    }
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    return 0;
}
