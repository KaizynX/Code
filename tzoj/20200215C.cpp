#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int M = 1e3+7;

int n, k, q;
int ill[N*M], a[N][M], m[N];
map<string, int> bus, peo;

inline int get_id(map<string, int> &mp, const string &str)
{
    if (mp.count(str)) return mp[str];
    return mp[str] = mp.size();
}

int main()
{
    string str;
    cin >> n;
    for (int i = 1, b; i <= n; ++i) {
        cin >> str;
        b = get_id(bus, str);
        cin >> m[b];
        for (int j = 1; j <= m[b]; ++j) {
            cin >> str;
            a[b][j] = get_id(peo, str);
        }
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> str;
        ill[get_id(peo, str)] = 1;
    }
    cin >> q;
    while (q--) {
        cin >> str;
        int b = get_id(bus, str), cnt = 0;
        for (int i = 1; i <= m[b]; ++i)
            cnt += ill[a[b][i]];
        cout << cnt << endl;
    }
    return 0;
}
