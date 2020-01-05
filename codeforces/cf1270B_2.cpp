#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int T, n;
int a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int maxi = 1, mini = 1, flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[mini]+i-mini >= a[i]) mini = i;
            if (a[maxi]-i+maxi <= a[i]) maxi = i;
            if (a[i]-a[mini] > i-mini) {
                cout << "YES" << endl;
                cout << mini << " " << i << endl;
                flag = 1;
                break;
            }
            if (a[maxi]-a[i] > i-maxi) {
                cout << "YES" << endl;
                cout << maxi << " " << i << endl;
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        cout << "NO" << endl;
    }
    return 0;
}

