#include<iostream>
using namespace std;
int main(){
    int A[5];
    for(int i=0;i<5;i++){
        cin>>A[i];
    }
    int m=A[0];
    for(int i=1;i<5;i++){
        if(m<A[i])
        m=A[i];
    }
    cout<<m<<endl;
    return 0;
}
