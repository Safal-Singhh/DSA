class Solution {
public:
    void display(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        display(root->left, ans);
        display(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        display(root, ans);
        return ans;
    }
};