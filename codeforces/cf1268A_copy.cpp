#include <bits/stdc++.h>
using namespace std;

const int maxn=int(2e5)+11;
int n,k;
char s[maxn], t[maxn];
int fa[maxn], num[maxn];
vector<int> v[maxn];
bool vis[maxn];

int _find(int k) {
	if(fa[k]==k) return k;
	else return fa[k]=_find(fa[k]);
}
void connect(int a,int b) {
	int g1=_find(a), g2=_find(b);
	if(g1==g2) return;
	fa[g2]=g1;
	return;
}
bool ok() {
	for(int i=1;i<=n;++i) if(s[i]!=t[i]) {
		if(s[i]>t[i]) return false;
		else return true;
	}
	return true;
}

int sta1[maxn], sta2[maxn], top=0;

void work() {
	scanf("%d%d%s",&n,&k,s+1);
	int i;
	for(i=1;i<=n;++i)
		fa[i]=i;
	for(i=1;i<=n-k;++i)
		connect(i,i+k);
	for(i=1;i<=n;++i) {
		fa[i]=_find(i);
		v[fa[i]].push_back(i);
	}
	for(i=1;i<=n;++i) if(!vis[i]) {
		sta1[++top]=i, sta2[top]=s[i]-'0';
		for(int j=0;j<(int)v[fa[i]].size();++j) {
			int p=v[fa[i]][j];
			vis[p]=true;
			t[p]=s[i];
		}
	}
	if(!ok()) {
		int pos=top;
		while(pos && sta2[pos]==9) {
			sta2[pos]=0;
			pos--;
		}
		sta2[pos]++;
		for(int k=pos;k<=top;++k) {
			i=sta1[k];
			for(int j=0;j<(int)v[fa[i]].size();++j) {
				int p=v[fa[i]][j];
				t[p]=sta2[k]+'0';
			}
		}
	}
	printf("%d\n%s\n",n,t+1);
	//cout<<s+1<<endl;
	return;
}

int main() {
	//freopen("input.txt","r",stdin);
	work();


	return 0;
}
