#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double V(double x){
    return pow(x,4);
}
double f(double A, double x){
    return sqrt(8)/(sqrt(V(A)-V(x)));
}
double pn(double x, double n){
    if(n==0) return 1;
    else if(n==1) return x;
    else return ((2*n-1)*x*pn(x,n-1)-(n-1)*pn(x,n-2))/n;
}
double dpn(double x, double n){
    return (n/(x*x-1))*(x*pn(x,n)-pn(x,n-1));
}
double tperiod(double A){
    double a=0, b=A;
    int n=20;
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
        result += f(A,x_prine[i])*w_prime[i];
    }
    return result;
}
int main(){
    ofstream fout("data.dat");
    for(double A=0;A<=2;A+=0.01){
        fout<<A<<" "<<tperiod(A)<<endl;
    }
}