// Brute Force Approach
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> res;
//         for(int i = 0; i <= n-k; i++){
//             int maximum = INT_MIN;
//             for(int j = i; j < k+i; j++){
//                 maximum = max(maximum, nums[j]);
//             }
//             res.push_back(maximum);
//         }
//         return res;
//     }
// }; 

// Optimal Approach using Stacks
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        stack<int> st;
        vector<int> ngi(n);
        ngi[n-1] = n;
        st.push(n-1);
        for(int i = n-2; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()) ngi[i] = n;
            else ngi[i] = st.top();
            st.push(i);
        }
        
        for(int i = 0; i <= n-k; i++){
            int mx = nums[i];
            int j = i;
            while(j < k+i){
                mx = nums[j];
                j = ngi[j];
            }
            res.push_back(mx);
        }
        return res;
    }
};