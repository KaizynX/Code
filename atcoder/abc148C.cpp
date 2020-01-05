#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int a, b;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    cout << 1ll*a*b/__gcd(a, b) << endl;
    return 0;
}
