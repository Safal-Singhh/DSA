class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        vector<int> ans;
        queue<int> q;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i] < 0) q.push(i);
        }
        int i = 0;
        while(i < n-k+1){
            while(q.size() > 0 && q.front() < i) q.pop();
            if(q.size() == 0 || q.front() >= i+k) ans.push_back(0);
            else ans.push_back(arr[q.front()]);
            i++;
        }
        return ans;
    }
};