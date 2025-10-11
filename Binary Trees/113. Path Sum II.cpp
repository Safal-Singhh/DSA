class Solution {
public:
    void check(TreeNode* root, int targetSum, int curr, vector<int> arr, vector<vector<int>>& ans){
        if(!root) return;
        curr += root->val;
        arr.push_back(root->val);
        if(!root->left && !root->right && curr == targetSum){
            ans.push_back(arr);
            return;
        }
        check(root->left,targetSum,curr,arr,ans);
        check(root->right,targetSum,curr,arr,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int curr = 0;
        vector<int> arr;
        vector<vector<int>> ans;
        check(root, targetSum, curr, arr, ans);
        return ans;
    }
};