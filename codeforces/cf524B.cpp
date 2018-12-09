#include <bits/stdc++.h>

using namespace std;

int q, l, r, tl, tr;
long long ans;

int main()
{
    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        // -
        tl = l; tr = r;
        if(tl%2 == 0) tl++;
        if(tr%2 == 0) tr--;
        ans = -1ll*(tl+tr)*((tr-tl)/2+1)/2;
        // +
        tl = l; tr = r;
        if(tl%2 == 1) tl++;
        if(tr%2 == 1) tr--;
        ans += 1ll*(tl+tr)*((tr-tl)/2+1)/2;
        cout << ans << endl;
    }
    return 0;
}
