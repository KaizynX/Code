#include <map> 
#include <set> 
#include <cmath> 
#include <stack> 
#include <queue> 
#include <cstdio> 
#include <vector> 
#include <cstring> 
#include <iostream>
#include <algorithm> 

using namespace std;

const int Maxn = 1e4+7;

int n, ans = 1;
int a[Maxn], b[Maxn];

int main()
{
    cin >> n;
    int last = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i];
        if(a[i-1] > b[i] || b[i-1] > a[i]) continue;
        ans += min(a[i], b[i])-max(last+1, max(a[i-1], b[i-1]))+1;
        last = min(a[i], b[i]);
    }
    cout << ans << endl;
    return 0;
}