#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2+7;
const int INF = 1e9;
const int lenp = 25;
const int p[] = { 0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };

int n, res, choose;
int a[MAXN], b[MAXN];

inline bool check(int cur)
{
    for (int i = 1; i <= n; ++i) {
        if (!b[i]) continue;
        if (!(cur&b[i])) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int flag = 0;
        for (int j = 16; j <= lenp; ++j) {
            if (p[j] == a[i]) {
                if (!(choose&(1<<j))) {
                    ++res;
                    choose |= 1<<j;
                }
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        for (int j = 1; j <= 15; ++j) {
            if (a[i]%p[j] == 0) {
                while (a[i]%p[j] == 0)
                    a[i] /= p[j];
                b[i] |= 1<<j;
            }
        }
    }
    int nowc = INF;
    for (int i = 0; i < (1<<16); ++i) {
        if (check(i)) {
            int cnt = 0;
            for (int j = 1; j <= 15; ++j) {
                if (i&(1<<j)) ++cnt;
            }
            if (cnt < nowc) {
                nowc = cnt;
            }
        }
    }
    res += nowc;
    cout << res << endl;
    return 0;
}
