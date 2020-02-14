#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, ot, in, dif;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n/2; ++i) in += a[i];
    for (int i = n/2+1; i <= n; ++i) ot += a[i];
    dif = ot-in;
    cout << "Outgoing #: " << (n+1)/2 << endl
         << "Introverted #: " << n/2 << endl
         << "Diff = " << dif << endl;
    return 0;
}
