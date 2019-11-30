#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 18;
const int M = (1<<N)+7;

int n, p;
int a[M];
vector<int> b, res;

inline int my_log2(int x) {
    int res = 0;
    for (int i = 0; i <= N; ++i)
        if ((1<<i) <= x) res = i;
    return res;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == -1) p = i;
    }
    for (int target = 1<<my_log2(p); p > target; --p) {
        swap(a[p], a[p-1]);
    }
    for (int i = p+1; i <= n; ++i) {
        if ((int)b.size() < (i-p)/p) b.emplace_back(a[i]);
        else if (b.size() && b.back() > a[i]) {
            b.pop_back();
            b.emplace_back(a[i]);
        }
    }
    for (int i = 0; i < (int)b.size(); ++i) {
        if ((int)res.size() < my_log2(i+2)) res.emplace_back(b[i]);
        else if (res.size() && res.back() > b[i]) {
            res.pop_back();
            res.emplace_back(b[i]);
        }
    }
#ifdef DEBUG
    for (int i : b) cout << i << " ";
    cout << endl;
    for (int i : res) cout << i << " ";
    cout << endl;
#endif
    long long ans = 0;
    for (int i : res) ans += i;
    cout << ans << endl;
    return 0;
}
