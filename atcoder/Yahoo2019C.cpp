#include <bits/stdc++.h>

using namespace std;

int k, a, b;
long long ans;

int main()
{
    cin >> k >> a >> b;
    if(b-a <= 2 || a+1 > k) cout << k+1 << endl;
    else
    {
        k -= a-1;
        ans = a;
        ans += 1ll*(k/2)*(b-a)+(k&1);
        cout << ans << endl;
    }
    system("pause");
    return 0;
}