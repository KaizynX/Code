#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=sgn;
}
template <typename T>
void out(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
struct node
{
	int x;
	char c;
}x[6];
bool cmp(node a,node b)
{
	return a.x < b.x;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	string a,b,c;
	cin >> a >> b >> c;
	x[1].x = a[0] - '0';
	x[1].c = a[1];
	x[2].x = b[0] - '0';
	x[2].c = b[1];
	x[3].x = c[0] - '0';
	x[3].c = c[1];
	sort(x+1,x+4);
	for(int i =1;i <= 3;i++){
		int tmp = 2;
		for(int j =1;j <= 3;j++){
			if(i != j)
			{
				if(x[i].x == x[j].x && x[i].c == x[j].c)
                   tmp--;
			}
		}
		int _ = 2;
		map<int,int> mp;
	    if(x[i].x == 1)
	    {
           for(int j =1;j <= 3;j++){
           	if(i != j && !mp[x[j].x] && x[i].c == x[j].c)
           	{
           		if(x[j].x == 2 || x[j].x == 3)
           		{
           			_--;
           			mp[x[j].x]++;
           		}
           	}
           }
	    }
	    else if(x[i].x == 2)
	    {
           for(int j =1;j <= 3;j++){
           	if(i != j && !mp[x[j].x] && x[i].c == x[j].c)
           	{
                if(x[j].x == 3 || x[j].x == 1 || x[j].x == 4)
                {
                	_--;
                	mp[x[j].x]++;
                }
           	}
           }
	    }
	    else if(x[i].x >= 3 && x[i].x <= 7)
	    {
            for(int j =1;j <= 3;j++){
               if(i !=j && !mp[x[j].x] && x[j].c == x[i].c)
               {
               	   if((x[j].x == x[i].x - 2) || (x[j].x == x[i].x - 1) || (x[j].x == x[i].x + 1) || (x[j].x == x[i].x + 2))
               	   {
               	   	  _ --;
               	   	  mp[x[j].x]++;
               	   }
               }
            }
	    }
	    else if(x[i].x == 8)
	    {
            for(int j =1;j <= 3;j++){
           	if(i != j && !mp[x[j].x] && x[i].c == x[j].c)
           	{
                if(x[j].x == 6 || x[j].x == 7 || x[j].x == 9)
                {
                	_--;
                	mp[x[j].x]++;
                }
           	}
           }
	    }
	    else {
            for(int j =1;j <= 3;j++){
           	if(i != j && !mp[x[j].x] && x[i].c == x[j].c)
           	{
           		if(x[j].x == 7 || x[j].x == 8)
           		{
           			_--;
           			mp[x[j].x]++;
           		}
           	}
           }
	    } 
	    ans = min (ans,_);
	} 
	cout << ans << endl;
	return 0 ;
}
