#include <bits/stdc++.h>
using namespace std;

void print_norm(int n){
    for(int i = 1; i <= n; i++){
        cout << i;
    }
}
void print_rev(int n){
    for(int i = n; i >= 1; i--){
        cout << i;
    }
}
void print_space(int n){
    for(int i = 0; i < n; i++){
         cout << " ";
    }
}
void question1 (){
    cout << "Problem 1" << endl;
    cout << "Value of n: ";
    int n,f;
    cin >> n;
    for(int i = 1; i <= n; i++){
        f = 1;
        for(int j = 1; j <= n; j++){
            if(f){
                print_norm(i); print_space(n-i);
                f = 0;
            }
            else{
                print_space(n-i); print_rev(i);
                f = 1;
            }
        }
        cout << endl;
    }
}
int main(){
    question1 ();
}