#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l+r)>>1;
        if (mid*108/100 >= n) r = mid;
        else l = mid+1;
    }
    if (l*108/100 == n) cout << l << endl;
    else cout << ":(" << endl;
    return 0;
}

