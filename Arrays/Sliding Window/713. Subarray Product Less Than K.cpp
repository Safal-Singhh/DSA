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

// Sliding Window Approach
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int count = 0;
        int n = nums.size();
        int i = 0, j = 0;
        int prod = 1;
        while(j < n){
            prod *= nums[j];
            while(prod >= k){
                count += (j-i);
                prod /= nums[i];
                i++;
            }
            j++;
        }
        while(i < n){
            count += (j-i);
            prod /= nums[i];
            i++;
        }
        return count;
    }
};