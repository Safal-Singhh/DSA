class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void nthLeft(TreeNode* root, int level, int m, vector<int>& temp){
        if(root == NULL) return;
        if(m == level){
            temp.push_back(root->val);
            return;
        }
        nthLeft(root->left, level, m+1, temp);
        nthLeft(root->right, level, m+1, temp);
    }
    void nthRight(TreeNode* root, int level, int m, vector<int>& temp){
        if(root == NULL) return;
        if(m == level){
            temp.push_back(root->val);
            return;
        }
        nthRight(root->right, level, m+1, temp);
        nthRight(root->left, level, m+1, temp);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans;
        for(int i = 1; i <= n; i++){
            vector<int> temp;
            if(i % 2 == 0) nthRight(root, i, 1, temp);
            else nthLeft(root, i, 1, temp);
            ans.push_back(temp);
        }
        return ans;
    }
};