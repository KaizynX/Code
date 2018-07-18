#include <iostream>
using namespace std;
const int MAXT=12;//it's not clearly,it's choosen the biggest within TLE
int p[6][6],kong[2][2],ans=0x7fffffff;
int change[4][2]={-1,0,0,1,0,-1,1,0};
bool judge()//AC
{
	int sumh,sums,heng,shu,flag=0;
	for(int i=1;i<=4;++i)
	{
		sumh=1;sums=1;
		heng=p[i][1];
		shu=p[1][i];
		for(int j=2;j<=4;++j)
		{
			if(p[i][j]==heng)sumh++;
			if(p[j][i]==shu)sums++;
		}
		if(sumh==4||sums==4)
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		int zu=p[1][1],yx=p[1][4],sumz=1,sumy=1;
		for(int i=2;i<=4;++i)
		{
			if(p[i][i]==zu)sumz++;
			if(p[i][5-i]==yx)sumy++;
		}
		if(sumz==4||sumy==4)
			flag=1;
	}
	return flag;
}

void bfs(int step,int last)
{
	if(judge())
	{
		ans=min(ans,step);
		return;
	}
	if(step>MAXT)return;//kill......
	for(int i=0;i<=1;++i)//two kong
	{
		int x=kong[i][0],y=kong[i][1];
		for(int j=0;j<4;++j)
		{
			int cx=x+change[j][0],cy=y+change[j][1];
			int v=p[cx][cy];
			if(cx>0&&cx<=4&&cy>0&&cy<=4&&v!=last&&v!=0)
			{
				swap(p[cx][cy],p[x][y]);
				kong[i][0]=cx;
				kong[i][1]=cy;
				
				bfs(step+1,v);
				
				swap(p[cx][cy],p[x][y]);
				kong[i][0]=x;
				kong[i][1]=y;
			}
		}
	}
}

int main()
{
	char a;
	int k=0;
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j)
		{
			cin>>a;
			if(a=='B')p[i][j]=1;
			else if(a=='W')p[i][j]=2;
			else 
			{
				kong[k][0]=i;
				kong[k][1]=j;
				k++;
			}
		}
	bfs(0,0);
	cout<<ans<<endl;
	return 0;
}
