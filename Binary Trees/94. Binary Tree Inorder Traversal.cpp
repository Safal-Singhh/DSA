class Solution {
public:
    void display(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        display(root->left, ans);
        ans.push_back(root->val);
        display(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        display(root, ans);
        return ans;
    }
};