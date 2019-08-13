#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n;

int main()
{
    int maxa = 0;
    long long sum = 0;
    cin >> n;
    for(int i = 0, a; i < n; ++i)
    {
        cin >> a;
        sum += a;
        maxa = max(maxa, a);
    }
    cout << (sum&1 || maxa+maxa > sum ? "NO" : "YES") << endl;
    return 0;
}
