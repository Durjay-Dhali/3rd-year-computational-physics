#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double z){
double a=(z*z)/((1-z)*(1-z));
double b=exp(-a)/((1-z)*(1-z));
return b;}
//Legendre's Polynomial 𝑃 𝑛(𝑥)
double Pn(double x, int n){
if(n==0) return 1;
else if (n==1) return x;
else return (((2*n-1)*x*Pn(x,n-1))-((n-1)*Pn(x,n-2)))/n;
}
double d_Pn(double x,int n){
return (n/((x*x)-1))*(x*Pn(x,n)-Pn(x,n-1));}
void gauss_qua(double a,double b,int n){
if (n<=0)
cout<<"The number of sample points can not be negative or zero";
double x0[n],x[n],w[n],x_prime[n],w_prime[n],c,h;
int i;
for(i=0;i<n;i++){
x0[i]=cos((M_PI*((i+1)-0.25))/(n+0.5));
//Imprived root by Newton-Raphson method
c=x0[i];
h=Pn(c,n)/d_Pn(c,n);
while (abs(h)>=0.00000000001){
c=c-h;
h=Pn(c,n)/d_Pn(c,n);
}
x[i]=c; w[i]= (2/((1-c*c)*(d_Pn(c,n)*d_Pn(c,n))));
}
for(i=0;i<n;i++){
x_prime[i]=0.5*(((b-a)*x[i])+(b+a));
w_prime[i]=0.5*(b-a)*w[i];
}
double result=0.0;
for(i=0;i<n;i++){
result+=(w_prime[i]*f(x_prime[i]));
}
// Now the desired result is shown below
cout<<"The value of integration is: "<<result<<endl;
// If we use return type function then simply replace the cout line by return result
// return result;
}
int main(){
double a,b;
int n;
cout<<"Enter the lower limit of integration: ";
cin>>a;
cout<<"Enter the upper limit of integration: ";
cin>>b;
cout<<"Enter the order n of the legendre polynomial: ";
cin>>n;
gauss_qua(a,b,n);
// When the gauss_qua(a.b.n) is return type write the following
// cout<<"The value of integration is: "<<gauss_qua(a,b,n)<<endl;
return 0;}