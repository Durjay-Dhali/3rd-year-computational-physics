#include<iostream>
using namespace std;
int eps(int a, int b, int c){
    return 0.5*(a-b)*(b-c)*(c-a);
}
int main(){
    int A[3][3]={1,3,5,9,8,7,2,5,8};
    int det =0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                det+= eps(i,j,k)*A[0][i]*A[1][j]*A[2][k];
            }
        }
    }
    cout<<det<<endl;
}    