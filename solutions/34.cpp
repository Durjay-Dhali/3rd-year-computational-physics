#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double V=pow(10,-3);
double rho = 6.022e28;
double KB=1.38e-23;
double theta_D=428;
double f(double x, double T){
    double a = 9*V*rho*KB*pow(T/theta_D,3);
    double b = pow(x,4)*exp(x)/(pow(exp(x)-1,2));
    return a*b;
}
double pn(double x, double n){
    if(n==0) return 1;
    else if(n==1) return x;
    else return ((2*n-1)*x*pn(x,n-1)-(n-1)*pn(x,n-2))/n;
}
double dpn(double x, double n){
    return (n/(x*x-1))*(x*pn(x,n)-pn(x,n-1));
}
double sp_heat(double T){
    double a=0, b=theta_D/T;
    int n=5;
    double x0[n], x[n], w[n], x_prine[n], w_prime[n],c,h;
    int i;
    for(i=0;i<=n;i++){
        x0[i]=cos(M_PI*((1+i)-0.25)/(n+0.5));
        c=x0[i];
        h=pn(c,n)/dpn(c,n);
        while(abs(h)>0.00001){
            c=c-h;
            h=pn(c,n)/dpn(c,n);
        }
        x[i]=c;
        w[i]=2/((1-c*c)*(dpn(c,n)*dpn(c,n)));
    }
    for(i=0;i<n;i++){
        x_prine[i]=0.5*((a+b)+(b-a)*x[i]);
        w_prime[i]=0.5*(b-a)*w[i];
    }

    double result =0;
    for(i=0;i<n;i++){
        result += f(x_prine[i],T)*w_prime[i];
    }
    return result;
}
int main(){
    ofstream fout("data.dat");
    for(double T=5;T<=500;T+=1){
        fout<<T<<" "<<sp_heat(T)<<endl;
    }
}