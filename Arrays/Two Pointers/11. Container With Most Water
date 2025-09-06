class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0, rp = height.size() - 1;
        int maxWater = 0;
        while(lp < rp){
            int area = 0;
            area = (rp - lp) * min(height[lp],height[rp]);
            maxWater = max(area,maxWater);
            height[lp] < height[rp] ? lp++ : rp--;
        }
    return maxWater;
    }
};
