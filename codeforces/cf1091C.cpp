#include <bits/stdc++.h>

using namespace std;

int main()
{
    int INF;
    cin >> INF;
    for(int n = 1; n <= INF; ++n)
    {
        set<long long> s;
        cout << n << ":";
    for(int k = 1; k <= n; ++k)
    {
        int cur = 1+k;
        if(cur > n) cur -= n;
        long long sum = 1;
        while(cur != 1)
        {
            sum += cur;
            cur += k;
            if(cur > n) cur -= n;
        }
        s.insert(sum);
    }
    for(set<long long>::iterator it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << endl;
    }
    return 0;
}
