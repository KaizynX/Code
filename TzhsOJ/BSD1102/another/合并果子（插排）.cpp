#include<iostream>
#include<algorithm>
using namespace std;
int a[10001];
int cmp(int a,int b){
	return a>b;
}
int main(){
	int n,sum=0,t,j;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=n-1;i>=1;i--){
		t=a[i]+a[i-1];
		sum+=t;
		for(j=i;j>=0;j--){
			if(a[j]<t){
				a[j+1]=a[j];
			}
			else{
				a[j+1]=t;
				break;
			}
		}
		if(j<0)
			a[0]=t;
	}
	cout<<sum<<endl;
	return 0;
}
