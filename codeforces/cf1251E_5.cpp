#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int t, n;
pair<int, int> a[N];
priority_queue<int> q;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &a[i].first, &a[i].second);
        }
        sort(a+1, a+n+1);
        int cnt = 0;
        long long res = 0;
        for (int i = 0, p = 1; i < n; ++i) {
            while (p <= n && a[p].first == i)
                q.push(a[p++].second);
            if (q.empty()) ++cnt;
            else q.pop();
        }
        while (q.size()) {
            res += q.top();
            q.pop();
        }
        printf("%I64d\n", res);
    }
    return 0;
}
