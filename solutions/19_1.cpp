#include<iostream>
#include<cmath>
using namespace std;
double f(double z){
    return exp(-(z*z)/((1-z)*(1-z)))/((1-z)*(1-z));
}
double pn(double x, int n){
    if (n==0) return 1;
    else if(n==1) return x;
    else return (((2*n-1)*x*pn(x,n-1))-((n-1)*pn(x,n-2)))/n;
}
double dpn(double x, int n){
    return (n/(x*x-1))*(x*pn(x,n)-pn(x,n-1));
}
void gauss(double a, double b, int n){
    if(n<=1) cout<<"can't be less than 2"<<endl;
    else{
        double x0[n], x[n], w[n], x_prine[n], w_prime[n],c,h;
        int i;
        for(i=0;i<n;i++){
            x0[i]=cos(M_PI*((i+1)-0.25)/(n+0.5));
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
            result += f(x_prine[i])*w_prime[i];
        }
        cout<<result<<endl;
    }
}

int main(){
    gauss(0,1,20);
}