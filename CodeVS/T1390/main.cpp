#include <iostream>
#include <cstring>
using namespace std;

string jinzhi(int b,int i2)
{
    string a;
    while(i2)
    {
        if(i2%b==0)
        {
            i2/=b;
            a+='0';
        }
        else
        {
            int jin=i2%b;
            if(jin<10)a+='0'+jin;
            else
            {
                if(jin==10)a+='A';
                else if(jin==11)a+='B';
                else if(jin==12)a+='C';
                else if(jin==13)a+='D';
                else if(jin==14)a+='E';
                else if(jin==15)a+='F';
                else if(jin==16)a+='G';
                else if(jin==17)a+='H';
                else if(jin==18)a+='I';
                else if(jin==19)a+='J';
            }
            i2=(i2-jin)/b;
        }
    }
    return a;
}

string fanjinzhi(string a)
{
    string m;
    int l=a.length();
    for(int i=l-1;i>=0;i--)m+=a[i];
    return m;
}

int main()
{
    int b;
    string n;
    cin>>b;
    for(int i=1;i<=300;i++)
    {
        n=jinzhi(b,i*i);
        if(fanjinzhi(n)==n)
        {
            string out=jinzhi(b,i);
            cout<<fanjinzhi(out)<<" "<<n<<endl;
        }
    }
    return 0;
}
