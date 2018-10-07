#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 2e3+7;
const int Maxm = 5e5+7;

// r�����¼������i��ֱ������һ��
// <==> ��i��ֱ�� a[r[i]]
int n, m, k, tot, r[Maxn];
long long res[Maxm];

// ֱ��
struct Line
{
    int ki, b, rank;
    // �����˱�int������
    long long y;
    // ����x�������y��ֵ
    inline long long calc(int x)
    {
        return y = (long long)x*ki+b;
    }
    inline bool operator < (const Line &l) const
    {
        return y < l.y;
    }
} a[Maxn];

// ֱ��֮��Ľ���
struct Point
{
    int i, j, x;
    inline int calc()
    {
        return x = (a[i].b-a[j].b)/(a[j].ki-a[i].ki)+1;
    }
    bool operator < (const Point &b) const
    {
        return x == b.x ? i < b.i : x < b.x;
    }
} p[Maxn*Maxn/2];

// ѯ��
struct Query
{
    int x, num;
    bool operator < (const Query &b) const
    {
        return x < b.x;
    }
} q[Maxm];

// ���
template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
    x = c-'0';
    while((c=getchar()) >= '0' && c <= '9') x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

// �������
template <typename T> void put(T x)
{
    if(x < 0)
    {
        putchar('-');
        x = -x;
    }
    if(x/10) put(x/10);
    putchar(x%10+'0');
}

int main()
{
    read(n); read(m); read(k);
    for(int i = 1; i <= n; ++i)
    {
        read(a[i].ki);
        read(a[i].b);
        r[i] = i;
    }
    for(int i = 1; i <= m; ++i)
    {
        read(q[i].x);
        q[i].num = i;
    }
    // ѯ�ʰ�x��С��������
    sort(q+1, q+m+1);
    // �����һ��ѯ��֮ǰÿ���ߵ�y,������
    for(int i = 1; i <= n; ++i)
        a[i].calc(p[1].x);
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; ++i)
        a[i].rank = i;
    // ����ÿ�����ߵĽ���
    for(int i = 1; i < n; ++i)
        for(int j = i+1; j <= n; ++j)
            // б����ͬû�н���Ŀ�
            if(a[i].ki != a[j].ki && a[i].calc(q[m].x) >= a[j].calc(q[m].x))
            {
                p[++tot].i = i; p[tot].j = j;
                if(p[tot].calc() < q[1].x) --tot;
            }
    // �ѽ��㰴x��С��������
    sort(p+1, p+tot+1);
    // Ԥ����ÿ��ѯ��
    for(int i = 1, cur = 1; i <= m; ++i)
    {
        // ÿ��ѯ��,��ѯ�ʵ�x֮ǰ�Ľ������
        while(cur <= tot && p[cur].x <= q[i].x)
        {
            a[p[cur].i].rank++;
            a[p[cur].j].rank--;
            r[a[p[cur].i].rank] = p[cur].i;
            r[a[p[cur].j].rank] = p[cur].j;
            ++cur;
        }
        // ��������k��ֱ�ߵ�y
        res[q[i].num] = a[r[k]].calc(q[i].x);
    }
    for(int i = 1; i <= m; ++i)
        put(res[i]), putchar('\n');
    return 0;
}
