class Solution {
public:
    void check(TreeNode* root, long long tar,int& count){
        if(!root) return; 
        if((long long)(root->val) == tar) count++;
        check(root->left,tar-(long long)(root->val),count);
        check(root->right,tar-(long long)(root->val),count);
    }
    int pathSum(TreeNode* root, int tar) {
        if(!root) return 0;
        int count = 0;
        check(root,(long long)(tar),count);
        count += pathSum(root->left,tar) + pathSum(root->right,tar);
        return count;
    }
};