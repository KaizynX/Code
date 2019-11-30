#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 18;
const int M = (1<<N)+7;

int n, p;
int a[M];
vector<pair<int, int>> b;
priority_queue<pair<int, int>> q;

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
        if ((int)q.size() < (i-p)/p) q.push({a[i], i});
        else if (q.size() && q.top().first >= a[i]) {
            q.pop();
            q.push({a[i], i});
        }
    }
    while (q.size()) {
        auto tmp = q.top();
        q.pop();
        b.emplace_back(tmp.second, tmp.first);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < (int)b.size(); ++i) {
        if ((int)q.size() < my_log2(i+2)) q.push({b[i].second, b[i].first});
        else if (q.size() && q.top().first >= b[i].second) {
            q.pop();
            q.push({b[i].second, b[i].first});
        }
    }
#ifdef DEBUG
    for (auto i : b) cout << "(" << i.first << ", " << i.second << ") ";
    cout << endl;
#endif
    long long ans = 0;
    while (q.size()) {
        ans += q.top().first;
        q.pop();
    }
    cout << ans << endl;
    return 0;
}
