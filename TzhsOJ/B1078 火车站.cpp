
#include <cstdio>  
using namespace std;  
  
int b[20]={0,1,1};  
  
int main()  
{  
int a,n,m,x,i,k=0;  
scanf("%d%d%d%d",&a,&n,&m,&x);  
if(x==1){printf("%d",a);return 0;}  
for(i=3;i<20;i++)b[i]=b[i-1]+b[i-2];  
if(n>4)k=(m-(b[n-3]+1)*a)/(b[n-2]-1);  
printf("%d",(b[x-1]-1)*k+(b[x-2]+1)*a);  
return 0;  
}
