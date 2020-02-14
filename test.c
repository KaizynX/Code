#include<stdio.h>

int main(){
   int i,sum=0,a,b,c,d;
   d=0;
   c=0;
   for(i=1;i<=12;i++){
    scanf("%d",&a);
    sum=c+300;
    b=(sum-a)/100*100;
    c=sum-b-a;
    d=d+b;
   if(c<0) {
       printf("%d\n", -i);
       break;
   }

   }
   if(i==13) printf("%f",d*1.2+c);

    return 0;
}
