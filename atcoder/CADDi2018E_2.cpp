#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;

int n;
int a[Maxn], op[Maxn];
long long ans;

int main()
{
    cin >> n >> a[1];
    for(int i = 2; i <= n; ++i)
    {
        cin >> a[i];
        op[i] = (int)ceil(abs(log2((double)a[i-1]/a[i])));
    }
    return 0;
}
