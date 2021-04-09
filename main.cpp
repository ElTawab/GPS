#include <iostream>
#include <iomanip>
using namespace std;
#define f(x,xn,y,yn,e,tln,tsn,v) (x-xn)*(x-xn)+(y-yn)*(y-yn)-(e+tln-tsn)*(e+tln-tsn)*v*v
#define dx(x,xn) 2*(x-xn)
#define dy(y,yn) 2*(y-yn)
#define dt(e,tln,tsn,v) -2*(e+tln-tsn)*v*v
int main()
{
     cout<<std::setprecision(20);
    long const double x1=25700,y1=6800,x2=23030,y2=13300,x3=17100,y3=20375,v=300,tl1=105.10200,
    ts1=36.532944917384,tl2=105.50200,ts2=37.8525643607006,tl3=108.00200,ts3= 38.6962494012455 ;
    long double x=0,y=0,e=0;
    double det;double Dx1,Dx2,Dx3,Dy1,Dy2,Dy3,Dt1,Dt2,Dt3,D11,D12,D13,D21,D22,D23,D31,D32,D33,f1,f2,f3;
    for(int i=0;i<4;i++)
    {
        //Evaluate the vector function
        f1=f(x,x1,y,y1,e,tl1,ts1,v);
        f2=f(x,x2,y,y2,e,tl2,ts2,v);
        f3=f(x,x3,y,y3,e,tl3,ts3,v);
        //Evaluate the Jacobian matrix
        Dx1=dx(x,x1);
        Dx2=dx(x,x2);
        Dx3=dx(x,x3);
        Dy1=dy(y,y1);
        Dy2=dy(y,y2);
        Dy3=dy(y,y3);
        Dt1=dt(e,tl1,ts1,v);
        Dt2=dt(e,tl2,ts2,v);
        Dt3=dt(e,tl3,ts3,v);
        //Evaluate the inverse of Jacobian matrix
        D11=Dy2*Dt3-Dt2*Dy3;
        D12=Dt1*Dy3-Dy1*Dt3;
        D13=Dy1*Dt2-Dt1*Dy2;
        D21=Dt2*Dx3-Dx2*Dt3;
        D22=Dt3*Dx1-Dx3*Dt1;
        D23=Dt1*Dx2-Dx1*Dt2;
        D31=Dx2*Dy3-Dy2*Dx3;
        D32=Dx3*Dy1-Dy3*Dx1;
        D33=Dx1*Dy2-Dy1*Dx2;
        det=Dx1*D11+Dy1*D21+Dt1*D31;
        //update the values of the variables
        x=x-1/det*(D11*f1+D12*f2+D13*f3);
        y=y-1/det*(D21*f1+D22*f2+D23*f3);
        e=e-1/det*(D31*f1+D32*f2+D33*f3);
        //print the result after every iteration
        cout<<"After the "<<i+1<<" iteration\n";
        cout<<"x= "<<x<<" \ny= "<<y<<" \ne= "<<e<<endl;
        cout<<endl<<endl;
        //repeat

    }

}
