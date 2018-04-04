#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   double PI=0,a;
   int k,b=1;
   for(k=0;k<=1000;++k)
   {
       if(k%2==0){
            a=1.0/(2*k+1);
       }
       else a=-1*(1.0/(2*k+1));
       PI+=a;
   }
   cout<<setprecision(4)<<fixed<<PI;
    return 0;
}
