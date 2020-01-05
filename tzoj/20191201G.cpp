#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int n;
long long a[N];
map<long long, int> vis;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int fuck = 0;
    while (cin >> n) {
        if (fuck) cout << endl;
        fuck = 1;
        vis.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ++vis[a[i]];
        }
        sort(a+1, a+n+1);
        reverse(a+1, a+n+1);
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (vis[a[i]] > 1) {
                if (flag) cout << " ";
                cout << a[i];
                flag = 1;
                vis[a[i]] = 0;
            }
        }
        if (flag) cout << endl;
        flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (vis[a[i]] == 1) {
                if (flag) cout << " ";
                cout << a[i];
                flag = 1;
            }
        }
        cout << endl;
    }
    return 0;
}


