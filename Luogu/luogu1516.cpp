#include <bits/stdc++.h>

using namespace std;

const int kN = 2e9;

int x, y, m, n, L;
/********
 * m*t+x = n*t+y (mod L)
 * (m-n)*t = y-x
 * let: d = gcd(m-n, L)
 * if (y-x)%d == 0
 * (m-n)*t + L*s = d
 * else no answer
 ********/

inline int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}

void exgcd(int a, int b, long long &x, long long &y)
{
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a%b, y, x);
    y -= a/b*x;
}

int main()
{
    scanf("%d%d%d%d%d", &x, &y, &m, &n, &L);
    int m_n = m - n, y_x = y - x;
    if (m_n < 0) {
        m_n = -m_n;
        y_x = -y_x;
    }
    int d = gcd(m_n, L);
    if (y_x % d != 0) {
        return printf("Impossible\n")&0;
    }
    long long t, s;
    exgcd(m_n, L, t, s);
    printf("%lld\n", ((y_x/d*t)%(L/d)+L/d)%(L/d));
    return 0;
}
