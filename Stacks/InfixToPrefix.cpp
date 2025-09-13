#include <bits/stdc++.h>
using namespace std;

int pri(char ch){
    if(ch == '+' || ch == '-') return 1;
    else return 2;
}

string sol(string val1, string val2, char ch){
    string s = "";
    s.push_back(ch);
    s += val1;
    s += val2;
    return s;
}

int main(){
    string s = "(7+9)*4/8-3";
    // we need two stacks - for values and operators
    stack<string> val;
    stack<char> op;
    for(int i = 0; i < s.length(); i++){
        // check if s[i] is a digit
        if(s[i] >= 48 && s[i] <= 57){
            val.push(to_string(s[i]-48));
        }
        else{
            if(op.size() == 0) op.push(s[i]);
            else if(s[i] == '(') op.push(s[i]);
            else if(op.top() == '(') op.push(s[i]);
            else if(s[i] == ')'){
                while(op.top() != '('){
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = sol(val1,val2,ch);
                    val.push(ans);
                }
                op.pop();
            }
            else{
                while(op.size() > 0 && pri(s[i]) <= pri(op.top())){
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = sol(val1,val2,ch);
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
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = sol(val1,val2,ch);
        val.push(ans);
    }

    cout << val.top() << endl;
    return 0;
}