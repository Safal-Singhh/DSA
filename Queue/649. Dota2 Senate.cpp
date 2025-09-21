class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> r;
        queue<int> d;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'R') r.push(i);
            else d.push(i);
        }
        while(!r.empty() && !d.empty()){
            if(r.front() < d.front()){
                d.pop();
                int x = r.front();
                r.pop();
                r.push(x + s.length());
            }
            else{
                r.pop();
                int x = d.front();
                d.pop();
                d.push(x + s.length());
            }
        }
        if(r.empty()) return "Dire";
        else return "Radiant";
    }
};