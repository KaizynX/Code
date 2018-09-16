#include <cstdio>
#include <iostream>

using namespace std;

long long k, m, n = 1, cur = 1;
int f[10000000];

/* f(n) = 1111...(n)
 * f(n) = x*m+y
 * f(n)%m = y
 * f(n+1) = (x*m+y)*10+1
 *        = 10*x*m + 10*y+1
 * f(n+1)%m = (10*y+1)%m
 * f(n+2) = 100*x*m + 100*y+10+1
 *
 * f(n+k) = 10^k*x*m + 10^k*y+ 111...(k)
 * f(n+k)%m = 10^k*y%m + f(k)%m
 *
 * g(n) = 10^n%m
 * f(n+k)%m = g(k)*f(n)%m + f(k)%m
 */
/*f(n) = 111...(n)%m
f(n) = (10^(n+1)-1)/9%m
设9的逆元为%m = c
f(n) = (10^(n+1)-1)*逆元%m
f(n) = (10^(n+1)-1)%m*c%m
      = (10^(n+1)*c%m - 1)%m

记n+1为n
求 c*10^n%m = (k+1)%m
设右边为ki
c*10^n %m = ki
其中c, ki为常数
g(n) = c*10^n %m
g(n+1) = g(n)*10 %m
g(n+k) = g(n)*10^k%m 

ac % m == bc %m
a % (m/gcd(c,m)) = b%(m/gcd(c, m))

c*10^n%m == ki

答案为n+1
*/

int main()
{
    cin >> k >> m;
    while(cur <= k)
    {
        cur = cur*10+1;
        n++;
    }
    cur %= m;
    while(cur != k)
    {
        cur = (cur*10+1)%m;
        n++;
    }
    cout << n << endl;
    return 0;
}
