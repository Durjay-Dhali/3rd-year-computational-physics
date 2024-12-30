#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
double f1(double x){
    return (1+cos(x))*sin(abs(2*x))/(1+abs(sin(2*x)));
}
double f2(double x){
    return 1/(1+sin(x)*sin(x));
}
double integral(double f(double), double a, double b, double c, double d, double n){
    double n0=0;
    srand(time(0));
    for(int i=0;i<n;i++){
        double x=a+(b-a)*(double)rand()/RAND_MAX;
        double y=c+(d-c)*(double)rand()/RAND_MAX;
        if(f(x)>0){
            if(y<=f(x)){
                n0++;
            }
        }
        if(f(x)<0){
            if(y>=f(x)){
                n0--;
            }
        }
    }
    return (n0/n)*(b-a)*(d-c);;
}
int main(){
    cout<<integral(f1,-M_PI,M_PI,-10,10,10000000)<<endl;
    cout<<integral(f2,0,M_PI/2.0,0,1,10000000)<<endl;
}