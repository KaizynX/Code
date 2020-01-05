#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, k;
int a[N];
vector<int> v;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> k) {
        int cnt = 0;
        long long res = 0;
        v.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i]&1) ++cnt;
            else {
                v.push_back(cnt+1);
                cnt = 0;
            }
        }
        v.push_back(cnt+1);
        for (int i = 0; i+k < (int)v.size(); ++i) {
            res += 1ll*v[i]*v[i+k];
        }
        cout << res << endl;
    }
    return 0;
}
