#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int L=10;
int len;
char tr[L*4];
string mid,hou;

void build_tree(int hx,int hy,int mx,int my,int i)
{
    if(hx>hy||mx>my)return;
	tr[i]=hou[hy];
	if(hx==hy||mx==my)return;
	int pos=mid.find(tr[i]);
    build_tree(hx,hx+pos-mx-1,mx,pos-1,i*2);
    build_tree(hx+pos-mx,hy-1,pos+1,my,i*2+1);
}

void print_tree(int i)
{
    if(tr[i]==NULL)return;
    cout<<tr[i];
    print_tree(i*2);
    print_tree(i*2+1);
}

int main()
{
	cin>>mid>>hou;
	len=mid.length();
	build_tree(0,len-1,0,len-1,1);
	print_tree(1);
	return 0;
}
