#include<bits/stdc++.h>
using namespace std;

class Matrix{
    public:
    int r,c; vector<vector<int>> array;
    Matrix(int r, int c) : r(r), c(c), array(r, vector<int>(c)) {}
    void input(){
        cout << "Input values row-wise: " << endl;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> array[i][j];
            }
        }
    }
    void print(){
        cout << "Matix: " << endl;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
    friend Matrix operator * (Matrix const& matA, Matrix const& matB);
};
Matrix operator *(Matrix const& matA, Matrix const& matB){
    int r1,r2,c1,c2;
    r1 = matA.r; r2 = matB.r;
    c1 = matA.c; c2 = matB.c;
    if(r2 != c1) throw invalid_argument("Invalid dimensions for operation.");
    Matrix temp(r1,c2);
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            temp.array[i][j] = 0;
            for(int t = 0; t < r2; t++){
                temp.array[i][j] += (matA.array[i][t])*(matB.array[t][j]);
            }
        }
    }
    return temp;
}
int main(){
    int r,c; cin >> r >> c;
    Matrix matA(r,c), matB(c+1,r), matC(r,r);
    matA.input(); matB.input();
    matC = matA * matB;
    matA.print(); matB.print(); matC.print();
}