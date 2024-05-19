#include <bits/stdc++.h>
using namespace std;

float calculator(string* ops, float val, int o){
    float ans = 0;
    float logval = log(val),sinval = sin(val),expval = exp(val);
    for(int i = 0; i < o;i++){
        if(i){
            if(ops[i] == "+"){
                if(ops[i++] == "ln") ans += logval;
                else if(ops[i++] == "sin") ans += sinval;
                else if(ops[i++] == "exp") ans += expval;
            }
            else if(ops[i] == "-"){
                if(ops[i++] == "ln") ans -= logval;
                else if(ops[i++] == "sin") ans -= sinval;
                else if(ops[i++] == "exp") ans -= expval;
            }
            else if(ops[i] == "*"){
                if(ops[i++] == "ln") ans *= logval;
                else if(ops[i++] == "sin") ans *= sinval;
                else if(ops[i++] == "exp") ans *= expval;
            }
            else if(ops[i] == "/"){
                if(ops[i++] == "ln") ans /= logval;
                else if(ops[i++] == "sin") ans /= sinval;
                else if(ops[i++] == "exp") ans /= expval;
            }
            else if(ops[i] == "mod"){
                if(ops[i++] == "ln") ans += abs(logval);
                else if(ops[i++] == "sin") ans += abs(sinval);
                else if(ops[i++] == "exp") ans += abs(expval);
            }
            else if(ops[i] == "%"){
                if(ops[i++] == "ln"){ ans -= logval * ((int) ans/logval); }
                else if(ops[i++] == "sin"){ ans -= sinval * ((int) ans/sinval); }
                else if(ops[i++] == "exp"){ ans -= expval * ((int) ans/expval); }
            }
        }
        else{
            if(ops[0] == "ln") ans += logval;
            else if(ops[0] == "sin") ans += sinval;
            else if(ops[0] == "exp") ans += expval;
        }
    }
    return ans;
}
void question2(){
    int ops,vals;
    cout << "Problem 2" << endl;
    cout << "Number of operators (+,-,*,/,mod,\%,ln,sin,exp) = "; cin >> ops;
    cout << "Number of values = "; cin >> vals;
    float values[vals];
    string operators[ops];
    cout << "Input operators in order seperated by spaces: ";
    for(int i = 0; i < ops; i++){
        cin >> operators[i];
    }
    cout << "Input values in order seperated by spaces: ";
    for(int i = 0; i < vals; i++){
        cin >> values[i];
    }
    float ans[vals];
    for(int i = 0; i < vals; i++){
        ans[i] = calculator(operators, values[i], ops);
    }
    cout << "Ans in order seperated by spaces: ";
    for(int i = 0; i < vals; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    question2();
}