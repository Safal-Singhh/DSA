class Solution {
public:
    int levels(TreeNode* root){
        if(!root) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void preOrder(TreeNode* root, vector<int>& ans, int levels){
        if(!root) return;
        ans[levels] = root->val;
        preOrder(root->left,ans,levels+1);
        preOrder(root->right,ans,levels+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        preOrder(root,ans,0);
        return ans;
    }
};