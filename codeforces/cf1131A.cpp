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

const int Maxn = 1e1+7;

int w[3], h[3];
int ans;

int main()
{
    cin >> w[1] >> h[1] >> w[2] >> h[2];
    ans = (w[1]+2)+2*h[1]+(w[2]+2)+2*h[2]+w[1]-w[2];
    cout << ans << endl;
    return 0;
}