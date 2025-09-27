class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void nth(TreeNode* root, int level, int m, vector<int>& temp){
        if(root == NULL) return;
        if(m == level){
            temp.push_back(root->val);
            return;
        }
        nth(root->left, level, m+1, temp);
        nth(root->right, level, m+1, temp);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans;
        for(int i = 1; i <= n; i++){
            vector<int> temp;
            nth(root, i, 1, temp);
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};