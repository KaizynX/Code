#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int t, n;
pair<int, int> a[N];
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &a[i].first, &a[i].second);
        }
        sort(a+1, a+n+1);

        long long res = 0;
        while (q.size()) q.pop();
        for (int i = n, cnt = 0; i; --i) {
            q.push(a[i].second);
            if (i-1+cnt >= a[i].first) continue;
            ++cnt;
            res += q.top();
            q.pop();
        }
        printf("%I64d\n", res);
    }
    return 0;
}
