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