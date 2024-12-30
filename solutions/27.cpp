#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
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
double diffraction (double u0, double I0){
    double a=pow((Fr_cos(u0)+0.5),2);
    double b=pow((Fr_sin(u0)+0.5),2);
    return 0.5*I0*(a+b);
}
int main(){
    ofstream fout ("data.dat");
    ofstream fout2 ("data2.dat");
    for(double x=0;x<=5;x+=0.01){
        fout<<x<<" "<<Fr_sin(x)<<" "<<Fr_cos(x)<<endl;
    }
    for(double u0=-1;u0<=4.0;u0+=0.1){
        fout2<<u0<<" "<<diffraction(u0,1)<<endl;
    }
    return 0;
}