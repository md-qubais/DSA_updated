class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        root->left=balanceBST(root->left);
        root->right=balanceBST(root->right);
        
    }
};