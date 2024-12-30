#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout("data.dat");
double f(double thetaM, double phi){
    double a= 1-pow(sin(thetaM/2.0),2)*pow(sin(phi),2);
    return pow(a,-0.5);
}
double inte(double thetaM){
    double a=0, b=M_PI/2, n=100;
    double h=(b-a)/n;
    double I=0, J=0;
    for(int i=1;i<n;i+=2){
        I+=f(thetaM, a+i*h);
    }
    for(int i=2;i<n;i+=2){
        J+=f(thetaM, a+i*h);
    }
    return (h/3)*(f(thetaM,a)+4*I+2*J+f(thetaM,b));
}
double T(double thetaM){
    return 4*sqrt(0.0253)*inte(thetaM);
}
int main(){
    for(double thetaM=0;thetaM<=M_PI*12;thetaM+=0.01){
        fout<<thetaM<<" "<<T(thetaM)<<endl;
    }
    return 0;
}