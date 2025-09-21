class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> ans(deck.size());
        queue<int> q;
        for(int i = 0; i < deck.size(); i++){
            q.push(i);
        }
        for(int i = 0; i < deck.size(); i++){
            int idx = q.front();
            q.pop();
            ans[idx] = deck[i];
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};