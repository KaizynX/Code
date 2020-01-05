#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n;
int vis[N];

int main()
{
    cin >> n;
    for (int i = 1, a; i <= n; ++i)  {
        cin >> a;
        vis[a] = 1;
    }
    for (int i = 1, flag = 0; i <= 13; ++i) {
        if (vis[i]) continue;
        if (flag) cout << " ";
        cout << i;
        flag = 1;
    }
    cout << endl;
    return 0;
}
