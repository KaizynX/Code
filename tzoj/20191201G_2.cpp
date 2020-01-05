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
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (++vis[a[i]] > 1) flag = 1;
        }
        sort(a+1, a+n+1);
        reverse(a+1, a+n+1);
        if (!flag) {
            for (int i = 1; i <= n; ++i)
                cout << a[i] << " \n"[i==n];
            continue;
        }
        vector<long long> shit1, shit2;
        for (int i = 1; i <= n; ++i) {
            if (vis[a[i]] == 1) shit2.push_back(a[i]);
            else if (vis[a[i]] > 1) {
                shit1.push_back(a[i]);
                vis[a[i]] = 0;
            }
        }
        for (int i = 0; i < (int)shit1.size(); ++i)
            cout << shit1[i] << " \n"[i+1==(int)shit1.size()];
        for (int i = 0; i < (int)shit2.size(); ++i)
            cout << shit2[i] << " \n"[i+1==(int)shit2.size()];
    }
    return 0;
}



