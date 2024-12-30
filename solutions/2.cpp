#include<iostream>
using namespace std;
double f(double x){
    return x*x*x-x*x+2;
}
double df(double x){
    return 3*x*x-2*x;
}
void nr(double x){
    double h=f(x)/df(x);
    while(abs(h)>=0.000001){
        x=x-h;
        h=f(x)/df(x);
    }
    cout<<x<<endl;
}
int main(){
    nr(2);
    return 0;
}