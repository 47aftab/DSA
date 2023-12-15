#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

stack <int> opstk;
stack <int> op1;
stack <int> op2;

int eval_postfix(string exp){
    for(int i = 0; i<exp.length(); i++){
        if(isdigit(exp[i])){
            opstk.push(exp[i] - '0');
        }
        else{
            int op2 = opstk.top();
            opstk.pop();
            int op1 = opstk.top();
            opstk.pop();
            
            if(exp[i] == '+'){
                opstk.push(op1 + op2);
            }
            else if(exp[i] == '-'){
                opstk.push(op1 - op2);
            }
            else if(exp[i] == '*'){
                opstk.push( op1 * op2);
            }
            else if (exp[i] == '/'){
                opstk.push(op1 / op2);
            }
            else {
                opstk.push(pow(op1,op2));
            }
        }
    }
    cout<<"The evaluation result is :"<<endl;
    return opstk.top() ;
}



int main(){
    string exp;
    cout << "Enter the postfix expression :"<<endl;
    cin>>exp;
    cout<<eval_postfix(exp);
    return 0;
}