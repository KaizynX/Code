#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int n, k, m;
int s[N], minv[N], maxv[N];
vector<int> res;

int main()
{
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1, tmp; i <= n; ++i) {
        cin >> s[i];
        minv[i] = maxv[i] = s[i];
        for (int j = 1; j < k; ++j) {
            scanf("%d", &tmp);
            s[i] += tmp;
            minv[i] = min(minv[i], tmp);
            maxv[i] = max(maxv[i], tmp);
        }
        s[i] -= minv[i]+maxv[i];
        res.emplace_back(s[i]);
    }
    sort(res.begin(), res.end());
    for (int i = max(0, (int)res.size()-m); i < (int)res.size(); ++i)
        printf("%.3f%c", 1.0*res[i]/(k-2), " \n"[i==(int)res.size()-1]);
    return 0;
}
