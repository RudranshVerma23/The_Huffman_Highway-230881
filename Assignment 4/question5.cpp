#include<bits/stdc++.h>
using namespace std;

string rotate(string s){
    string temp = s;
    temp[0] = s[s.size()-1];
    for(int i=1;i<s.size();i++){
        temp[i] = s[i-1];
    }
    return temp;
}
int main(){
    string max;
    cout << "Input  string: "; cin>>max;
    int len = max.size();
    string temp,curr=max;
    for(int j=0;j<len-1;j++){
        temp = rotate(curr);
        for(int i=0; i<len;i++){
            if(temp[i] < max[i]){
                max = temp; break;
            }
            else if(temp[i] > max[i]){break;}
        }
        curr = temp;
    }
    cout << "Lexicographically smallest rotation of above string is: " << max;
}