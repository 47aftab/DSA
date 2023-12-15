#include <iostream>
#include <string>
#include <stack>
using namespace std;
int prec(char c){
        if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if ( c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
};

string infix_to_postfix(string s){
    stack <char> opstk;
    string res;
    // (s[i] >= 'a' && s[i] <= 'z') || ( s[i] >= 'A' && s[i] <= 'Z')
    for(int i=0; i<s.length(); i++){

        if(isalnum(s[i])){
            res += s[i];
        }
        else if(s[i] == '('){
            opstk.push(s[i]);
        }
        else if( s[i] == ')'){
            while(!opstk.empty() && opstk.top() != '('){
                res += opstk.top();
                opstk.pop();
            }
            if(!opstk.empty()){
                opstk.pop();
            }
        }
        else{
            while(!opstk.empty() && prec(opstk.top())>prec(s[i])){
                res += opstk.top();
                opstk.pop();
            }
            opstk.push(s[i]);
        }

    }
    while(!opstk.empty()){
        res+=opstk.top();
        opstk.pop();
    }

};
