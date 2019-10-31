#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 2e5+7;

int n, k;
int a[N], f[N];

int main()
{
    string str;
    cin >> n >> k >> str;
    for (int i = 0; i < n; ++i)
        a[i] = str[i] == 'W' ? 0 : 1;

    int s = -1;
    for (int i = 0; i < n; ++i) {
        f[i] = (a[i] != a[(i+1)%n] && a[i] != a[(i-1+n)%n]);
        if (!f[i]) s = i;
    }
    if (s == -1) {
        for (int i = 0; i < n; ++i)
            cout << (a[i]^(k&1) ? 'B' : 'W');
        cout << endl;
        return 0;
    }

    for (int j = 1, i = (s+1)%n, cnt = 0, l; j <= n; i = (++j+s)%n) {
        if (!f[i]){
            for (int p = 0; p < min(k, (cnt+1)/2); ++p) {
                a[(i-1-p+n)%n] = a[i];
                a[(l+p)%n] = a[(l-1+n)%n];
            }
            if (k*2 < cnt && k%2) {
                for (int p = (l+k)%n; p != (i-k+n)%n; p = (p+1)%n)
                    a[p] ^= 1;
            }
            cnt = 0;
        } else {
            if (!cnt) l = i;
            ++cnt;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << (a[i] ? 'B' : 'W');
    cout << endl;
    return 0;
}
