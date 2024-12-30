#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double t){
return (2/sqrt(M_PI))*exp(-t*t);
}
double scatt_angle(double x){
    double a=0, b=x, I=0,J=0;
    int i, n=100;
    double h=(b-a)/n;
    for(i=1;i<n;i+=2){
        I+=f(a+i*h);
    }
    for(i=1;i<n;i+=2){
        J+=f(a+i*h);
    }
    return (h/3)*(f(a)+(4*I)+(2*J)+f(b));
}
int main(){
    ofstream fout("data.dat");
    for(double A=-2;A<=2;A+=0.01){
        fout<<A<<" "<<scatt_angle(A)<<endl;
    }
    return 0;
}
