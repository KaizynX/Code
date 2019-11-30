#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, r, c, k, sum;
int a[N][N], res[N][N];
vector<char> mark;

inline void print()
{
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cout << mark[res[i][j]];
        }
        cout << endl;
    }
}

int main()
{
    char ch;
    for (ch = 'a'; ch <= 'z'; ++ch) mark.push_back(ch);
    for (ch = 'A'; ch <= 'Z'; ++ch) mark.push_back(ch);
    for (ch = '0'; ch <= '9'; ++ch) mark.push_back(ch);
    cin >> T;
    while (T--) {
        sum = 0;
        cin >> r >> c >> k;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                cin >> ch;
                a[i][j] = (ch == 'R' ? 1 : 0);
                sum += a[i][j];
                res[i][j] = -1;
            }
        }
        int mk = 0, cur = 0;
        for (int i = 1; i <= r; ++i) {
            if (i%2) for (int j = 1; j <= c; ++j) {
                res[i][j] = min(mk, k-1);
                cur += a[i][j];
                if (cur >= sum/k+(mk < sum%k)) {
                    cur = 0;
                    ++mk;
                }
            }
            else for (int j = c; j; --j) {
                res[i][j] = min(mk, k-1);
                cur += a[i][j];
                if (cur >= sum/k+(mk < sum%k)) {
                    cur = 0;
                    ++mk;
                }
            }
        }
        print();
    }
    return 0;
}
