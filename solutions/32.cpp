#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double lemda =1, z=3;
double fs(double u){
    return sin(M_PI*u*u/2);
}
double Fr_sin(double x){
    double a=0, b=x, n=100;
    double h=(b-a)/n;
    double I=0, J=0;
    for(int i=1;i<n;i+=2){
        I+=fs(a+i*h);
    }
    for(int i=2;i<n;i+=2){
        J+=fs(a+i*h);
    }
    return (h/3.0)*(fs(a)+4*I+2*J+fs(b));
}
double fc(double u){
    return cos(M_PI*u*u/2);
}
double Fr_cos(double x){
    double a=0, b=x, n=100;
    double h=(b-a)/n;
    double I=0, J=0;
    for(int i=1;i<n;i+=2){
        I+=fc(a+i*h);
    }
    for(int i=2;i<n;i+=2){
        J+=fc(a+i*h);
    }
    return (h/3.0)*(fc(a)+4*I+2*J+fc(b));
}
double diffraction (double x){
    double u=x*sqrt(2.0/(lemda*z));
    double a=pow((2*Fr_cos(u)+1),2);
    double b=pow((2*Fr_sin(u)+1),2);
    return (a+b)/8.0;
}
int main(){
    ofstream fout("data.dat");
    for(double x=-5;x<=5;x+=0.01){
        fout<<x<<" "<<diffraction(x)<<endl;
    }
    return 0;
}