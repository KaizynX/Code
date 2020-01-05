#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

long long a, b, k;

int main()
{
    cin >> a >> b >> k;
    long long c = min(a, k);
    a -= c;
    k -= c;
    c = min(b, k);
    b -= c;
    cout << a << " " << b << endl;
    return 0;
}
