#include <bits/stdc++.h>

using namespace std;

int q;
long long a;

int main()
{
    cin >> q;
    for(int j = 1; j <= q; ++j)
    {
        a = (1ll<<j)-1;
        int ans = 0, i;
        for(int b = 1; b < a; ++b)
        {
            //ans = max(ans, __gcd(a^b, a&b));
            int tmp = __gcd(a^b, a&b);
            if(tmp > ans)
            {
                ans = tmp;
                i = b;
            }
        }
        cout << "a:" << a << " ans:" <<  ans << " b:" << i << endl;
    }
    system("pause");
    return 0;
}