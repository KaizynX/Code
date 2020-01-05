#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n[4], nn[4];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 4; ++i) cin >> n[i];
    if (!n[0] || !n[1] || !n[2] || !n[3]) {
        int l = 0, r = 3;
        while (!n[l]) ++l;
        while (!n[r]) --r;
        if (l == r) {
            if (n[l] == 1) cout << "YES" << endl << l << endl;
            else cout << "NO" << endl;
        } else if (l+1 == r) {
            if (abs(n[l]-n[r]) > 1) cout << "NO" << endl;
            else {
                cout << "YES" << endl;
                if (n[l] > n[r]) cout << l << " ";
                for (int i = 1; i <= n[l] && i <= n[r]; ++i)
                    cout << r << " " << l << " ";
                if (n[l] < n[r]) cout << r << " ";
                cout << endl;
            }
        } else if (l+2 == r) {
            if (!n[l+1]) cout << "NO" << endl;
            else {
                int flag = -1;
                for (int i = 0; i < n[l+1]; ++i) {
                    for (int j = l; j <= r; ++j) nn[j] = n[j];
                    --nn[l+1];
                    if (nn[l]-i < 0 || nn[l]-i > 1 ||
                        nn[r]-nn[l+1]+i < 0 || nn[r]-nn[l+1]+i > 1) continue;
                    flag = i;
                    break;
                }
                if (flag != -1) {
                    cout << "YES" << endl;
                    if (nn[l] > flag) cout << l << " ";
                    for (int i = 0; i < flag; ++i)
                        cout << l+1 << " " << l << " ";
                    cout << l+1 << " ";
                    for (int i = 0; i < n[l+1]-1-flag; ++i)
                        cout << r << " " << l+1 << " ";
                    if (n[r] > n[l+1]-flag-1) cout << r << " ";
                    cout << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }
    for (int i = 1; i <= n[1] && i <= n[2]; ++i) {
        for (int j = 0; j < 4; ++j) nn[j] = n[j];
        nn[1] -= i;
        nn[2] -= i;
        if (nn[0]-nn[1] < 0 || nn[0]-nn[1] > 1 || nn[3]-nn[2] < 0 || nn[3]-nn[2] > 1) continue;

        cout << "YES" << endl;
        if (nn[0] > nn[1]) cout << 0 << " ";
        for (int j = 0; j < nn[1]; ++j) {
            cout << 1 << " ";
            cout << 0 << " ";
        }
        for (int j = 0; j < i; ++j) {
            cout << 1 << " ";
            cout << 2 << " ";
        }
        for (int j = 0; j < nn[2]; ++j) {
            cout << 3 << " ";
            cout << 2 << " ";
        }
        if (nn[3] > nn[2]) cout << 3 << " ";
        cout << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
