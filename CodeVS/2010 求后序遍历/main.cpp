#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int L=300;
int len;
char tr[L*4];
string first,mid;

void build_tree(int fx,int fy,int mx,int my,int i)
{
	tr[i]=first[fx];
	if(fx>=fy||mx>=my)return;
	int pos=mid.find(tr[i]);
    build_tree(fx+1,fx+pos-mx,mx,pos-1,i*2);
    build_tree(fx+pos-mx+1,fy,pos+1,my,i*2+1);
}

void print_tree(int i)
{
    if(tr[i]==NULL)return;
    print_tree(i*2);
    print_tree(i*2+1);
    cout<<tr[i];
}

int main()
{
	cin>>first>>mid;
	len=first.length();
	build_tree(0,len-1,0,len-1,1);
	print_tree(1);
	return 0;
}
