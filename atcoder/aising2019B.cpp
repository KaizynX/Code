#include <bits/stdc++.h>

using namespace std;

int n, a, b, cnt[3];

int main()
{
    cin >> n >> a >> b;
    for(int i = 1, p; i <= n; ++i)
    {
        cin >> p;
        if(p <= a) cnt[0]++;
        else if(p <= b) cnt[1]++;
        else cnt[2]++;
    }
    cout << min(cnt[0], min(cnt[1], cnt[2])) << endl;
    return 0;
}
