#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int N = 1000010;
const int inf = 1e9;
const int mod = 998244353;
 
inline int read()
{
  int p=0; int f=1; char ch=getchar();
  while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
  while(ch>='0' && ch<='9'){p=p*10+ch-'0'; ch=getchar();}
  return p*f;
}

struct node{int l,r;}a[N],b[N];

bool cmp(const node &x,const node &y)
{
  if(x.l != y.l) return x.l<y.l;
  return x.r > y.r;
}
int tr[N]; int low_bit(int x){return x&(-x);}
int n;

void add(int x,int c)
{
  while(x<=2*n)
  {
    tr[x] += c;
    x+=low_bit(x);
  }
}

int qry(int x)
{
  int s = 0;
  while(x>=1)
  {
    s+=tr[x]; x-=low_bit(x);
  }return s;
}

int main()
{
  n = read();
  for(int i=1;i<=n;i++) a[i].l = read(),a[i].r = read();
  sort(a+1,a+n+1,cmp); int ans = 0;
  for(int i=1;i<=n;i++)
  {
    ans += qry(a[i].r) - qry(a[i].l);
    add(a[i].r,1);
  }bool bk = 1;
  if(ans == n-1)
  {
    int blen = 0;
    for(int i=1;i<=n;i++)
    {
      if(!blen){b[++blen] = a[i]; continue;}
      else if(b[blen].l <= a[i].l && a[i].r <= b[blen].r) continue;
      b[++blen] = a[i];
    }
    // for(int i=1;i<=blen;i++) printf("%d %d\n",b[i].l,b[i].r);
    for(int i=3;i<=blen;i++)
    {
      if(b[i].l < b[i-2].r){bk = 0; break;}
    }
  }else bk = 0;
  // printf("%d\n",ans);
  if(bk) printf("YES\n");
  else printf("NO\n");
  return 0;
}

