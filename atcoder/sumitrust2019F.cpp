#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

int t1, t2;
long long a1, a2, b1, b2;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    if (a1 > b1) swap(a1, b1), swap(a2, b2);
    long long d1 = a1*t1+a2*t2, d2 = b1*t1+b2*t2;
    long long aa1 = a1*t1, aa2 = a2*t2, bb1 = b1*t1, bb2 = b2*t2;
    if (d1 < d2) {
        cout << 0 << endl;
        return 0;
    }
    if (d1 == d2) {
        cout << "infinity" << endl;
        return 0;
    }
    // aa1 < bb1, aa2 > bb2, dd1+dd2 > 0
    long long dd1 = aa1-bb1, dd2 = aa2-bb2;
#ifdef DEBUG
    cout << dd1 << " " << dd2  << " " << dd1+dd2 << endl;
#endif
    cout << (-dd1)/(dd1+dd2)*2+((-dd1)%(dd1+dd2) != 0) << endl;
    return 0;
}

