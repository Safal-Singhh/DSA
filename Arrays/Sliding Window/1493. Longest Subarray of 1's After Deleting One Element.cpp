class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        int dlt = 0, i = 0, j = 0;
        int maxLen = INT_MIN;
        int len;
        while(j < n){
            if(nums[j] == 1) j++;
            else{
                if(dlt < k){
                    dlt++;
                    j++;
                }else{
                    len = j-i;
                    maxLen = max(maxLen, len);
                    while(nums[i] == 1) i++;
                    i++;
                    j++;
                }
            }
        }
        len = j-i;
        maxLen = max(maxLen, len);
        return maxLen-1;
    }
};