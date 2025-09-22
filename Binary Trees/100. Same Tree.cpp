// My approach
class Solution {
public:
    void arr(TreeNode* root, vector<int>& vec){
        if(root == NULL){
            vec.push_back(INT_MIN);
            return;
        }
        vec.push_back(root->val);
        arr(root->left, vec);
        arr(root->right, vec);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> a;
        vector<int> b;
        arr(p,a);
        arr(q,b);
        if(a.size() != b.size()) return false;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
};

// Using recursion
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        
        if(p->val != q->val) return false;
        bool l = isSameTree(p->left, q->left);
        if(l == false) return false;
        bool r = isSameTree(p->right, q->right);
        if(r == false) return false;
        return true;
    }
};