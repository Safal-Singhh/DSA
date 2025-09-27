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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        int n = levels(root);
        for(int i = 1; i <= n; i++){
            vector<int> temp;
            nth(root, i, 1, temp);
            double avg = 0;
            int x = temp.size();
            for(int i = 0; i < x; i++){
                avg += temp[i];
            }
            avg /= x;
            ans.push_back(avg);
        }
        return ans;
    }
};