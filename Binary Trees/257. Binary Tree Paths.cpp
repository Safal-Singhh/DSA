class Solution {
public:
    void path(TreeNode* root, vector<string>& ans, string temp){
        if(root == NULL) return;
        string a = to_string(root->val);
        if(!root->left && !root->right){
            temp += a;
            ans.push_back(temp);
            return;
        }
        path(root->left, ans, temp+a+"->");
        path(root->right, ans, temp+a+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        path(root, ans, "");
        return ans;
    }
};