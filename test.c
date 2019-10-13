#include <stdio.h>
#include <math.h>

int main()
{

    double a, b, c, d;
    scanf("%lf %lf %lf", &a, &b, &c);
    d = b*b-4*a*c;
if(d>=0)
        if(d>0)
          {printf("%.2f\n",(-b+pow(d,0.5))/2/a);
           printf("%.2f",(-b-pow(d,0.5))/2/a);
		  	}
        else
            {if(a==0&&b==0&&c==0)
            printf("Zero Equation");
            if(a==0&&b==0&&c!=0)
            printf("Not An Equation");
            else
            printf("%.2f\n",-b/2/a);
			}
    else
           {printf("%.2f%+.2fi\n",-b/2*a,pow(-d,0.5)/2/a);
            printf("%.2f%+.2fi\n",-b/2*a,pow(-d,0.5)/2/a);
        }
    return 0;
}
