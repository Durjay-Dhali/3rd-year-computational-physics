#include<iostream>
#include<cmath>
#include<iomanip>
#define E 0.0001
using namespace std;
double f(double x){
    return x*sin(x) + cos(x);
}
double fd(double x){
    return x*cos(x)+sin(x)-sin(x);
}
void bisection(double a, double b){
    double c;
    if(f(a)*f(b)<0){
        while (abs(a-b)>E){
            c=(a+b)/2;
            if(f(c)==0){
                break;
            }
            if(f(a)*f(c)<0){
                b=c;
            }
            else{
                a=c;
            }
        }
        cout << "bisection: " <<fixed<<setprecision(3)<< c << endl;
    } else
        cout << "Can not find a root in the given interval";
}

void nr(double x){
    double h = f(x)/fd(x);
    while (abs(h)>E){
        x = x-h;
        h = f(x)/fd(x);
    }
        cout << "NR: " <<fixed<<setprecision(3)<< x << endl;
}

void secant(double x1,double x2){
    if(f(x1)-f(x2)!=0){
    double x0;
    while(abs(x2-x1)>E){
        x0 = (x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
        x1=x2;
        x2=x0;
    }
    cout<<"secant: "<<fixed<<setprecision(3)<<x0<<endl;
    }
    else
        cout<<"error"<<endl;
}

int main()
{
    double x1 = 0, x2 = 5;
    bisection(x1, x2);
    nr(5);
    secant(2, 3);
    return 0;
}