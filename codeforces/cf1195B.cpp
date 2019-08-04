#include <bits/stdc++.h>

using namespace std;

int n, k;

int main()
{
    cin >> n >> k;
    int l = 0, r = n;
    while(l < r)
    {
        int mid = (l+r)/2;
        long long res = (long long)(1+mid)*mid/2-(n-mid);
        if(res < k) l = mid+1;
        else r = mid;
    }
    cout << n-l << endl;
    return 0;
}
