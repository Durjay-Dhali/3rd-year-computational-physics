#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double A, double theta){
    double a=A*cos(theta)+1;
    double b=a*sin(theta);
    double c=A*A+2*A*cos(theta)+1;
    return (0.5*b)/(c*c);
}
double scatt_angle(double A){
    double a=0, b=M_PI, I=0,J=0;
    int i, n=100;
    double h=(b-a)/n;
    for(i=1;i<n;i+=2){
        I+=f(A,a+i*h);
    }
    for(i=1;i<n;i+=2){
        J+=f(A,a+i*h);
    }
    return (h/3)*(f(A,a)+(4*I)+(2*J)+f(A,b));
}
int main(){
    ofstream fout("data.dat");
    for(double A=2;A<=20;A+=0.1){
        fout<<A<<" "<<scatt_angle(A)<<endl;
    }
    return 0;
}