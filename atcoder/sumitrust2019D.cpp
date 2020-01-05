#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;
int vis1[10], vis2[10][10], vis3[10][10][10];
string s;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        int x = s[i]-'0';
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                if (vis2[j][k])
                    vis3[j][k][x] = 1;
            }
            if (vis1[j])
                vis2[j][x] = 1;
        }
        vis1[x] = 1;
    }
    int res = 0;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                if (vis3[i][j][k])
                    ++res;
            }
        }
    }
    cout << res << endl;
    return 0;
}
