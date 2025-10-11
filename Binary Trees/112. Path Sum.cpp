class Solution {
public:
    bool check(TreeNode* root, int targetSum, int curr){
        if(!root) return false;
        curr += root->val;
        if(!root->left && !root->right && curr == targetSum) return true;
        return check(root->left,targetSum,curr) || check(root->right,targetSum,curr);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int curr = 0;
        return check(root,targetSum,curr);
    }
};