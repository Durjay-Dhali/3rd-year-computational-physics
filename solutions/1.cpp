#include<iostream>
#include<cmath>
using namespace std;
#define Epsilon 0.0001

double f(double x){
    return x*x*x -x*x +2;
}

void bisection(double a, double b){
    if((f(a)*f(b))>0){
        cout<<"wrong guess"<<endl;
    }
    else{
        double c;
        while(b-a>Epsilon){
            c=(a+b)/2.0;
            if(f(c)==0){
                break;
            }
            else if (f(a)*f(c)<0){
                b=c;
            }
            else
                a=c;
        }
    cout<<c<<endl;
    }
    
}

int main(){
    bisection(-500,500);
}