#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e3+7;
const string s[3][4] = {{"aa.",
                         "..b",
                         "..b"},
                        {"aab",
                         "c.b",
                         "cdd"},
                        {"aabc",
                         "ddbc",
                         "efgg",
                         "efhh"}};
const int a[3] = {3, 3, 4}, b[3] = {1, 2, 3};

int n;
char res[N][N];

inline void filll(int k, int x, int y)
{
    for (int i = 0; i < a[k]; ++i) {
        for (int j = 0; j < a[k]; ++j) {
            res[x+i][y+j] = s[k][i][j];
        }
    }
}

inline void solve(int i0, int i1, int i2)
{
    for (int i = 0; i < i0; ++i)
        for (int j = 0; j < i0; ++j)
            filll(0, i*a[0], j*a[0]);
    for (int i = 0; i < i1; ++i)
        for (int j = 0; j < i1; ++j)
            filll(1, a[0]*i0+i*a[1], a[0]*i0+j*a[1]);
    for (int i = 0; i < i2; ++i)
        for (int j = 0; j < i2; ++j)
            filll(2, a[0]*i0+a[1]*i1+i*a[2], a[0]*i0+a[1]*i1+j*a[2]);
}

inline void print()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (res[i][j]) cout << res[i][j];
            else cout << '.';
        }
        cout << endl;
    }
}

int main()
{
    cin >> n;
    for (int i0 = 0; i0 <= n; ++i0) {
        for (int i1 = 0; i1 <= n; ++i1) {
            int rest = n-i0*a[0]-i1*a[1];
            if (rest < 0 || rest%a[2]) continue;
            int i2 = rest/a[2];
            if (i0 && i1 && i0*b[0] != i1*b[1]) continue;
            if (i0 && i2 && i0*b[0] != i2*b[2]) continue;
            if (i1 && i2 && i1*b[1] != i2*b[2]) continue;
            solve(i0, i1, i2);
#ifdef DEBUG
            cout << i0 << " " << i1 << " " << i2 << endl;
#endif
            print();
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
