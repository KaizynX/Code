#include <bits/stdc++.h>

using namespace std;

const int kN = 2e5+7;

int n;
long long res;
int a[kN], b[kN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] < a[i]) {
            cout << "-1" << endl;
            return 0;
        }
    }
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 0; i < n; ++i) {
            int bt = b[(i-1+n)%n]+b[(i+1)%n];
            if (b[i]-bt >= a[i]) {
                int k = (b[i]-a[i])/bt;
                res += k;
                b[i] -= k*bt;
                flag = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << res << endl;
    return 0;
}
