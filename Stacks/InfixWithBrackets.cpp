#include <bits/stdc++.h>
using namespace std;

int pri(char ch){
    if(ch == '+' || ch == '-') return 1;
    else return 2;
}

int sol(int val1, int val2, int ch){
    if(ch == '+') return val1+val2;
    else if(ch == '-') return val1-val2;
    else if(ch == '*') return val1*val2;
    else return val1/val2;
}

int main(){
    string s = "(2+6)*4/8-3";
    // we need two stacks - for values and operators
    stack<int> val;
    stack<char> op;
    for(int i = 0; i < s.length(); i++){
        // check if s[i] is a digit
        if(s[i] >= 48 && s[i] <= 57){
            val.push(s[i]-48);
        }
        else{
            if(op.size() == 0) op.push(s[i]);
            else if(s[i] == '(') op.push(s[i]);
            else if(op.top() == '(') op.push(s[i]);
            else if(s[i] == ')'){
                while(op.top() != '('){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = sol(val1,val2,ch);
                    val.push(ans);
                }
                op.pop();
            }
            else{
                while(op.size() > 0 && pri(s[i]) <= pri(op.top())){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = sol(val1,val2,ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    // the operator stack can have values
    // so make it empty
    while(op.size() > 0){
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = sol(val1,val2,ch);
        val.push(ans);
    }

    cout << val.top() << endl;
    cout << (2+6)*4/8-3 << endl;
    return 0;
}