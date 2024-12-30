#include<iostream>
#include<cmath>
#define E 0.0001
using namespace std;
double f(double x){
    return x*x-18;
}
double fd(double x){
    return 2*x;
}
void nr(double x){
    double h = f(x)/fd(x);
    while (abs(h)>E){
        x = x-h;
        h = f(x)/fd(x);
    }
        cout << "NR: " << x << endl;
}
int main()
{
    nr(5);
    return 0;
}