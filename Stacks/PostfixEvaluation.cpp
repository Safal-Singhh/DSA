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
    string s = "79+4*8/3-";
    stack<int> val;
    for(int i = 0; i < s.length(); i++){
        // check if s[i] is a digit
        if(s[i] >= 48 && s[i] <= 57){
            val.push(s[i]-48);
        }
        else{
            char ch = s[i];
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            int ans = sol(val1,val2,ch);
            val.push(ans);
        }    
    }

    cout << val.top() << endl;
    return 0;
}