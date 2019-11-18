#include <bits/stdc++.h>

using namespace std;

long long n, p;

int main()
{
    cin >> n;
    for (long long i = 2; i*i <= n; ++i) {
        if (n%i) continue;
        cout << i << endl;
        return 0;
    }
    cout << n << endl;
    return 0;
}
