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

const int Maxn = 1e2+7;

int n;
int a[Maxn], b[Maxn];

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    b[n/2] = a[0];
    int i = (n/2-1+n)%n, j = (n/2+1)%n, p = 1;
    while(p+1 < n)
    {
        if(max(a[p]-a[(i+1)%n], a[p+1]-a[(j-1+n)%n]) <=
                max(a[p]-a[(j-1+n)%n], a[p+1]-a[(i+1)%n]) )
        {
            b[i] = a[p];
            b[j] = a[p+1];
        }
        else
        {
            b[j] = a[p];
            b[i] = a[p+1];
        }
        i = (i-1+n)%n;
        j = (j+1)%n;
        p += 2;
    }
    if(p < n) b[i] = a[p];
    for(int i = 0; i < n; ++i)
        cout << b[i] << " ";
    return 0;
}