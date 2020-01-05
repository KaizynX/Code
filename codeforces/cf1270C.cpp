#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const long long INF = 1ll<<50;

int T, n;
int a[N];
long long res[3];

#ifdef DEBUG
inline void check() {
    long long lef = 0, rig = 0;
    for (int i = 1; i <= n; ++i) {
        lef += a[i];
        rig ^= a[i];
    }
    for (int i = 0; i < 3; ++i) {
        lef += res[i];
        rig ^= res[i];
    }
    cout << lef << " " << rig*2 << endl;
}
#endif

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        long long lef = 0, rig = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            lef += a[i];
            rig ^= a[i];
        }
        memset(res, 0, sizeof res);
        // rig *= 2;
        //if (lef > rig*2) {
            res[2] += INF;
            rig ^= INF;
            lef += INF;
        //}
        if ((rig*2-lef)&1) {
            ++res[2];
            ++lef;
            rig ^= 1;
        }
        res[0] += (rig*2-lef)/2;
        res[1] += (rig*2-lef)/2;
        cout << 3 << endl;
        for (int i = 0; i < 3; ++i)
            cout << res[i] << " ";
        cout << endl;
#ifdef DEBUG
        check();
#endif
    }
    return 0;
}
