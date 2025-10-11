class Solution {
public:
    vector<int> leftMax(vector<int> h, vector<int>& left){
        int n = h.size();
        int maxx = INT_MIN;
        for(int i = 0; i < n; i++){
            maxx = max(h[i],maxx);
            left[i] = maxx;
        }
        return left;
    }
    vector<int> rightMax(vector<int> h, vector<int>& right){
        int n = h.size();
        int maxx = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            maxx = max(h[i],maxx);
            right[i] = maxx;
        }
        return right;
    }
    int trap(vector<int>& h) {
        vector<int> left(h.size());
        vector<int> right(h.size());
        leftMax(h, left);
        rightMax(h, right);
        int total = 0;
        for(int i = 0; i < h.size(); i++){
            total += min(left[i], right[i]) - h[i];
        }
        return total;
    }
};