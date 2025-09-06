class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int sum = 0;
        int len = 0;
        while(j < n){
            sum += nums[j];
            while(sum >= target){
                len = j-i+1;
                ans = min(ans, len);
                sum -= nums[i++];
            }
            j++;
        }
        if(ans != INT_MAX) return ans;
        else return 0;
    }
};