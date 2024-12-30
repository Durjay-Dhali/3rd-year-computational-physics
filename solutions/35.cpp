#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout("data.dat");
double fact(double n){
    double result =1;
    for(int i=n;i>1;i--){
        result *=i;
    }
    return result;
}
double hermite(double x, double n){
    if(n==0) return 1;
    else if(n==1) return 2*x;
    else return 2*x*hermite(x, n-1)-2*(n-1)*hermite(x,n-2);
}
double f(double x, double n){
    double a=sqrt(pow(2,n)*fact(n)*sqrt(M_PI));
    return hermite(x,n)*exp(-x*x/2.0)/a;
}
double eigen(double z, int n, int m){
    double a=sqrt(pow(2,n)*fact(n)*sqrt(M_PI));
    double b=sqrt(pow(2,m)*fact(m)*sqrt(M_PI));
    double x = z/(1-z);
    return hermite(x,n)*hermite(x,m)*exp(-x*x)/(a*b*(1-z)*(1-z));
}
double pn(double x, double n){
    if(n==0) return 1;
    else if(n==1) return x;
    else return ((2*n-1)*x*pn(x,n-1)-(n-1)*pn(x,n-2))/n;
}
double dpn(double x, double n){
    return (n/(x*x-1))*(x*pn(x,n)-pn(x,n-1));
}
double gauss_qua(double n, double m){
    double a=-1, b=1;
    int p=20;
    double x0[p], x[p], w[p], x_prine[p], w_prime[p],c,h;
    int i;
    for(i=0;i<=p;i++){
        x0[i]=cos(M_PI*((1+i)-0.25)/(p+0.5));
        c=x0[i];
        h=pn(c,p)/dpn(c,p);
        while(abs(h)>0.00001){
            c=c-h;
            h=pn(c,p)/dpn(c,p);
        }
        x[i]=c;
        w[i]=2/((1-c*c)*(dpn(c,p)*dpn(c,p)));
    }
    for(i=0;i<p;i++){
        x_prine[i]=0.5*((a+b)+(b-a)*x[i]);
        w_prime[i]=0.5*(b-a)*w[i];
    }

    double result =0;
    for(i=0;i<p;i++){
        result += eigen(x_prine[i],n,m)*w_prime[i];
    }
    return result;
}

int main(){
    for(double x=-5;x<=5;x+=0.001){
        fout<<x<<" "<<f(x,0)<<" "<<f(x,1)<<" "<<f(x,2)<<" "<<f(x,3)<<endl;
    }
    int N,M ;
    for(N=0;N<=4;N++){
        for(M=0;M<=4;M++){
            cout<<N<<" "<<M<<" "<<gauss_qua(N,M)<<endl;
        }
        cout<<endl;
    }
}