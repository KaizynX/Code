#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+7;

int n, nn, np;
int a[MAXN];
multiset<long long> ms;

int main()
{
    cin >> n;
    ms.insert(0);
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        // sum-() < 0
        // () > sum
        nn += ms.end()-ms.upper_bound(sum);
        // sum-() > 0
        // () < sum
        np += ms.lower_bound(sum)-ms.begin()-1;
    }
    cout << nn << " " << np << endl;
    return 0;
}
