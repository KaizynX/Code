	#include <iostream>
	using namespace std;
	const int Maxn=10009;
	int left1[Maxn],right1[Maxn];
	void Link(int a,int b)
	{
	    right1[a]=b;
	    left1[b]=a;
	}
	int main()
	{
	    int n;
	    cin>>n;
	    for(int i=1; i<=n; i++){
	        left1[i]=i-1;
	        right1[i]=(i+1)%(n+1);
	    }
	    left1[1]=n;
	    right1[n]=1;
	    int m1,m2,k=n;
	    cin>>m1>>m2;
	    for(int i=1; i<n; i++){
	        if(i%2==1){
	            for(int j=1; j<=m1; j++){
	                k=right1[k];
	            }
	            Link(left1[k],right1[k]);
	            k=right1[k];
	        }else{
	            for(int j=1; j<=m2; j++){
	                k=left1[k];
	            }
	            Link(left1[k],right1[k]);
	            k=left1[k];

	        }
	    }
	    cout<<k<<endl;
	    return 0;
	}
