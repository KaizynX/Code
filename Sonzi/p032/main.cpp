#include <iostream>

using namespace std;

int main()
{
    int s,s100=0,s90=0,s80=0,s70=0,s60=0,s0=0;
    cin>>s;
    int a[s];
    /*for(int i=1;i<=s;++i){
        a[i]=0;
    }*/
    for(int i=1;i<=s;++i){
        cin>>a[i];
        if(a[i]==100)s100++;
        if(a[i]>=90 && a[i]<100)s90++;
        if(a[i]>=80 && a[i]<90)s80++;
        if(a[i]>=70 && a[i]<80)s70++;
        if(a[i]>=60 && a[i]<70)s60++;
        if(a[i]<60)s0++;
    }
    cout<<s100<<endl<<s90<<endl<<s80<<endl<<s70<<endl<<s60<<endl<<s0;
    return 0;
}
