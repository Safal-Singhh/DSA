// Brute Force Approach
// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int count = 0;
//         for(int i = 0; i < nums.size(); i++){
//             int a = 1;
//             double pro = 1;
//             for(int j = i; j < nums.size(); j++){
//                 pro *= nums[j];
//                 if(pro < k) count++;
//             }
//         }
//         return count;
//     }
// };