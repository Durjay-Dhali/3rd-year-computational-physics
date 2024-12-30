#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout("data.dat");
double f(double tau){
return exp(-(tau*tau));
}
double integration(double t){
    double a=0, b=8/sqrt(t),n=100;
    double h=(b-a)/n;
    double I=0, J=0;
    for(int i=1;i<n;i+=2){
        I+=f(a+i*h);
    }
    for(int i=2;i<n;i+=2){
        J+=f(a+i*h);
    }
    return (h/3.0)*(f(a)+4*I+2*J+f(b));
}
double T(double t){
    return 100*(1-(2/sqrt(M_PI))*integration(t));
}
int main(){
    for(double t=10;t<=200;t+=0.01){
        fout<<t<<" "<<T(t)<<endl;
    }
    return 0;
}
