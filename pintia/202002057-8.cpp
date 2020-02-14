#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int n, sum;
string name[N];
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> name[i] >> a[i];
        sum += a[i];
    }
    int res = 1;
    for (int i = 2; i <= n; ++i) {
        if (abs(sum/2.0/n-a[i]) < abs(sum/2.0/n-a[res]))
            res = i;
    }
    cout << sum/(2*n) << " " << name[res] << endl;
    return 0;
}
