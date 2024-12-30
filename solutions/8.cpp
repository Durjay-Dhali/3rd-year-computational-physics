#include <iostream>
#include <complex>
using namespace std;

int main() {
    complex<double> A[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin>> A[i][j];
        }

    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout<<abs(A[1][0])<<endl;
    return 0;
}

/*
Input: 
(1,2)
(3,5)
(2,3)
(4,1)

real()
imag()
arg()
abs()
*/
 