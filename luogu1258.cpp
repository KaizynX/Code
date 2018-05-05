#include <cstdio>
#include <iostream>

using namespace std;

double S, Vm, Vc;

int main()
{
	cin >> S >> Vm >> Vc;
	double t1,t2,t3;
 	t1 = (1-Vc/Vm)*S / (Vm + Vc/Vm*Vc + (Vm - Vc/Vm*Vm)*(Vc-Vm)/(Vc+Vm));
	t2 = (Vc - Vm) * t1 / (Vc + Vm);
    t3 = (S - Vc * t1 - Vm * (Vc - Vm) * t1 / (Vc + Vm)) / Vm;
	printf("%.6f\n",t1 + t2 + t3);
	return 0;
}
/*
 *  t1 : car take A, and B walk
 *  t2 : car back to B, A&B walk
 *  t3 : car take B, and A walk, they reach at end at same time
 *
 *  A : Vc * t1 + Vm * t2 + Vm * t3 = S
 *  B : Vm * t1 + Vm * t2 + Vc * t3 = S
 *
 *  t2 = (Vc - Vm) * t1 / (Vc + Vm)
 *
 *  from A we could get :
 *  t3 = (S - Vc * t1 - Vm * t2) / Vm
 *     = (S - Vc * t1 - Vm * (Vc - Vm) * t1 / (Vc + Vm)) / Vm
 *
 *  take them to B we could get :
 *  S = Vm*t1+Vm*(Vc-Vm)/(Vc+Vm)*t1+Vc*(S-(Vc-Vm*(Vc-Vm)/(Vc+Vm))*t1)/Vm
 *  S = Vm*t1+Vm*(Vc-Vm)/(Vc+Vm)*t1+Vc*S/Vm-Vc*(Vc-Vm*(Vc-Vm)/(Vc+Vm))/Vm*t1
 *  S = (Vm + Vm*(Vc-Vm)/(Vc+Vm) + Vc/Vm*(Vc-Vm*(Vc-Vm)/(Vc+Vm))) * t1 + Vc*S/Vm
 *	(1-Vc/Vm)*S = (Vm + Vc/Vm*Vc + (Vm - Vc/Vm*Vm)*(Vc-Vm)/(Vc+Vm)) * t1
 */
